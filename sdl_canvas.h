#ifndef SDL_CANVAS_H
#define SDL_CANVAS_H

#include "canvas.h"

#include <string>

struct SDL_Window;
struct SDL_Renderer;

class SdlCanvas : public Canvas {
 public:
  SdlCanvas(int width_pixels, int height_pixels, std::string name = "Hello World");
  // This lets you draw a point.
  void DrawPointAtPixel(int i, int j) override;
  int GetWidthPixels() const override;
  int GetHeightPixels() const override;
  // Draw a triangle to the screen in white.
  void DrawTriangle(Triangle2 triangle) override;
  void Render() override;
  void Clear() override;

 private:
  SDL_Window *window_;
  SDL_Renderer *renderer_;
};
#endif /* SDL_CANVAS_H */
