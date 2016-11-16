function(define_deserialize_benchmark BENCHMARK_NAME)
  add_executable(${BENCHMARK_NAME} ${BENCHMARK_NAME}.cpp)
  target_include_directories(${BENCHMARK_NAME} PUBLIC
    "${CMAKE_SOURCE_DIR}/serialization/include"
    ${CEREAL_INCLUDE_DIRS} ${HANA_INCLUDE_DIRS} "../include")
  target_compile_options(${BENCHMARK_NAME} PUBLIC "-std=c++1z" "-Wall" "-Os")
endfunction()
