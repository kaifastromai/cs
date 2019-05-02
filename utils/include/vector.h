
#pragma once
#include <cmath>
#include <sstream>
#include <cmath>
#include <initializer_list>
struct Vector
{
public:
    //A constant to use in omparisons
    inline static float EPSILON;
    Vector(float in_x = 0, float in_y = 0)
    {
        x = in_x;
        y = in_y;
    };

    float x, y;
    float Dot(Vector &v)
    {

        return v.x * this->x + v.y * this->y;
    };

    //Get magnitude of self
    static float Mag(Vector &other)
    {
        return std::sqrt(std::pow(other.x, 2) + std::pow(other.y, 2));
    }
    float Mag()
    {
        return std::sqrt((this->x) * (this->x) + (this->y) * (this->y));
    }
    float Mag2()
    {
        float i = Mag();
        return i * i;
    }

    Vector Unit()
    {
        float mag = Mag();
        Vector v = Vector(this->x / mag, this->y / mag);
        return v;
    };

    static Vector Unit(Vector &v)
    {
        float mag = Mag(v);

        return Vector(v.x / mag, v.y / mag);
    };

    Vector Normalize()
    {
        Vector unit = Unit();
        this->x = unit.x;
        this->y = unit.y;
        return unit;
    };
    Vector operator+(Vector &other)
    {
        return Vector(this->x + other.x, this->y + other.y);
    };
    void operator+=(Vector other)
    {
        this->x += other.x;
        this->y += other.y;
    };
    /*  Vector operator-(Vector &other)
    {
        return Vector(this->x - other.x, this->y - other.y);
    }; */
    Vector operator-(Vector other)
    {
        return Vector(this->x - other.x, this->y - other.y);
    };
    void operator-=(Vector other)
    {
        this->x -= other.x;
        this->y -= other.y;
    };

    void operator*=(float val)
    {
        this->x *= val;
        this->y *= val;
    };
    /*  friend void operator*(float val, Vector &v)
    {
        v.x *= val;
        v.y *= val;
        //return v;
    }; */
    friend Vector operator*(float val, Vector v)
    {
        return Vector(v.x * val, v.y * val);
    };
    friend Vector operator*(Vector v, float val)
    {
        return Vector(v.x * val, v.y * val);
    };

    friend Vector operator/(Vector v, const float val)
    {
        return Vector(v.x / val, v.y / val);
    };
    friend bool operator==(Vector &v1, Vector v2);
    friend bool operator<(Vector &v1, Vector &v2);
    friend bool operator>(Vector &v1, Vector v2);
    friend bool operator<=(Vector &v1, Vector v2);
    friend bool operator>=(Vector &v1, Vector &v2);

    operator std::string() const
    {
        std::stringstream ss;
        ss << "<" << this->x << ", " << this->y << ">";
        return ss.str();
    };
};
