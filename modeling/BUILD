cc_library(
    name = "modeling",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/modeling/*.hpp"]),
    deps = [
        "@lanelet2//:lanelet2_core",
    ],
    visibility = ["//app:__pkg__", "//dummy:__pkg__"],
)

cc_test(
    name = "generate_lane_test",
    srcs = ["tests/generate_lane_test.cpp"],
    deps = [
        ":modeling",
        "@googletest//:gtest",
        "@googletest//:gtest_main",
    ],
)
