#include "graphics/sdl_canvas.h"

#include <iostream>
#include <cassert>
#include <SDL.h>

SdlCanvas::SdlCanvas(int width_pixels, int height_pixels) {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
  }
  window_ = SDL_CreateWindow("Hello World!", SDL_WINDOWPOS_CENTERED,
                             SDL_WINDOWPOS_CENTERED, width_pixels,
                             height_pixels, SDL_WINDOW_SHOWN);
  if (window_ == nullptr) {
    std::cout << "SDL_Create Window Error: " << SDL_GetError() << std::endl;
  }
  renderer_ = SDL_CreateRenderer(
      window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (renderer_ == nullptr) {
    std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
  }
}

void SdlCanvas::DrawPointAtPixel(int i, int j) {
  SDL_RenderDrawPoint(renderer_, i, j);
}

int SdlCanvas::GetWidthPixels() const {
  int width = 0;
  SDL_GetWindowSize(window_, &width, nullptr);
  return width;
}

int SdlCanvas::GetHeightPixels() const {
  int height = 0;
  SDL_GetWindowSize(window_, nullptr, &height);
  return height;
}

void SdlCanvas::DrawTriangle(Triangle2 triangle) {
  const Number scale = 200;
  SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255);
  Vector2 a = std::get<0>(triangle);
  Vector2 b = std::get<1>(triangle);
  Vector2 c = std::get<2>(triangle);
  a = scale * a;
  b = scale * b;
  c = scale * c;
  a.i += GetWidthPixels()/2;
  a.j += GetHeightPixels()/2;
  b.i += GetWidthPixels()/2;
  b.j += GetHeightPixels()/2;
  c.i += GetWidthPixels()/2;
  c.j += GetHeightPixels()/2;
  //std::cout << "i:" << a.i << ", j:" << a.j << std::endl;
  assert(0 == SDL_RenderDrawLine(renderer_, a.i, a.j, b.i, b.j));
  assert(0 == SDL_RenderDrawLine(renderer_, b.i, b.j, c.i, c.j));
  assert(0 == SDL_RenderDrawLine(renderer_, c.i, c.j, a.i, a.j));
}

void SdlCanvas::Render() {
  SDL_RenderPresent(renderer_);
}

void SdlCanvas::Clear() {
  SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
  SDL_RenderClear(renderer_);
}
