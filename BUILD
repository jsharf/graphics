
cc_library(
  name = "canvas",
  hdrs = ["canvas.h"],
  visibility = ["//visibility:public"],
  deps = [":types"],
)

cc_library(
  name = "camera",
  hdrs = ["camera.h"],
  visibility = ["//visibility:public"],
  copt = ["-Iexternal/"],
  deps = [
      ":canvas",
      ":scene",
      ":types",
      "@plasticity//geometry:matrix4",
  ],
)

cc_library(
  name = "scene",
  hdrs = ["scene.h"],
  visibility = ["//visibility:public"],
)

cc_library(
  name = "types",
  hdrs = ["types.h"],
  copts = ["-Iexternal/"],
  visibility = ["//visibility:public"],
  deps = [
    "@plasticity//geometry:vector",
  ],
)

cc_library(
  name = "perspective_camera",
  hdrs = ["perspective_camera.h"],
  visibility = ["//visibility:public"],
  srcs = ["perspective_camera.cc"],
  copt = ["-Iexternal/"],
  deps = [
      ":camera",
      ":canvas",
      ":scene",
      ":types",
      "@plasticity//geometry:matrix4",
      "@plasticity//geometry:vector",
  ],
)

cc_library(
  name = "camera_3d",
  hdrs = ["camera_3d.h"],
  visibility = ["//visibility:public"],
  deps = [
      ":camera",
      ":canvas",
      ":scene",
      ":types",
      "@plasticity//geometry:matrix4",
      "@plasticity//geometry:vector",
  ],
)

cc_library(
  name = "sdl_canvas",
  hdrs = ["sdl_canvas.h"],
  visibility = ["//visibility:public"],
  srcs = ["sdl_canvas.cc"],
  deps = [
      ":canvas",
      ":types",
      "@linux_sdl//:sdl2",
      "@plasticity//geometry:vector",
  ],
  copts = [
      "-D_THREAD_SAFE",
      "-Iexternal/",
  ],
)

# For the utah_teapot_demo. Contains teapot vertex mesh data.
cc_library(
  name = "utah_data",
  hdrs = ["utah_teapot.h"],
  visibility = ["//visibility:public"],
)

# A little demo which renders the utah teapot.
cc_binary(
  name = "utah_demo",
  srcs = ["utah_demo.cc"],
  copts = ["-Iexternal/"],
  deps = [
      ":sdl_canvas",
      ":scene",
      ":perspective_camera",
      ":camera_3d",
      ":types",
      ":utah_data",
      "@linux_sdl//:sdl2",
      "@plasticity//geometry:matrix4",
  ],
  linkopts = ["-lm"],
  linkstatic = 1,
)
