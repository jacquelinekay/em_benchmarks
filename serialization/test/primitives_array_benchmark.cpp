#include "serialize_wrapper.hpp"
#include "fill_test_message.hpp"
#include <array>
#include "idl/primitives_array.hpp"

using namespace em_benchmarks;

int main(int argc, char** argv) {
  std::stringstream sstr;
  using MessageName = msg::PrimitivesArray<8>;
  {
    MessageName msg;
    fill_test_message(msg);
    serialize_wrapper::serialize(msg, sstr);
  }

  {
    MessageName msg;
    serialize_wrapper::deserialize(sstr, msg);
  }

  return 0;
}
