// test basic serialization/deserialization functionality
// target destination: POSIX/desktop
#include <boost/core/lightweight_test.hpp>
#include <boost/hana/equal.hpp>
#include <array>

#include "serialize_wrapper.hpp"
#include "fill_test_message.hpp"

using namespace em_benchmarks;

template<typename T,
  typename std::enable_if<boost::hana::Struct<T>::value>::type * = nullptr>
void validate_message(T &in, T &out) {
  std::stringstream sstr;
  serialize_wrapper::serialize(in, sstr);

  serialize_wrapper::deserialize(sstr, out);
  BOOST_TEST_EQ(boost::hana::equal(in, out), true);
}

int main(int argc, char** argv) {
  msg::Primitives prim_in;
  fill_test_message(prim_in);
  msg::Primitives prim_out;
  validate_message(prim_in, prim_out);

  msg::PrimitivesArray<8> prims_array_in;
  fill_test_message(prims_array_in);
  msg::PrimitivesArray<8> prims_array_out;
  std::stringstream sstr;
  serialize_wrapper::serialize(prims_array_in, sstr);

  serialize_wrapper::deserialize(sstr, prims_array_out);
  validate_message(prims_array_in, prims_array_out);

  msg::PrimitiveArrays<8> prim_arrays_in;
  fill_test_message(prim_arrays_in);
  msg::PrimitiveArrays<8> prim_arrays_out;
  validate_message(prim_arrays_in, prim_arrays_out);

  /*
  Nested<8, 8, 0> nested_in;
  fill_test_message(nested_in.primitives);
  fill_test_message(nested_in.primitives_array);
  fill_test_message(nested_in.primitive_arrays);

  Nested<8, 8, 0> nested_out;
  validate_message(nested_in, nested_out);
  */

  return boost::report_errors();
}
