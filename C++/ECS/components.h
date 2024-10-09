struct Position : Component
{
    int x,y,z;
    Position(int x,int y,int z) : x(x),y(y),z(z) {}
    void update() override 
    {
        std::cout<< "Position("<< x <<","<<y<<","<<z<<")";
    }
};
struct Color : Component
{
    int r,g,b;
    Color(int r,int g,int b) : r(r),g(g),b(b) {}
    void update() override 
    {
        std::cout<< "Color("<< r <<","<<g<<","<<b<<")";
    }
};
struct Rotation : Component
{
    int x,y,z;
    Rotation(int x,int y,int z) : x(x),y(y),z(z) {}
    void update() override 
    {
        std::cout<< "Rotation("<< x <<","<<y<<","<<z<<")";
    }
};
