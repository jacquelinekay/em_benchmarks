#ifndef SERIALIZATION__IDL__PRIMITIVE_ARRAYS_HPP_
#define SERIALIZATION__IDL__PRIMITIVE_ARRAYS_HPP_

#include <boost/hana/define_struct.hpp>
#include <cereal/types/array.hpp>

#include <string>

namespace em_benchmarks {
namespace msg {

// Struct of Arrays
template<size_t ArraySize>
struct PrimitiveArrays {
  BOOST_HANA_DEFINE_STRUCT(PrimitiveArrays,
    (std::array<int32_t, ArraySize>, int32_value),
    (std::array<uint32_t, ArraySize>, uint32_value),
    (std::array<int64_t, ArraySize>, int64_value),
    (std::array<uint64_t, ArraySize>, uint64_value),
    (std::array<double, ArraySize>, double_value),
    (std::array<float, ArraySize>, float_value),
    (std::array<bool, ArraySize>, bool_value),
    (std::array<std::string, ArraySize>, string_value)
  );
};

}
}

#endif  //  SERIALIZATION__IDL__PRIMITIVE_ARRAYS_HPP_
