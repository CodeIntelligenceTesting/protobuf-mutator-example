/*
 * Copyright (c) 2024. Code Intelligence GmbH. All rights reserved.
 */

#include <string>

#define EXAMPLE_FLAG1 (1 << 3)
#define EXAMPLE_FLAG2 (1 << 14)

void parser_begin(bool conf1, int conf2);
void parser_parse_packet(const std::string &data, unsigned int flags);
void parser_finish();
