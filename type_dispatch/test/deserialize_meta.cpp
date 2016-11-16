#include "idl/ack.hpp"
#include "idl/foo.hpp"
#include "idl/bar.hpp"
#include "idl/source.hpp"
#include "deserialize_meta.hpp"

#include "serialize_wrapper.hpp"

using namespace em_benchmarks;

int main(int argc, char** argv) {
  std::stringstream s;
  cereal::BinaryOutputArchive a(s);

  const auto [callback_map, type_sequence] = register_callbacks(
    callback<Ack>("ack", [](auto &&x){ volatile Ack y = x; }),
    callback<Source>("source", [](auto &&x){ volatile Source y = x; }),
    callback<Foo>("foo", [](auto &&x){ volatile Foo y = x; }),
    callback<Bar>("bar", [](auto &&x){ volatile Bar y = x; })
  );

  Ack ack;
  serialize_wrapper::serialize(ack, s);

  deserialize_with_callback(a, callback_map, type_sequence);

  return 0;
}
