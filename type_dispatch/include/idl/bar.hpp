#ifndef SERIALIZATION__IDL__BAR_HPP_
#define SERIALIZATION__IDL__BAR_HPP_

#include "idl/header.hpp"
#include <boost/hana/define_struct.hpp>

namespace em_benchmarks {

struct Bar {
  BOOST_HANA_DEFINE_STRUCT(Bar,
    (Header, header),
    (char, b)
  );
};

}

#endif  //  SERIALIZATION__IDL__BAR_HPP_
