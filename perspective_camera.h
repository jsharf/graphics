#ifndef PERSPECTIVE_CAMERA_H
#define PERSPECTIVE_CAMERA_H
#include "graphics/camera.h"
#include "graphics/types.h"
#include "math/geometry/vector.h"
#include "math/geometry/matrix4.h"

class PerspectiveCamera : public Camera {
 public:
  void SetOrientation(Matrix4 orientation) override;
  // Position vector components in meters.
  void SetPosition(Number i, Number j, Number k) override;
  void CaptureWorld(Scene* scene, Canvas* canvas) override;

 private:
  static Triangle2 PerspectiveProject(Triangle3 vertex);
  static Vector2 PerspectiveProject(Vector3 vertex);
  static Triangle3 TransformToCameraView(Matrix4 modelview_matrix,
                                         Triangle3 triangle);

  Matrix4 orientation_;
  Vector3 position_;
};
#endif /* PERSPECTIVE_CAMERA_H */
