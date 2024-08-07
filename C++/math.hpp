#include <iostream>
#include <cmath>
#include <random>

namespace Math
{
    long double randomReal(long double min=0,long double max=1) {
        static std::random_device rseed;
        static std::mt19937 rng(rseed());
        std::uniform_real_distribution<long double> dist(min,max);
        return dist(rng);
    }
    
    long int randomInt(long int min=0,long int max=1) {
        static std::random_device rseed;
        static std::mt19937 rng(rseed());
        std::uniform_int_distribution<long int> dist(min,max);
        return dist(rng);
    }

    template <typename T>
    struct Vector2{
        T x;
        T y;
        Vector2() : x(0),y(0) {}
        Vector2(T x,T y) : x(x),y(y) {}
        Vector2 operator+(const Vector2& other) {
            return { this->x + other.x , this->y + other.y };
        }
        Vector2 operator-(const Vector2& other) {
            return { this->x - other.x , this->y - other.y };
        }
        void operator=(const Vector2& other) {
            this->x = other.x;
            this->y = other.y;
        }
        bool operator==(const Vector2& other) {
            if(this->x == other.x && this->y == other.y)return true;
            return false;
        }
        bool operator!=(const Vector2& other) {
            if(this->x == other.x && this->y == other.y)return false;
            return true;
        }
        friend std::ostream& operator<<(std::ostream& os, Math::Vector2<T>& other) {
            os << "("<<other.x<<","<<other.y<<")";  
            return os;
        }
        T magnitude() 
        {
            return sqrt(this->x*this->x + this->y*this->y);
        }
        T norm() {
            return this->x*this->x + this->y*this->y;
        }
    };
    
    template <typename T>
    struct complex 
    {
        T real;
        T im;
        complex(): im(0),real(0) {}
        complex(T real, T im): im(im),real(real) {}

        complex operator+(const complex& other) {
            return {this->real + other.real , this->im + other.im};
        }
        complex operator-(const complex& other) {
            return {this->real - other.real , this->im - other.im};
        }
        complex operator*(const complex& other) {
            return {this->real*other.real - this->im*other.im, this->real*other.im + this->im*other.real};
        }
        complex operator/(const complex& other) { //check
            long double denominator = other.real * other.real + other.im * other.im;
            if (denominator == 0)
                throw std::runtime_error("Division by zero");
            return {(this->real*other.real + this->im*other.im) / (other.real*other.real + other.im *other.im), (this->im*other.real - this->real*other.im) / (other.real*other.real + other.im *other.im)};
        }
        bool operator==(const complex& other) 
        {
            if(this->real == other.real && this->im == other.im)return true;
            return false;
        }
        bool operator!=(const complex& other) 
        {
            if(this->real == other.real && this->im == other.im)return false;
            return true;
        }
        void operator=(const complex& other) 
        {
            this->real = other.real;
            this->im = other.im;
        }
        T norm() 
        {
            return this->real*this->real + this->im*this->im;
        }
        complex conj() 
        {
            return {this->real, -1*this->im};
        }
        T magnitude() 
        {
            return sqrt(this->real*this->real + this->im*this->im);
        }
        T arg() {
            return atan2(this->im,this->real);
        }
        friend std::ostream& operator<<(std::ostream& os, Math::complex<T>& other) {
            if(other.im < 0 && other.real < 0 || other.im < 0 && other.real>= 0)
                os << other.real<<other.im<<"i";
            else os << other.real <<"+"<<other.im<<"i";    
            return os;
        }
        // make polar form complex struct
    };
} // namespace Math


