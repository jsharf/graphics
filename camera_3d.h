#ifndef CAMERA_3D_H
#define CAMERA_3D_H

#include "graphics/camera.h"
#include "graphics/scene.h"
#include "graphics/canvas.h"
#include "graphics/sdl_canvas.h"

class Camera3d : public Camera {
 public:
  Camera3d(Camera *left, Camera *right, const Number center_offset)
      : left_camera_(left),
        right_camera_(right),
        center_offset_(center_offset) {}

  void SetOrientation(Matrix4 orientation) override {
    left_camera_->SetOrientation(
        orientation * Matrix4::Translate(-center_offset_ / 2.0, 0, 0));
    right_camera_->SetOrientation(
        orientation * Matrix4::Translate(center_offset_ / 2.0, 0, 0));
  }

  void SetPosition(Number i, Number j, Number k) override {
    left_camera_->SetPosition(i, j, k);
    right_camera_->SetPosition(i, j, k);
  }

  void CaptureWorld(Scene *scene, Canvas *canvas) override {
    left_camera_->CaptureWorld(scene, canvas);
    right_camera_->CaptureWorld(scene, canvas);
  }

 private : Camera *left_camera_;
  Camera *right_camera_;
  const Number center_offset_;
};

#endif /* CAMERA_3D_H */
