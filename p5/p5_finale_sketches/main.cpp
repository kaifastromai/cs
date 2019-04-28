#include "../include/vector.h"
#include <iostream>
using namespace std;
int main()
{

    Vector v(2, 3);
    Vector v2(10, 11);
    std::cout << (string)(v2 + v) << endl;
    std::cout << v.Dot(v2) << endl;
}