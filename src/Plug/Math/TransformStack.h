class TransformStack
{
    public:

    void enter (const Transform &transform);
    void leave ();
    
    Transform top () const;

    Vec2d apply     (const Vec2d &vec) const; 
    Vec2d restore   (const Vec2d &vec) const;

};