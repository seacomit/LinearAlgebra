
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

struct Vector3D
{
    float x, y, z;

    Vector3D() = default;

    Vector3D(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }

    float& operator [](int i)
    {
        return ((&x)[i]);
    }

    const float& operator [](int i) const
    {
        return ((&x)[i]);
    }

    Vector3D& operator *=(float s)
    {
        x *= s;
        y *= s;
        z *= s;
        return (*this);
    }

    Vector3D& operator /=(float s)
    {
        s = 1.0F / s;
        x *= s;
        y *= s;
        z *= s;
        return (*this);
    }

    Vector3D& operator +=(const Vector3D& v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        return (*this);
    }

    Vector3D& operator -=(const Vector3D& v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return (*this);
    }
};

inline Vector3D operator +(const Vector3D& a, const Vector3D& b)
{
    return (Vector3D(a.x + b.x, a.y + b.y, a.z + b.z));
}

inline Vector3D operator -(const Vector3D& a, const Vector3D& b)
{
    return (Vector3D(a.x - b.x, a.y - b.y, a.z - b.z));
}

inline Vector3D operator *(const Vector3D& v, float s)
{
    return (Vector3D(v.x * s, v.y * s, v.z * s));
}

inline Vector3D operator /(const Vector3D& v, float s)
{
    s = 1.0F / s;
    return (Vector3D(v.x * s, v.y * s, v.z * s));
}

// Negation not subtraction.
inline Vector3D operator -(const Vector3D& v)
{
    return (Vector3D(-v.x, -v.y, -v.z));
}

inline float Magnitude(const Vector3D& v)
{
    return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

inline Vector3D Normalize(const Vector3D& v)
{
    return (v / Magnitude(v));
}

// A 3x3 matrix whose API uses row vectors, but under the hood converts to and works with column vectors.
struct Matrix3D
{
    private:
        float n[3][3];
    public:
        Matrix3D() = default;

        Matrix3D(float n00, float n01, float n02,
                 float n10, float n11, float n12,
                 float n20, float n21, float n22)
        {
            n[0][0] = n00; n[0][1] = n10; n[0][2] = n20;
            n[1][0] = n01; n[1][1] = n11; n[1][2] = n21;
            n[2][0] = n02; n[2][1] = n12; n[2][2] = n22;
        }

        Matrix3D(const Vector3D& a, const Vector3D& b, const Vector3D& c)
        {
            n[0][0] = a.x; n[0][1] = a.y; n[0][2] = a.z;
            n[1][0] = b.x; n[1][1] = b.y; n[1][2] = b.z;
            n[2][0] = c.x; n[2][1] = c.y; n[2][2] = c.z;
        }

        float& operator ()(int i, int j)
        {
            return (n[j][i]);
        }

        const float& operator ()(int i, int j) const
        {
            return (n[j][i]);
        }

        Vector3D& operator [](int j)
        {
            return (*reinterpret_cast<Vector3D*>(n[j]));
        }

        const Vector3D& operator [](int j) const
        {
            return (*reinterpret_cast<const Vector3D*>(n[j]));
        }
};

int main()
{
    VideoMode vm(1920, 1080);
    RenderWindow window(vm, "LinearAlgebra", Style::Fullscreen);

    Vector3D vector(4, 8, 16);

    std::cout << vector[0];
    std::cout << vector[1];
    std::cout << vector[2];

    while (window.isOpen())
    {
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }
    }

    return 0;
}
