#include "vector.hpp"

int main(int argc, char const *argv[]) {
    Vector<float> float_vec;
    float_vec.push_back(3.14);
    float_vec.push_back(2.71);
    float_vec.push_back(1.0);
    float_vec.print_vector();
    float_vec.fill(0);
    float_vec.print_vector();

    std::cout<<"\n";
    
    Vector<std::string> str_vec;
    str_vec.push_back("hello");
    str_vec.push_back("world");
    str_vec.print_vector();
    str_vec.fill("");
    str_vec.print_vector();
    
    std::cout<<"\n";
    
    Vector<int> int_vec;
    int_vec.push_back(12);
    int_vec.push_back(13);
    int_vec.push_back(5);
    int_vec.print_vector();
    int_vec.reverse();
    int_vec.print_vector();
    int_vec.sort();
    int_vec.print_vector();
    int_vec.fill(0);
    int_vec.print_vector();
    
    return 0;
}
