#ifndef SERIALIZATION__IDL__SOURCE_HPP_
#define SERIALIZATION__IDL__SOURCE_HPP_

#include <array>

#include "idl/header.hpp"
#include <boost/hana/define_struct.hpp>
#include <cereal/types/array.hpp>

namespace em_benchmarks {

struct Source {
  BOOST_HANA_DEFINE_STRUCT(Source,
    (Header, header),
    (uint32_t, protocol_id),
    (std::array<uint32_t, 3>, guid)
  );
};

}

#endif  //  SERIALIZATION__IDL__SOURCE_HPP_
