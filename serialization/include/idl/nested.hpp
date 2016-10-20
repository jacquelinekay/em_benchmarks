#ifndef SERIALIZATION__IDL__NESTED_HPP_
#define SERIALIZATION__IDL__NESTED_HPP_

#include <boost/hana/define_struct.hpp>

#include "primitives.hpp"
#include "primitives_array.hpp"
#include "primitive_arrays.hpp"

namespace em_benchmarks {
namespace msg {

template<size_t NPrimitivesArray, size_t NPrimitiveArrays, size_t NestDepth>
struct Nested;

template<size_t NPrimitivesArray, size_t NPrimitiveArrays, size_t NestDepth>
struct Nested {
  BOOST_HANA_DEFINE_STRUCT(Nested,
    (Nested<NPrimitivesArray, NPrimitiveArrays, NestDepth - 1>, nested),
    (Primitives, primitives),
    (PrimitivesArray<NPrimitivesArray>, primitives_array),
    (PrimitiveArrays<NPrimitiveArrays>, primitive_arrays)
  );
};

template<size_t NPrimitivesArray, size_t NPrimitiveArrays>
struct Nested<NPrimitivesArray, NPrimitiveArrays, 0> {
  BOOST_HANA_DEFINE_STRUCT(Nested,
    (Primitives, primitives),
    (PrimitivesArray<NPrimitivesArray>, primitives_array),
    (PrimitiveArrays<NPrimitiveArrays>, primitive_arrays)
  );
};

}
}

#endif  //  SERIALIZATION__IDL__NESTED_HPP_
