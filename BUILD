package_group(
    name = "graphics",
    packages = [
        "//graphics/...",
    ],
    includes = [
        ":graphics_users",
    ],
)

package_group(
    name = "graphics_users",
    packages = [
        "//math/..."
    ],
    includes = [],
)

cc_library(
  name = "canvas",
  hdrs = ["canvas.h"],
  visibility = [":graphics"],
)

cc_library(
  name = "camera",
  hdrs = ["camera.h"],
  visibility = [":graphics"],
  deps = [
      ":canvas",
      ":scene",
      "//math/geometry:matrix4",
  ],
)

cc_library(
  name = "scene",
  hdrs = ["scene.h"],
  visibility = [":graphics"],
)

cc_library(
  name = "types",
  hdrs = ["types.h"],
  visibility = [":graphics"],
)

cc_library(
  name = "perspective_camera",
  hdrs = ["perspective_camera.h"],
  visibility = [":graphics"],
  srcs = ["perspective_camera.cc"],
  deps = [
      ":camera",
      ":canvas",
      ":scene",
      ":types",
      "//math/geometry:matrix4",
      "//math/geometry:vector",
  ],
)

cc_library(
  name = "camera_3d",
  hdrs = ["camera_3d.h"],
  visibility = [":graphics"],
  deps = [
      ":camera",
      ":canvas",
      ":scene",
      ":types",
      "//math/geometry:matrix4",
      "//math/geometry:vector",
  ],
)

cc_library(
  name = "sdl_canvas",
  hdrs = ["sdl_canvas.h"],
  visibility = [":graphics"],
  srcs = ["sdl_canvas.cc"],
  deps = [
      ":canvas",
      ":types",
      "//math/geometry:vector",
  ],
  copts = [
      "-I/Library/Frameworks/SDL2.framework/Headers",
      "-D_THREAD_SAFE",
  ],
  linkopts = [
      "-L/usr/local/lib",
      "-lSDL2",
  ],
)

# For the utah_teapot_demo. Contains teapot vertex mesh data.
cc_library(
  name = "utah_data",
  hdrs = ["utah_teapot.h"],
  visibility = [":graphics"],
)

# A little demo which renders the utah teapot.
cc_binary(
  name = "utah_demo",
  srcs = ["utah_demo.cc"],
  deps = [
      ":sdl_canvas",
      ":scene",
      ":perspective_camera",
      ":camera_3d",
      ":types",
      ":utah_data",
      "//math/geometry:matrix4",
  ],
  copts = [
      "-I/Library/Frameworks/SDL2.framework/Headers",
  ],
  linkopts = ["-lm"],
  linkstatic = 1,
)
