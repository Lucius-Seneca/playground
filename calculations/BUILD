cc_library(
    name = "calculations",
    srcs = glob(["src/*.cpp"]),
    hdrs = glob(["include/calculations/*.hpp"]),
    deps = [
        "@eigen//:eigen",
    ],
    visibility = ["//app:__pkg__", "//dummy:__pkg__"],
)

cc_test(
    name = "calculation_test",
    size = "small",
    srcs = glob(["tests/*.cpp"]),
    deps = [
        "@googletest//:gtest",
        "@googletest//:gtest_main",
        "calculations"
    ],
)
