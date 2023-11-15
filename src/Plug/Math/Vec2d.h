
class Vec2d 
{

    double length2() const;
    double length()  const;

    bool operator == (const Vec2d &other);

    Vec2d& operator  = (const Vec2d &other);
    Vec2d& operator += (const Vec2d &other);
    Vec2d& operator -= (const Vec2d &other);
    Vec2d& operator *= (const double scale);
    Vec2d& operator /= (const double scale);

    Vec2d& operator *= (const Vec2d &other);
    Vec2d& operator /= (const Vec2d &other);
};

double dot(const Vec2d &lhs, const Vec2d &rhs);

Vec2d operator + (const Vec2d &vec1, const Vec2d &vec2);
Vec2d operator - (const Vec2d &vec1, const Vec2d &vec2);

Vec2d operator * (const Vec2d &vec, const double scale);
Vec2d operator * (const double scale, const Vec2d &vec);
Vec2d operator * (const Vec2d &lhs,  const Vec2d &rhs);

Vec2d operator / (const Vec2d &vec, const double scale);
Vec2d operator / (const Vec2d &lhs, const Vec2d &rhs);
