#include "serialize_wrapper.hpp"
#include "fill_test_message.hpp"
#include <array>
#include "primitive_arrays.pb.h"

using namespace em_benchmarks;

int main(int argc, char** argv) {
  std::stringstream sstr;
  using MessageName = PrimitiveArrays;
  {
    MessageName msg;
    serialize_wrapper::serialize(msg, sstr);
  }

  {
    MessageName msg;
    serialize_wrapper::deserialize(sstr, msg);
  }

  return 0;
}
