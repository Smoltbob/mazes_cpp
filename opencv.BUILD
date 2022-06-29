
cc_library(
    name = "core",
    srcs = glob([
        "modules/core/src/**/*.cpp",
        "modules/core/src/**/*.hpp",
        "modules/core/include/**/*.hpp",
        "modules/core/include/**/*.h",
    ]) + [
	"custom_hal.hpp",
	"cvconfig.h",
	"version_string.inc",
	"opencl_kernels_core.hpp",
	],
    hdrs = ["modules/core/include/opencv2/core/opencl/ocl_defs.hpp"],
    copts = [
        "-D__OPENCV_BUILD",
    ],
    includes = [
        ".",
        "modules/core/include",
    ],
    linkopts = [
        "-ldl",
    ] + select({
        "//conditions:default": ["-lpthread"],
    }),
    visibility = ["//visibility:public"],
)

genrule(
    name = "cvconfig",
    outs = ["cvconfig.h"],
    cmd = """
      echo '#define HAVE_PNG' >> $@
    """,
)

genrule(
    name = "custom_hal",
    outs = ["custom_hal.hpp"],
    cmd = "touch $@",
)

genrule(
    name = "version_string",
    outs = ["version_string.inc"],
    cmd = "echo '\"OpenCV 3.1.0\"' > $@",
)

genrule(
    name = "opencv_core_kernels",
    outs = ["opencl_kernels_core.hpp"],
    cmd = """
      echo '#include "opencv2/core/ocl.hpp"' > $@
      echo '#include "opencv2/core/ocl_genbase.hpp"' > $@
      echo '#include "opencv2/core/opencl/ocl_defs.hpp"' > $@
    """,
)

cc_library(
    name = "imgproc",
    srcs = glob([
        "modules/imgproc/src/**/*.cpp",
        "modules/imgproc/src/**/*.hpp",
        "modules/imgproc/src/**/*.h",
        "modules/imgproc/include/**/*.hpp",
        "modules/imgproc/include/**/*.h",
    ]) + ["opencl_kernels_imgproc.hpp"],
    copts = ["-D__OPENCV_BUILD"],
    includes = [
        ".",
        "modules/core/include",
        "modules/imgproc/include",
    ],
    visibility = ["//visibility:public"],
    deps = [":core"],
)

genrule(
    name = "opencv_imgproc_kernels",
    outs = ["opencl_kernels_imgproc.hpp"],
    cmd = """
      echo '#include "opencv2/core/ocl.hpp"' > $@
      echo '#include "opencv2/core/ocl_genbase.hpp"' > $@
      echo '#include "opencv2/core/opencl/ocl_defs.hpp"' > $@
    """,
)


cc_library(
    name = "imgcodecs",
    srcs = glob([
        "modules/imgcodecs/src/**/*.cpp",
        "modules/imgcodecs/src/**/*.hpp",
        "modules/imgcodecs/include/**/*.hpp",
        "modules/imgcodecs/include/**/*.h",
    ]),
    copts = [
        "-D__OPENCV_BUILD",
    ],
    includes = [
        "modules/imgcodecs/include",
    ],
    visibility = ["//visibility:public"],
    deps = [
        ":core",
        ":imgproc",
	"@libpng//:libpng",
    ],
)
