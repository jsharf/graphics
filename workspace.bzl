load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

def repo():
  # Use plasticity for the math/geometry libraries.
  git_repository(
    name = "plasticity",
    remote = "https://github.com/jsharf/plasticity.git",
    commit = "a3e7f213251f4f6b4904be6ea6fde93d9519e1ce",
  )
  # Import SDL2.
  http_archive(
      name = 'linux_sdl',
      urls = [
        'https://www.libsdl.org/release/SDL2-2.0.7.tar.gz',
      ],
      build_file = '@//:BUILD.sdl2',
      strip_prefix = 'SDL2-2.0.7',
      sha256 = "ee35c74c4313e2eda104b14b1b86f7db84a04eeab9430d56e001cea268bf4d5e",
  )
