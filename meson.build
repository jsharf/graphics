# Setup datadir to include share/
project('graphics', 'cpp', version: '1.0', default_options: ['cpp_std=c++17', 'b_lld=true'])

# SDL2 Dependency
sdl2_dep = dependency('sdl2', required: true)

# Dear ImGui Dependency
# If Dear ImGui is available in WrapDB, use wrapdb to fetch it.
# Otherwise, you may need to manually include it or write a wrap file.
imgui_dep = dependency('imgui', required: true)

gl_dep = dependency('gl', required : true)

plasticity_proj = subproject('plasticity')
geometry_dep = plasticity_proj.get_variable('geometry_dep')

install_subdir('share', install_dir: get_option('datadir') / meson.project_name())

# Create a lib and dependency for SDL wrapper.
sdl_canvas_lib = library('sdl_canvas',
    sources: [
        'sdl_canvas.cc',
    ],
    dependencies: [sdl2_dep, imgui_dep, gl_dep, geometry_dep],
    install: true
)

sdl_canvas_dep = declare_dependency(
    link_with: [sdl_canvas_lib],
    include_directories: include_directories('.'),
    dependencies: [sdl2_dep, gl_dep]
)

camera_lib = library('camera',
    sources: [
        'perspective_camera.cc',
    ],
    dependencies: [sdl2_dep, geometry_dep],
)

# Create a utah teapot demo executable.
executable('utah_demo',
    'utah_demo.cc',
    link_with: [camera_lib],
    dependencies: [sdl_canvas_dep, imgui_dep, gl_dep, geometry_dep],
    install: true
)