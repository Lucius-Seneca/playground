# This is just a dummy target to ensure that the compile_commands.json file is generated
# with all dependencies of the whole project
cc_binary(
    name = "dummy",
    srcs = [],
    deps = [
        "@googletest//:gtest",
        "@googletest//:gtest_main",
        "//graph:graph",
        "//calculations:calculations",
    ],
    visibility = ["//visibility:public"],
)
