load("//third_party/jpeg:workspace.bzl", jpeg = "repo")
load("//third_party/imgui:workspace.bzl", imgui = "repo")
load("//third_party/sdl2:workspace.bzl", sdl2 = "repo")
load("//third_party/sdl2_ttf:workspace.bzl", sdl2_ttf = "repo")
load("//third_party/plasticity:workspace.bzl", plasticity = "repo")

def workspace():
    jpeg()
    imgui()
    sdl2()
    sdl2_ttf()
    plasticity()

