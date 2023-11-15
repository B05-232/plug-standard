#ifndef _VEC2D_H_
#define _VEC2D_H_

#include <cmath>

namespace plug {

    class Vec2d 
    {
        public:

        Vec2d(const double coord_x, const double coord_y): x(coord_x), y(coord_y) {}
        Vec2d(): x(0.0), y(0.0) {}

        Vec2d(const Vec2d &src) = default; 


        ~Vec2d() = default;

        double length2() const
        {
            return x * x + y * y; 
        }

        double length() const
        {
            return sqrt(this->length2());
        }


        Vec2d& operator  = (const Vec2d &vec)
        {
            x = vec.x;
            y = vec.y;

            return *this;
        }

        Vec2d& operator += (const Vec2d &vec)
        {
            x += vec.x;
            y += vec.y;

            return *this;
        }

        Vec2d& operator -= (const Vec2d &vec)
        {
            x -= vec.x;
            y -= vec.y;

            return *this;
        }

        Vec2d& operator *= (const Vec2d &vec)
        {
            x *= vec.x;
            y *= vec.y;

            return *this;
        }

        Vec2d& operator /= (const Vec2d &vec)
        {
            x /= vec.x;
            y /= vec.y;

            return *this;
        }

        Vec2d& operator *= (const double val)
        {
            x *= val;
            y *= val;

            return *this;
        }

        Vec2d& operator /= (const double val)
        {
            x /= val;
            y /= val;

            return *this;
        }

        double x;
        double y;

    };

    double dot(const Vec2d &lhs, const Vec2d &rhs)
    {
        return lhs.x * rhs.x + lhs.y * rhs.y;
    }

    double cross(const Vec2d &lhs, const Vec2d &rhs)
    {
        return lhs.x * rhs.y - lhs.y * rhs.x;
    }

    Vec2d normalize(const Vec2d &vec)
    {
        double len = vec.length();
        return vec / len;
    }

    Vec2d operator + (const Vec2d &vec1, const Vec2d &vec2)
    {
        Vec2d res = vec1;
        res += vec2;

        return res;
    }

    Vec2d operator - (const Vec2d &vec1, const Vec2d &vec2)
    {
        Vec2d res = vec1;
        res -= vec2;

        return res;
    }

    Vec2d operator * (const Vec2d &lhs,  const Vec2d &rhs)
    {
        Vec2d res = lhs;
        res *= rhs;

        return res;
    }

    Vec2d operator / (const Vec2d &lhs, const Vec2d &rhs)
    {
        Vec2d res = lhs;
        res /= rhs;

        return res;
    }

    
  

    Vec2d operator * (const Vec2d &vec, const double scale)
    {
        Vec2d res = vec;
        res *= scale;

        return res;
    }

    Vec2d operator * (const double scale, const Vec2d &vec)
    {
        return operator*(vec, scale);
    }

    Vec2d operator / (const Vec2d &vec, const double scale)
    {
        Vec2d res = vec;
        res /= scale;

        return res;
    }
    

   
    

}

#endif