#ifndef FILL_TEST_MESSAGES__HPP_
#define FILL_TEST_MESSAGES__HPP_

#include "idl/primitives.hpp"
#include "idl/primitive_arrays.hpp"
#include "idl/primitives_array.hpp"
#include "idl/nested.hpp"

namespace em_benchmarks {

void fill_test_message(msg::Primitives &in) {
  in = {-1, 2, -3, 4, 5.5, 6.6, true, "hello world"};
}

template<size_t Size>
void fill_test_message(msg::PrimitivesArray<Size> &in) {
  for (auto &x : in.array_value) {
    fill_test_message(x);
  }
}

template<size_t Size>
void fill_test_message(msg::PrimitiveArrays<Size> &in) {
  for (int i = 0; i < 8; ++i) {
    in.int32_value[i] = -i;
    in.uint32_value[i] = i;
    in.int64_value[i] = -2 * i;
    in.uint64_value[i] = 2 * i;
    in.float_value[i] = i + 0.5;
    in.double_value[i] = i + 0.5;
    in.bool_value[i] = true;
    in.string_value[i] = "hello world " + std::to_string(i);
  }
}

template<size_t N, size_t M, size_t D>
void fill_test_message(msg::Nested<N, M, D> &n) {
  boost::hana::for_each(n, [](auto &&x) {
      fill_test_message(x);
    }
  );
}

}

#endif  // FILL_TEST_MESSAGES__HPP_
