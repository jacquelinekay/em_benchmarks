#ifndef SERIALIZATION__IDL__FOO_HPP_
#define SERIALIZATION__IDL__FOO_HPP_

#include "idl/header.hpp"
#include <boost/hana/define_struct.hpp>

namespace em_benchmarks {

struct Foo {
  BOOST_HANA_DEFINE_STRUCT(Foo,
    (Header, header),
    (uint32_t, f)
  );
};

}

#endif  //  SERIALIZATION__IDL__FOO_HPP_
