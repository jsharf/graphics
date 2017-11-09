#include <tuple>
#include <array>

#include "math/geometry/vector.h"

using Number = double;

using Color = std::tuple<int, int, int>;
using Triangle3 = std::array<Vector3, 3>;
using Triangle2 = std::array<Vector2, 3>;
using RectangleDimension = std::array<Number, 2>;
