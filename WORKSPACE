workspace(name = "graphics")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "rules_foreign_cc",
    # TODO: Get the latest sha256 value from a bazel debug message or the latest 
    #       release on the releases page: https://github.com/bazelbuild/rules_foreign_cc/releases
    #
    sha256 = "a5a6c12ce102c92ec386ed7ccf6e365d8658b62e21eda8aff9a2817e8fc2d5cd",
    strip_prefix = "rules_foreign_cc-83aeab38da0475e1c7f7f3b22fb8e956e85c7080",
    url = "https://github.com/bazelbuild/rules_foreign_cc/archive/83aeab38da0475e1c7f7f3b22fb8e956e85c7080.tar.gz",
)

load("@rules_foreign_cc//foreign_cc:repositories.bzl", "rules_foreign_cc_dependencies")

rules_foreign_cc_dependencies()

load("//:workspace.bzl", "workspace")
workspace()
