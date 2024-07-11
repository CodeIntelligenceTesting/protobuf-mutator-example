add_custom_command(OUTPUT
    ${CMAKE_CURRENT_BINARY_DIR}/mutator_data.pb.h
    ${CMAKE_CURRENT_BINARY_DIR}/mutator_data.pb.cc
    COMMAND protobuf::protoc mutator_data.proto
    --proto_path=${CMAKE_CURRENT_SOURCE_DIR}
    --cpp_out=${CMAKE_CURRENT_BINARY_DIR}
)

add_library(protobuf_mutator OBJECT
    ${CMAKE_CURRENT_BINARY_DIR}/mutator_data.pb.cc
    post_processor.cpp
)

target_include_directories(protobuf_mutator PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(protobuf_mutator PUBLIC
    protobuf-mutator-libfuzzer
    sut
)

add_fuzz_test(fuzztest fuzztest.cpp)
target_link_libraries(fuzztest sut protobuf_mutator)
target_link_options(fuzztest PRIVATE
    "-Wl,--copy-dt-needed-entries"
)
