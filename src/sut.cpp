/*
 * Copyright (c) 2024. Code Intelligence GmbH. All rights reserved.
 */

#include <cassert>
#include <cstddef>
#include <string>

#include "sut.h"

static bool example_config_1;
static int example_config_2;
static size_t parsed_packets;

void parser_begin(bool conf1, int conf2) {
    example_config_1 = conf1;
    example_config_2 = conf2;
    parsed_packets = 0;
}

void parser_parse_packet(const std::string &data, unsigned int flags) {
    parsed_packets++;

    // The mutator post-processor ensures
    // that this flag is always set.
    assert(flags & EXAMPLE_FLAG1);

    // Example for a complex condition that triggers a bug.
    if(example_config_1 == true && example_config_2 == -7654 &&
       parsed_packets == 4 && data.find("BUG") != data.npos &&
       (flags & EXAMPLE_FLAG2)) {
        // Page fault
        *((char *) 1) = 2;
    }
}

void parser_finish() {}
