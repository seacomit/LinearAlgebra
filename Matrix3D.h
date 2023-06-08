#pragma once
#include "Vector3D.h"

// A 3x3 matrix whose API uses row vectors, but under the hood converts to and works with column vectors.
struct Matrix3D
{
private:
    float n[3][3];
public:
    Matrix3D() = default;

    Matrix3D(float n00, float n01, float n02,
        float n10, float n11, float n12,
        float n20, float n21, float n22);

    Matrix3D(const Vector3D& a, const Vector3D& b, const Vector3D& c);

    float& operator ()(int i, int j);

    const float& operator ()(int i, int j) const;

    Vector3D& operator [](int j);

    const Vector3D& operator [](int j) const;
};