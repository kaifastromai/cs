#include "../include/vector.h"
#include "../include/util.storm.h"
bool operator==(Vector &v1, Vector v2)
{

    return csl::utils::nearly_equal(v1.x, v2.x) && csl::utils::nearly_equal(v1.y, v2.y);
}
bool operator<(Vector &vl, Vector &vr)
{

    return csl::utils::definitelyLessThan(vl.x, vr.x, Vector::EPSILON) &&
           csl::utils::definitelyLessThan(vl.y, vr.y, Vector::EPSILON);
}
bool operator>(Vector &vl, Vector vr)
{
    return csl::utils::definitelyGreaterThan(vl.x, vr.x, Vector::EPSILON) &&
           csl::utils::definitelyGreaterThan(vl.y, vr.y, Vector::EPSILON);
}

bool operator>=(Vector &vl, Vector &vr)
{

    return operator>(vl, vr) || operator==(vl, vr);
}
bool operator<=(Vector &vl, Vector vr)
{
    return operator<(vl, vr) || operator==(vl, vr);

}

