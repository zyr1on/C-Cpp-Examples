#include <iostream>
#include <tuple>
#include <utility>
#include <memory>

class Person {
public:
    Person(std::string name, int age) : name(std::move(name)), age(age) {}
    void display() const 
    {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
private:
    std::string name;
    int age;
};

class Car {
public:
    Car(std::string model, int price) : model(std::move(model)), price(price) {}
    void display() const 
    {
        std::cout << "Model: " << model << ", Price: " << price << std::endl;
    }
private:
    std::string model;
    int price;
};

template<typename... TArgs>
class MyTuple {
public:
    MyTuple(MyTuple&& other) noexcept : data(std::move(other.data))  //copy contructor
    {
        std::cout << "MyTuple move constructor called" << std::endl;
    }
    MyTuple& operator=(MyTuple&& other) noexcept                        //copy operator
    {
        if (this != &other)
            data = std::move(other.data);
        return *this;
    }
    template<typename... Args> MyTuple(Args&&... args) : data(std::forward<Args>(args)...) {} // variadic constructor
    
    template<std::size_t index> auto get() const 
    {
        return std::get<index>(data);
    }
private:
    std::tuple<TArgs...> data;
};

int main() {
    MyTuple<Person,Car> mytuple(Person("Semih",22),Car("pagani",3000000));
    mytuple.get<0>().display();
    mytuple.get<1>().display();
    
    std::cout<<"Creating mytuple2"<<"\n";
    
    MyTuple<Person,Car> mytuple2(Person("John Doe",30),Car("agera rs",2500000));
    mytuple2.get<0>().display();
    mytuple2.get<1>().display();
    
    std::cout<<"Copying mytuple to mytuple2";
    mytuple2 = std::move(mytuple);
    std::cout<<"-------------------\n";
    
    std::cout<<"mytuple:\n";
    mytuple.get<0>().display();
    mytuple.get<1>().display();
    
    std::cout<<"mytuple2:\n";
    mytuple2.get<0>().display();
    mytuple2.get<1>().display();
    return 0;
}
