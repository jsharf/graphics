#include "graphics/utah_teapot.h"

#include <iostream>
#include <vector>
#include <math.h>

#include <SDL.h>

#include "graphics/types.h"
#include "graphics/scene.h"
#include "graphics/perspective_camera.h"
#include "graphics/camera_3d.h"
#include "graphics/sdl_canvas.h"
#include "math/geometry/matrix4.h"

using Quad = std::tuple<Vector3, Vector3, Vector3, Vector3>;

class UtahTeapotScene : public Scene {
 public:
  std::vector<Triangle3> GetPrimitives() override {
    std::vector<Triangle3> triangles;
    const int num_quads = sizeof(polygons) / (sizeof(polygons[0]) * 4);
    for (int i = 0; i < num_quads; ++i) {
      const int vertex_index_a = polygons[i * 4 + 0] * 3;
      const int vertex_index_b = polygons[i * 4 + 1] * 3;
      const int vertex_index_c = polygons[i * 4 + 2] * 3;
      const int vertex_index_d = polygons[i * 4 + 3] * 3;
      Vector3 vertex_a(vertices[vertex_index_a + 0],
                       vertices[vertex_index_a + 1],
                       vertices[vertex_index_a + 2]);
      Vector3 vertex_b(vertices[vertex_index_b + 0],
                       vertices[vertex_index_b + 1],
                       vertices[vertex_index_b + 2]);
      Vector3 vertex_c(vertices[vertex_index_c + 0],
                       vertices[vertex_index_c + 1],
                       vertices[vertex_index_c + 2]);
      if (vertex_index_d < 0) {
        triangles.push_back(Triangle3{{vertex_a, vertex_b, vertex_c}});
      } else {
        Vector3 vertex_d(vertices[vertex_index_d + 0],
                         vertices[vertex_index_d + 1],
                         vertices[vertex_index_d + 2]);
        Quad quad(vertex_a, vertex_b, vertex_c, vertex_d);
        std::vector<Triangle3> quad_triangles = QuadToTriangles(quad);
        for (Triangle3 triangle : quad_triangles) {
          triangles.push_back(triangle);
        }
      }
    }
    return triangles;
  }

 private:
  static std::vector<Triangle3> QuadToTriangles(Quad quad) {
    Triangle3 a;
    Triangle3 b;
    std::vector<Triangle3> result;
    std::get<0>(a) = std::get<0>(quad);
    std::get<1>(a) = std::get<1>(quad);
    std::get<2>(a) = std::get<3>(quad);
    std::get<0>(b) = std::get<1>(quad);
    std::get<1>(b) = std::get<2>(quad);
    std::get<2>(b) = std::get<3>(quad);
    result.push_back(a);
    result.push_back(b);
    return result;
  }
};

int main() {
  const int width = 640;
  const int height = 480;
  const Number offset = 1.8;
  SdlCanvas canvas(width, height);
  UtahTeapotScene teapot_scene;
  PerspectiveCamera left_camera;
  PerspectiveCamera right_camera;
  Camera3d camera(&left_camera, &right_camera, offset);
  camera.SetPosition(0, -2, 1);
  camera.SetOrientation(Matrix4::RotI(M_PI/2.0));
  SDL_Event e;
  while (true) {
    SDL_PollEvent(&e);
    if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) break;
    // Transformation matrix: each point rotates around origin 2PI/second.
    canvas.Clear();
    camera.CaptureWorld(&teapot_scene, &canvas);
    canvas.Render();
    SDL_Delay(1);
  }
}
