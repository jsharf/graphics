#include "perspective_camera.h"

#include <iostream>
#include <vector>

void PerspectiveCamera::SetOrientation(Matrix4 orientation) {
  orientation_ = orientation;
}

void PerspectiveCamera::SetPosition(Number i, Number j, Number k) {
  position_.i = i;
  position_.j = j;
  position_.k = k;
}

void PerspectiveCamera::CaptureWorld(Scene *scene, Canvas *canvas) {
  Matrix4 camera_matrix =
      Matrix4::Translate(position_.i, position_.j, position_.k) * orientation_;
  Matrix4 modelview_matrix = camera_matrix.Invert();
  std::vector<Triangle3> triangles = scene->GetPrimitives();
  std::vector<Triangle2> projected_triangles;
  for (Triangle3 triangle : triangles) {
    Triangle3 camera_view_triangle = TransformToCameraView(modelview_matrix, triangle);
    Triangle2 projected_triangle = PerspectiveProject(camera_view_triangle);
    canvas->DrawTriangle(projected_triangle);
  }
}

Triangle3 PerspectiveCamera::TransformToCameraView(Matrix4 modelview_matrix, Triangle3 triangle) {
  Triangle3 triangle_3d;
  std::get<0>(triangle_3d) = modelview_matrix * std::get<0>(triangle);
  std::get<1>(triangle_3d) = modelview_matrix * std::get<1>(triangle);
  std::get<2>(triangle_3d) = modelview_matrix * std::get<2>(triangle);
  return triangle_3d;
}

Triangle2 PerspectiveCamera::PerspectiveProject(Triangle3 triangle_3d) {
  Triangle2 triangle_2d;
  std::get<0>(triangle_2d) = PerspectiveProject(std::get<0>(triangle_3d));
  std::get<1>(triangle_2d) = PerspectiveProject(std::get<1>(triangle_3d));
  std::get<2>(triangle_2d) = PerspectiveProject(std::get<2>(triangle_3d));
  return triangle_2d;
}

Vector2 PerspectiveCamera::PerspectiveProject(Vector3 vertex) {
  Vector2 orthographic(vertex.i, vertex.j);
  if (vertex.k == 0) {
    return orthographic;
  }
  Vector2 perspective = orthographic * (1 / vertex.k);
  return perspective;
}
