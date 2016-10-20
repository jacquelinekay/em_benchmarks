cmake_minimum_required(VERSION 3.5.1)
project(em_benchmarks)

set(CEREAL_INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/external/cereal/include)
set(HANA_INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/external/hana/include)
set(VARIANT_INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/external/variant)

set(CMAKE_CXX_FLAGS "-Os")

add_subdirectory(serialization)
add_subdirectory(type_dispatch)
