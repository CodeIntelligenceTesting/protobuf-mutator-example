/*
 * Copyright (c) 2024. Code Intelligence GmbH. All rights reserved.
 */

#include "mutator_data.pb.h"
#include "port/protobuf.h"
#include "src/libfuzzer/libfuzzer_macro.h"
#include "src/libfuzzer/libfuzzer_mutator.h"
#include "sut.h"

// This post-processor ensures that a specific flag
// will always be set in the generated fuzzer input data
static protobuf_mutator::libfuzzer::PostProcessorRegistration<fuzzing::DataPacket> pp = {
    [](fuzzing::DataPacket *packet, unsigned int seed) {
        unsigned int new_flags = packet->flags() | EXAMPLE_FLAG1;
        packet->set_flags(new_flags);
    }
};
