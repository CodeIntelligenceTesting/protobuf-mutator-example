/*
 * Copyright (c) 2024. Code Intelligence GmbH. All rights reserved.
 */

#include <cifuzz/cifuzz.h>

#include "mutator_data.pb.h"
#include "port/protobuf.h"
#include "src/libfuzzer/libfuzzer_macro.h"
#include "src/libfuzzer/libfuzzer_mutator.h"
#include "sut.h"


// The DEFINE_PROTO_FUZZER macro is used to define a fuzz test
// that receives a protobuf message as input. In this example,
// we created a protobuf message that corresponds to the input
// data that is received by a simple parser API.
DEFINE_PROTO_FUZZER(const fuzzing::FuzzerInput &input) {
    parser_begin(input.config1(), input.config2());
    for(const auto& packet : input.packets()) {
        parser_parse_packet(packet.data(), packet.flags());
    }
    parser_finish();
}

