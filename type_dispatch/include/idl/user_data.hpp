#ifndef SERIALIZATION__IDL__USER_DATA_HPP_
#define SERIALIZATION__IDL__USER_DATA_HPP_

#include "message_types.hpp"
#include <boost/hana/define_struct.hpp>

namespace em_benchmarks {

struct UserData {
  BOOST_HANA_DEFINE_STRUCT(UserData,
    (Header, header),
    
  );
};

};

#endif  //  SERIALIZATION__IDL__USER_DATA_HPP_
