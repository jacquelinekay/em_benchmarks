#include "idl/ack.hpp"
#include "idl/foo.hpp"
#include "idl/source.hpp"
#include "deserialize_casting.hpp"

#include "serialize_wrapper.hpp"

using namespace em_benchmarks;

void ack_callback(void * args) {
  // User callbacks have to provide the message type and
  // handle deserialization
  auto archive = static_cast<cereal::BinaryOutputArchive *>(args);
  if (!archive) {
    return;
  }
  Ack ack;
  (*archive)(ack);
  volatile Ack b = ack;
}

void source_callback(void * args) {
  auto archive = static_cast<cereal::BinaryOutputArchive *>(args);
  if (!archive) {
    return;
  }
  Source src;
  (*archive)(src);
  volatile Source b = src;
}

void foo_callback(void * args) {
  // User callbacks have to provide the message type and
  // handle deserialization
  auto archive = static_cast<cereal::BinaryOutputArchive *>(args);
  if (!archive) {
    return;
  }
  Foo src;
  (*archive)(src);
  volatile Foo b = src;
}

int main(int argc, char** argv) {
  std::stringstream s;
  cereal::BinaryOutputArchive a(s);
  CallbackMap callback_map;

  register_callback("ack", ack_callback, callback_map);
  register_callback("source", source_callback, callback_map);
  register_callback("foo", foo_callback, callback_map);

  Ack ack;
  serialize_wrapper::serialize(ack, s);

  deserialize_with_callback(a, callback_map);

  return 0;
}
