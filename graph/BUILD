cc_library(
    name = "graph",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/graph/*.hpp"]),
    visibility = ["//app:__pkg__"],
)

cc_test(
    name = "node_test",
    size = "small",
    srcs = glob(["tests/*.cpp"]),
    deps = [
        "@googletest//:gtest",
        "@googletest//:gtest_main",
        "graph"
    ],
)
