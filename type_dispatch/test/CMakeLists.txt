include(../cmake/define_deserialize_benchmark.cmake)

define_deserialize_benchmark(deserialize_meta)
#target_compile_options(deserialize_meta PUBLIC "-fno-rtti")
define_deserialize_benchmark(deserialize_casting)
#target_compile_options(deserialize_casting PUBLIC "-fno-rtti")
