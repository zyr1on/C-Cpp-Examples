#include <iostream>
#include <memory>
#include <vector>

struct Component 
{
    virtual ~Component() {}
    virtual void update() = 0;
};
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

class Entitiy 
{
private:
    std::vector<std::unique_ptr<Component>> components;
public:
    template<typename T,typename... Args>
    void addComponent(Args&&... args) 
    {
        components.emplace_back(std::make_unique<T>(std::forward<Args>(args)...));
    }
    template<typename T>
    T* getComponent() 
    {
        for(const auto& component : components)
            if(T* casted_component = dynamic_cast<T*>(component.get()))
                return casted_component;
        return nullptr;
    }
};

int main() 
{
    Entitiy player;
    player.addComponent<Position>(0,15,25);
    std::cout<<player.getComponent<Position>()->y<<"\n";

    return 0;
}
