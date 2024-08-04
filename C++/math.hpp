#include <iostream>
#include <cmath>

namespace Math
{
    struct complex 
    {
        long double real;
        long double im;
        complex(): im(0),real(0) {}
        complex(long double real, long double im): im(im),real(real) {}

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
        complex conj() {
            return {this->real, -1*this->im};
        }
        
        friend std::ostream& operator<<(std::ostream& os, complex& other) {
            if(other.im < 0 && other.real < 0 || other.im < 0 && other.real>= 0)
                os << other.real<<other.im<<"i";
            else os << other.real <<"+"<<other.im<<"i";    
            return os;
        }
        long double magnitude() 
        {
            return sqrt(this->real*this->real + this->im*this->im);
        }
        long double arg() {
            return atan2(this->im,this->real);
        }
        // make polar form complex struct
    };
} // namespace Math
