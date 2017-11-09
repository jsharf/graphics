#ifndef CAMERA_H
#define CAMERA_H 
#include "graphics/types.h"
#include "graphics/canvas.h"
#include "graphics/scene.h"
#include "math/geometry/matrix4.h"

class Camera {
  public:
  // Set the camera's position
  virtual void SetPosition(Number i, Number j, Number k) = 0;
  // Set the camera's orientation using a matrix4.
  virtual void SetOrientation(Matrix4 orientation) = 0;
  // The camera takes a picture of the scene from its perspective and draws it
  // to the canvas.
  virtual void CaptureWorld(Scene *scene, Canvas *canvas) = 0;
};

#endif /* CAMERA_H */
