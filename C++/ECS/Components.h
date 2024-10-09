struct Component
{
    virtual ~Component() {}
    virtual void update() = 0;
};

struct Color : Component
{
    int r,g,b,a;
    Color(int r,int g,int b,int a) : r(r),g(g),b(b),a(a) {}
    void update() override
    {
        std::cout<<"Color("<<r<<","<<g<<","<<b<<","<<","<<a<<")";
    }
};

struct Position : Component
{
    int x,y,z;
    Position(int x,int y,int z) : x(x),y(y),z(z) {}
    void update() override
    {
        std::cout<<"Position("<<x<<","<<y<<","<<z<<")";
    }
};

struct Rotation : Component
{
    int x,y,z;
    Rotation(int x,int y,int z) : x(x),y(y),z(z) {}
    void update() override
    {
        std::cout<<"Rotation("<<x<<","<<y<<","<<z<<")";
    }
};
