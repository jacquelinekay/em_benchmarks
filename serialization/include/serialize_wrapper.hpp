#ifndef SERIALIZATION__SERIALIZE_WRAPPER
#define SERIALIZATION__SERIALIZE_WRAPPER

#include <refl_serializer.hpp>

namespace serialize_wrapper
{

  template<typename T>
  void serialize(T const& src, std::stringstream& dst) {
    if constexpr(boost::hana::Struct<T>::value) {
      cereal::BinaryOutputArchive archive(dst);
      reflection_serialization::serialize(src, archive);
    } else {
      src.SerializeToOstream(&dst);
    }
  }

  template<typename T>
  void deserialize(std::stringstream& src, T &dst) {
    if constexpr(boost::hana::Struct<T>::value) {
      cereal::BinaryInputArchive archive(src);
      reflection_serialization::deserialize(archive, dst);
    } else {
      dst.ParseFromIstream(&src);
    }
  }

}

#endif  // SERIALIZATION__SERIALIZE_WRAPPER.hpp
