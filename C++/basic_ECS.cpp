// BASIC ECS WITHOUT MEMORY HANDLING
#include <array>
#include <iostream>
#include <memory>

struct Color
{
    int r,g,b;
    Color(int r,int g,int b) : r(r),g(g),b(b) {};
};
struct Position 
{
    int x,y,z;
    Position(int x,int y,int z) : x(x),y(y),z(z) {};
};

using ComponentID = std::size_t;
constexpr ComponentID maxComponents = 32;
using ComponentArray = std::array<void*, maxComponents>;
ComponentID getComponentTypeID() 
{
    static ComponentID lastid = 0;
    return lastid++;
}
template<typename T>
ComponentID getComponentTypeID() 
{
    static ComponentID typeID = getComponentTypeID();
    return typeID;
}

class Entity
{
private:
    ComponentArray components;
public:
    template<typename T>
    void addComponent(T* component) 
    {
        ComponentID id = getComponentTypeID<T>();
        components[id] = component; // T türünde unique_ptr kullanarak ekliyoruz
    }
    template<typename T>
    T* getComponent() 
    {
        ComponentID id = getComponentTypeID<T>();
        return static_cast<T*>(components[id]); // unique_ptr'dan T türünde pointer alıyoruz
    }
};

int main()
{
    Entity player;
    player.addComponent(new Position(0, 0, 5));
    player.addComponent(new Color(255, 125, 200));

    std::cout << player.getComponent<Color>()->b << "\n";
    std::cout << player.getComponent<Position>()->z << "\n";
    return 0;
}
