#include <boost/core/lightweight_test.hpp>
#include "serialize_wrapper.hpp"

#include "primitives.pb.h"
#include "primitive_arrays.pb.h"
#include "primitives_array.pb.h"

using namespace em_benchmarks;

template<typename T>
void validate_message(T &in, T &out) {
  std::stringstream sstr;
  serialize_wrapper::serialize(in, sstr);
  serialize_wrapper::deserialize(sstr, out);
}

int main(int argc, char** argv) {
  std::stringstream sstr;

  Primitives prim_in;
  // fill_test_message(prim_in);
  Primitives prim_out;
  validate_message(prim_in, prim_out);

  PrimitivesArray prims_array_in;
  // TODO resize vectory
  // fill_test_message(prims_array_in);
  PrimitivesArray prims_array_out;
  serialize_wrapper::serialize(prims_array_in, sstr);

  serialize_wrapper::deserialize(sstr, prims_array_out);
  validate_message(prims_array_in, prims_array_out);

  PrimitiveArrays prim_arrays_in;
  // fill_test_message(prim_arrays_in);
  PrimitiveArrays prim_arrays_out;
  validate_message(prim_arrays_in, prim_arrays_out);

  return 0;
}
