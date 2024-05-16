#pragma once

#include <glm/glm.hpp>

namespace Ynion::Math {

	bool DecomposeTransform(const glm::mat4& transform, glm::vec3& translation, glm::vec3& rotation, glm::vec3& scale);

    class Vector2 {
    public:
        float X, Y;
    public:
        Vector2() {}
        Vector2(float scalar) : X(scalar), Y(scalar) {}
        Vector2(float x, float y) : X(x), Y(y) {}

        static Vector2 zero() { return Vector2(0.0f); }

        Vector2 operator +(const Vector2& a) const {
            return Vector2(X + a.X, Y + a.Y);
        }

        Vector2 operator *=(float scalar) {
            return Vector2(X * scalar, Y * scalar);
        }
    };

    class Vector3 {
    public:
        float X, Y, Z;
    public:
        Vector3() {}
        Vector3(float scalar) : X(scalar), Y(scalar), Z(scalar) {}
        Vector3(float x, float y, float z) : X(x), Y(y), Z(z) {}

        static Vector3 zero() { return Vector3(0.0f); }

        Vector3 operator +=(Vector3 b) {
            return Vector3(X + b.X, Y + b.Y, Z + b.Z);
        }

        Vector3 operator *=(float scalar) {
            return Vector3(X * scalar, Y * scalar, Z * scalar);
        }
    };

}