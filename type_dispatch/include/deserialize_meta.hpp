#ifndef TYPE_DISPATCH__DESERIALIZE_VARIANT_HPP_
#define TYPE_DISPATCH__DESERIALIZE_VARIANT_HPP_

#include <tuple>

#include <boost/hana/flatten.hpp>
#include <boost/hana/for_each.hpp>
#include <boost/hana/insert.hpp>
#include <boost/hana/map.hpp>
#include <boost/hana/pair.hpp>
#include <boost/hana/tuple.hpp>
#include <boost/hana/type.hpp>

#include "refl_serializer.hpp"

#include "idl/ack.hpp"
#include "idl/source.hpp"

namespace hana = boost::hana;

namespace em_benchmarks {

template <typename Archive, typename CallbackMap, typename TypeSeq>
void deserialize_with_callback(Archive &archive,
                               const CallbackMap &callback_map,
                               const TypeSeq &type_sequence) {
  // Extract the keys of the callback map
  // Map of user data string ids to index into variant
  Header header;
  archive(header);

  // Linear search through the type-sequence (could be faster with lexicographic sort)
  hana::for_each(type_sequence,
                 [&archive, &header, &callback_map, &type_sequence](auto &&x) {
                   if (hana::first(x) == header.type_id) {
                     auto type_tag = hana::second(x);
                     using T = typename decltype(type_tag)::type;
                     T t;
                     archive(t);
                     callback_map[hana::type_c<T>](t);
                   }
                 });
}

template <typename CallbackMap, typename TypeSeq> struct CallbackRegistrar {
  const CallbackMap callback_map;
  const TypeSeq type_sequence;

  template <typename T, typename Callback>
  auto register_callback(const std::string &id, Callback &&callback) const {
    auto next_callback_map =
        hana::insert(callback_map, hana::make_pair(hana::type_c<T>, callback));
    auto next_tuple_sequence = hana::insert(
        type_sequence, hana::int_c<0>, hana::make_pair(id, hana::type_c<T>));
    return make_callback_registrar(next_callback_map, next_tuple_sequence);
  }

  auto unpack() const { return std::make_tuple(callback_map, type_sequence); }
};

static auto make_callback_registrar() {
  auto m = hana::make_map();
  auto t = hana::make_tuple();
  return CallbackRegistrar<decltype(m), decltype(t)>{m, t};
}

template <typename M, typename S>
static auto make_callback_registrar(const M &m, const S &s) {
  return CallbackRegistrar<M, S>{m, s};
}
}

#endif // TYPE_DISPATCH__DESERIALIZE_VARIANT_HPP_
