
/*!
	\brief Класс, устанавливающий в какой системе координат находится объект.
*/
class Transform
{
    public:

    Vec2d getOffset () const;
    Vec2d setOffset (const Vec2d &offset);
    
    Vec2d getScale  () const;
    Vec2d setScale  (const Vec2d &scale);

    Vec2d apply     (const Vec2d &vec);
    Vec2d restore   (const Vec2d &vec);

    Transform combine (const Transform &parent_transform);
};