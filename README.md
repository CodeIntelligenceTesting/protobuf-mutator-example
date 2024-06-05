# protobuf-mutator-example

This example project shows how `libprotobuf-mutator` can be used with `cifuzz` to fuzz C++ code. The fuzzer input in this scenario is a protobuf message that is defined in `test/mutator_data.proto`. In the fuzz test `test/fuzztest.cpp`, we are using the `DEFINE_PROTO_FUZZER` macro to define a fuzz test that receives mutated protobuf messages from the `libprotobuf-mutator`. In addition to that, a post processor is defined in `test/post_processor.cpp` to ensure that mutated protobuf messages keep certain properties.


### Build and run the fuzz test

```sh
cifuzz run fuzztest
```

The fuzzer should be able to find the bug in less than a minute.


### View the crashing input

All fuzzer inputs are stored in text form so that analyzing a crashing input is easy:

```sh
> cat .cifuzz-findings/quirky_puma/crashing-input
config1: true
config2: -7654
packets {
  flags: 8
}
packets {
  flags: 8
}
packets {
  flags: 8
}
packets {
  flags: 4227858431
  data: "BUG"
}
```
