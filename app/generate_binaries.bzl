def generate_binaries(srcs, deps=[]):
    for src in srcs:
        name = src.replace(".cpp", "")
        native.cc_binary(
            name = name,
            srcs = [src],
            deps = deps,
        )
