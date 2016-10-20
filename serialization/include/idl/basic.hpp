#ifndef SERIALIZATION__IDL__BASIC_HPP_
#define SERIALIZATION__IDL__BASIC_HPP_

#include <boost/hana/define_struct.hpp>

namespace em_benchmarks {

struct Basic {
  BOOST_HANA_DEFINE_STRUCT(Basic,
    (int32_t, count)
  );
};

};

#endif  //  SERIALIZATION__IDL__BASIC_HPP_
