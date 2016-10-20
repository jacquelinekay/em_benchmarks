find_package(Protobuf)

# TODO generate messages with empy
# need to generate array sizes in protobuf
set(ALL_MESSAGES "basic;primitives;primitive_arrays;primitives_array;nested")

if(NOT ${PROTOBUF_FOUND})
  message(WARNING "Protobuf not found. Code generation benchmarks will not be built.")
else()
  # TODO Invoke code generation for each message name
  foreach(MSG ${ALL_MESSAGES})
    list(APPEND IDL_FILES "proto/${MSG}.proto")
  endforeach()
  message(STATUS "generating: ${IDL_FILES}")
  PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS ${IDL_FILES})
add_library(proto_gen ${PROTO_SRCS} ${PROTO_HDRS})
endif()

add_subdirectory(test)
