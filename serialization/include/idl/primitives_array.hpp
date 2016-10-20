#ifndef SERIALIZATION__IDL__PRIMITIVES_ARRAY_HPP_
#define SERIALIZATION__IDL__PRIMITIVES_ARRAY_HPP_

#include <array>
#include <boost/hana/define_struct.hpp>
#include <cereal/types/array.hpp>

#include "primitives.hpp"

namespace em_benchmarks {
namespace msg {

// Array of Structs
template<size_t ArraySize>
struct PrimitivesArray {
  BOOST_HANA_DEFINE_STRUCT(PrimitivesArray,
    (std::array<Primitives, ArraySize>, array_value)
  );
};

}
}

#endif  // SERIALIZATION__IDL__PRIMITIVES_ARRAY_HPP_

