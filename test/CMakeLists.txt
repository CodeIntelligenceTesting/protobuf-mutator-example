find_package(Protobuf REQUIRED)
find_package(absl CONFIG)

protobuf_generate_cpp(
    PROTO_SRCS
    PROTO_HDRS
    mutator_data.proto
)

add_library(protobuf_mutator OBJECT
    ${PROTO_SRCS}
    ${PROTO_HDRS}
    post_processor.cpp
)

target_include_directories(protobuf_mutator PUBLIC
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${LIB_PROTOBUF_MUTATOR_INCLUDE_DIR}
    ${Protobuf_INCLUDE_DIR}
)

target_link_libraries(protobuf_mutator PUBLIC
    ${Lib_Protobuf_Mutator_LIBRARIES}
    ${Protobuf_LIBRARIES}
    absl::log_internal_check_op
    sut
)

add_fuzz_test(fuzztest fuzztest.cpp)
target_link_libraries(fuzztest sut protobuf_mutator)
