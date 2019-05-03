#pragma once
#include <iostream>
#include <random>
#include <chrono>
#include <exception>
#include <sstream>
#include "../include/vector.h"
//#include "../include/magnet_rocket.h"
namespace csl
{

class utils
{

private:
public:
    template <class T>
    //Add/subtracts maxDiff as a percentage of the whole:
    //(maxDiff of 10 would be 10% variation)
    static T Jiggle(T a, float maxDiff)
    {

        int r = unif<int>(0, 1);

        if (r == 0)
        {
            return a + unif<T>(0, a * maxDiff / 100); // ready to generate random numbers
        }
        else if (r == 1)
        {
            return a - unif<T>(0, a * maxDiff / 100);
        }
        else
            return (T)0;
    };

    template <class T>
    static T unif(T b, T t)
    {
        std::mt19937_64 rng;
        // initialize the random number generator with time-dependent seed
        uint64_t timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        std::seed_seq ss{uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed >> 32)};

        rng.seed(ss);
        if constexpr (std::is_same_v<T, int>)
        {
            std::uniform_int_distribution<T> dis_i(b, t);
            return dis_i(rng);
        }
        else
        {
            std::uniform_real_distribution<T> dis_r(b, t);
            return dis_r(rng);
        }
    }
    //Return true or false based upon variable weight (0-100.0f):
    //Value of 40 will return true 40% of the time
    static bool weighted_bool(float weight)
    {
        float f = unif<float>(0, 1);
        float vv = weight / 100.0f;
        return f < vv;
    }
    //Checks if a string can be safely cast to float. Returns a bool.
    static bool is_float(std::string &in)
    {

        std::istringstream iss(in);
        float f;
        iss >> std::noskipws >> f; // noskipws considers leading whitespace invalid
        // Check the entire string was consumed and if either failbit or badbit is set
        return iss.eof() && !iss.fail();
    }
    //Safely convert a string to a float. Returns a bool representing if the conversion succeeded or not. Takes variables by ref
    static bool safe_string_to_float(std::string &in, float &f)
    {
        if (is_float(in))
        {
            f = std::stof(in);
            return true;
        }
        else
        {
            return false;
        }
    }

    static bool approximatelyEqual(float a, float b, float epsilon)
    {
        return std::abs(a - b) <= ((std::abs(a) < std::abs(b) ? std::abs(b) : std::abs(a)) * epsilon);
    }

    static bool essentiallyEqual(float a, float b, float epsilon)
    {
        return std::abs(a - b) <= ((std::abs(a) > std::abs(b) ? std::abs(b) : std::abs(a)) * epsilon);
    }

    static bool definitelyGreaterThan(float a, float b, float epsilon)
    {
        return (a - b) > ((std::abs(a) < std::abs(b) ? std::abs(b) : std::abs(a)) * epsilon);
    }

    static bool definitelyLessThan(float a, float b, float epsilon)
    {
        return (b - a) > ((std::abs(a) < std::abs(b) ? std::abs(b) : std::abs(a)) * epsilon);
    }
    static bool nearly_equal(float v, float v1, float epsilon = 4.0f)
    {
        return std::abs(std::abs(v1) - std::abs(v)) < epsilon;
    }
    //interpolate between two values a and b given a fraction f
    static float lerp(float a, float b, float f)
    {
        return (a * (1.0 - f)) + (b * f);
    }
    //interpolate Vector values;
    static Vector lerp(Vector a, Vector b, float f)
    {
        return Vector(lerp(a.x, b.x, f), lerp(a.y, b.y, f));
    }
    /*  static int factorial(int i = 5)
    {
        int result = 1;

        for (int j = i - 1; j >= 0; j--)
        {

            result *= (i - j);
            // std::cout << j << std::endl;
        }
        return result;
    } */

    /*  static void spawn_threads(int n,)
    {
        std::thread threads[n];
        // spawn n threads:
        for (int i = 0; i < n; i++)
        {
            threads[i] = thread(doSomething, i + 1);
        }

        for (auto &th : threads)
        {
            th.join();
        }
    } */
    //Physics class definitions.
    class physics
    {
        /*   enum force_type
        {
            Spring,
            Gravity,
            Electromagnetic
        }; */
    public:
        //Generic physical attraction force between two objects given influence c1 and c2, respectively
        static Vector get_attraction_force(Vector pos1, Vector pos2, float c1 = 1.0f, float c2 = 200, float p_coef = 9e9)
        {
            float coef = p_coef;
            Vector r = pos2 - pos1;
            Vector f_particle = (r.Mag2() / (coef * c1 * c2)) * (r.Unit());
            return f_particle;
        };
        //Attraction force modeled after Ideal Spring Law
        static Vector get_spring_force(Vector pos1, Vector pos2, float ks = 30, float L0 = 0)
        {
            Vector L = pos1 - pos2;
            float stretch = L.Mag() - L0;
            Vector f_particle = -ks * stretch * L.Unit();
            return f_particle;
        };
        /*  static void attract_to_location(Vector location, MagnetRocket &r, float c1 = 1.0f, float c2 = 1, float p_coef = 10000)
        {
            Vector force(get_attraction_force(r.position, location, c1, c2, p_coef));
            r.force = force;
        };
        static void attract_to_location_spring(Vector location, MagnetRocket *r, float ks = 30, float L0 = 0, float dampening = 0.2)
        {

            Vector force(get_spring_force(r->position, location, ks, L0));
            r->force = force - (r->momentum) * dampening; //Add dampening
        }; */
    };
};

} // namespace csl