#ifndef SERIALIZATION__IDL__ACK_HPP_
#define SERIALIZATION__IDL__ACK_HPP_

#include "idl/header.hpp"
#include <boost/hana/define_struct.hpp>

namespace em_benchmarks {

struct Ack {
  BOOST_HANA_DEFINE_STRUCT(Ack,
    (Header, header),
    (uint32_t, writer_id),
    (uint32_t, count)
  );
};

}

#endif  //  SERIALIZATION__IDL__ACK_HPP_
