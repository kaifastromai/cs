#include "../include/vector.h"
#include "../include/util.storm.h"
bool operator==(Vector &v1, Vector &v2)
{
    return csl::utils::approximatelyEqual(v1.x, v2.x, Vector::EPSILON) && csl::utils::approximatelyEqual(v1.y, v2.y, Vector::EPSILON);
}