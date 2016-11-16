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

template <typename ...Callbacks>
auto register_callbacks(Callbacks const& ...callbacks) {
  auto map = hana::make_map(
    hana::make_pair(hana::type<typename Callbacks::type>{}, callbacks.function)...
  );
  auto tuple = hana::make_tuple(
    hana::make_pair(callbacks.id, hana::type<typename Callbacks::type>{})...
  );
  return std::make_tuple(std::move(map), std::move(tuple));
}

template <typename T, typename F>
struct Callback {
  std::string id;
  F function;
  using type = T;
};

template <typename T, typename F>
auto callback(const std::string &id, F&& callback) {
  return Callback<T, std::decay_t<F>>{id, std::forward<F>(callback)};
}
}

#endif // TYPE_DISPATCH__DESERIALIZE_VARIANT_HPP_
