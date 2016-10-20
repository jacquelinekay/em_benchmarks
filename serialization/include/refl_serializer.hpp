#ifndef SERIALIZATION__REFL_SERIALIZER
#define SERIALIZATION__REFL_SERIALIZER

#include <cereal/archives/binary.hpp>
#include <boost/hana/at_key.hpp>
#include <boost/hana/concept/struct.hpp>
#include <boost/hana/for_each.hpp>

// Tell Cereal how to iterate over fields of a Struct
namespace cereal {
  template<typename Archive, typename T,
    typename std::enable_if<boost::hana::Struct<T>::value>::type * = nullptr>
  void save(Archive& archive, T const& src) {
    boost::hana::for_each(src,
      [&archive](const auto& x) {
        archive(boost::hana::second(x));
      }
    );
  }

  template<typename Archive, typename T,
    typename std::enable_if<boost::hana::Struct<T>::value>::type * = nullptr>
  void load(Archive& archive, T& src) {
    boost::hana::for_each(src,
      [&archive, &src](auto&& x) {
        archive(boost::hana::second(x));
        boost::hana::at_key(src, boost::hana::first(x)) = boost::hana::second(x);
      }
    );
  }
}

namespace reflection_serialization {

template<typename T>
void serialize(T& src, cereal::BinaryOutputArchive& archive) {
  static_assert(
    boost::hana::Struct<T>::value,
    "serialize called on an object that is not a Hana Struct.");
  archive(src);
}

template<typename T>
void deserialize(cereal::BinaryInputArchive& archive, T& dst) {
  static_assert(
    boost::hana::Struct<T>::value,
    "serialize called on an object that is not a Hana Struct.");
  archive(dst);
}

};

#endif  // SERIALIZATION__REFL_SERIALIZER
