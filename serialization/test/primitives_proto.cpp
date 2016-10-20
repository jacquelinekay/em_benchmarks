// compile a binary for benchmarking the size of messages
// message_filename: path to the header defining the message
// (bit of a hack)

#include "serialize_wrapper.hpp"
#include "fill_test_messages.hpp"
#include ""

using namespace em_benchmarks;

int main(int argc, char** argv) {
  std::stringstream sstr;
  using MessageName = ;
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
