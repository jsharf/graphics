#ifndef CANVAS_H
#define CANVAS_H
#include "graphics/types.h"

// This class is an interface to generalize over all 2-dimensional canvases.
// This is a target for rendering (3D polygons get perspective-transformed to 2D
// and can be drawn to any canvas object).
class Canvas {
 public:
  // This lets you draw a point.
  virtual void DrawPointAtPixel(int i, int j) = 0;
  virtual int GetWidthPixels() const = 0;
  virtual int GetHeightPixels() const = 0;
  // Draw a triangle to the screen in white.
  virtual void DrawTriangle(Triangle2 triangle) = 0;
  virtual void Render() = 0;
  virtual void Clear() = 0;
};
#endif /* CANVAS_H */
