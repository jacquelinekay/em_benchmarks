#ifndef SERIALIZATION__IDL__HEADER_HPP_
#define SERIALIZATION__IDL__HEADER_HPP_

#include <string>

#include <boost/hana/define_struct.hpp>
#include <cereal/types/string.hpp>

#include "message_types.hpp"

namespace em_benchmarks {

struct Header {
  BOOST_HANA_DEFINE_STRUCT(Header,
    (std::string, type_id)
  );
};

};

#endif  //  SERIALIZATION__IDL__HEADER_HPP_
