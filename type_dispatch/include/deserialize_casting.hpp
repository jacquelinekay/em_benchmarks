#ifndef TYPE_DISPATCH__DESERIALIZE_CASTING_HPP_
#define TYPE_DISPATCH__DESERIALIZE_CASTING_HPP_

#include <map>
#include <string>
#include <cereal/archives/binary.hpp>

#include "idl/header.hpp"
#include "refl_serializer.hpp"

namespace em_benchmarks {

using CallbackMap = std::unordered_map<std::string, void (*)(void *)>;

void deserialize_with_callback(cereal::BinaryOutputArchive &archive,
                               CallbackMap &callback_map) {
  Header header;
  archive(header);
  callback_map[header.type_id](&archive);
}

void register_callback(const std::string &id, void(*callback)(void *),
                       CallbackMap &callback_map) {
  callback_map[id] = callback;
}
};

#endif // TYPE_DISPATCH__DESERIALIZE_CASTING_HPP_
