#ifndef SCENE_H
#define SCENE_H 
#include <vector>

// A scene contains a large number of triangles that need to be drawn.
class Scene {
  public:
   virtual std::vector<Triangle3> GetPrimitives() = 0;
};
#endif /* SCENE_H */
