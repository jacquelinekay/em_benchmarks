#ifndef SERIALIZATION__IDL__PRIMITIVES_HPP_
#define SERIALIZATION__IDL__PRIMITIVES_HPP_

#include <boost/hana/define_struct.hpp>
#include <cereal/types/string.hpp>

#include <string>

namespace em_benchmarks {
namespace msg {

struct Primitives {
  BOOST_HANA_DEFINE_STRUCT(Primitives,
    (int32_t, int32_value),
    (uint32_t, uint32_value),
    (int64_t, int64_value),
    (uint64_t, uint64_value),
    (double, double_value),
    (float, float_value),
    (bool, bool_value),
    (std::string, string_value)
  );
};

// needed for equality comparisons of std containers of this struct
bool operator==(const Primitives &a, const Primitives &b) {
  return boost::hana::equal(a, b);
}

}
}

#endif  //  SERIALIZATION__IDL__PRIMITIVES_HPP_
