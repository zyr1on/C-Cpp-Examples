#include <iostream>
#include <memory>
#include <vector>
#include <typeinfo>


struct Component {
    virtual ~Component() {} 
    virtual void update() = 0;
};

struct Position : public Component 
{
    int x, y, z;
    Position(int x, int y, int z) : x(x), y(y), z(z) {}
    void update() override {
        std::cout << "Position updated: " << x << ", " << y << ", " << z << "\n";
    }
};

struct Color : public Component 
{
    int r, g, b;
    Color(int r, int g, int b) : r(r), g(g), b(b) {}
    void update() override {
        std::cout << "Color updated: " << r << ", " << g << ", " << b << "\n";
    }
};

class Entity 
{
private:
    std::vector<std::unique_ptr<Component>> components;
public:
    template <typename T, typename... Args>
    void addComponent(Args&&... args) 
    {
        components.emplace_back(std::make_unique<T>(std::forward<Args>(args)...));
    }
    template <typename T>
    T* getComponent() {
        for (const auto& component : components)
            if (T* castedComponent = dynamic_cast<T*>(component.get())) 
                return castedComponent;
        return nullptr;
    }
    void updateComponents() 
    {
        for (const auto& component : components)
            component->update();
    }
};

int main() {
    Entity player;
    player.addComponent<Position>(0, 0, 5);
    player.addComponent<Color>(255, 125, 200); 

    player.updateComponents();
    std::cout<< player.getComponent<Color>()->g<<"\n";

    return 0;
}
