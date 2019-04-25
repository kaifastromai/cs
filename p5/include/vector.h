
#include <cmath>
#include <sstream>
#include <cmath>

struct Vector
{
public:
    Vector(float in_x = 0, float in_y = 0)
    {
        x = in_x;
        y = in_y;
    };
    float x;
    float y;
    float Dot(Vector &v)
    {

        return v.x * this->x + v.y * this->y;
    };

    //Get magnitude of self
    float Mag(Vector &other)
    {
        return std::sqrt(std::pow(other.x, 2) + std::pow(other.y, 2));
    }

    Vector Unit()
    {
        float mag = Mag(*this);
        return Vector(this->x / mag, this->y / mag);
    }
    void Normalize()
    {
        Vector unit = Unit();
        this->x = unit.x;
        this->y = unit.y;
    }   Vector operator+(Vector &other)
    {
        return Vector(this->x + other.x, this->y + other.y);
    };
    operator std::string() const
    {
        std::stringstream ss;
        ss << "<" << this->x << ", " << this->y << ">";
        return ss.str();
    };
};