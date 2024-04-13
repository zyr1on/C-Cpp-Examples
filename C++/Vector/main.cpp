#include "vectors.hpp"

int main(int argc, char const *argv[]) {    
    Vector<int> int_vec;
    int_vec.push_back(13);
    int_vec.push_back(-12);
    int_vec.push_back(18);
    // int_vec.print_vector() or std::cout << vector;
    std::cout << int_vec <<" ";
    int_vec.reverse();              // reverse int vector;
    std::cout << int_vec <<" ";
    int_vec.sort();                 // sorts int vector
    std::cout << int_vec <<" ";
    int_vec.assign(18,13);          // assigns old element(right) to new element(left)
    std::cout << int_vec <<" ";
    int_vec.delete_element(13);     // deletes given element (13)
    std::cout << int_vec <<" ";
    int_vec.pop_back();             // pops last element!
    std::cout << int_vec <<" ";
    int_vec.fill(0);                // fills "all" values with given value! (0)
    std::cout << int_vec <<"\n";
    int_vec.status();
    std::cout <<"\n";

    Vector<std::string> string_vec;
    // reverse,sort,delete,pop,push_back,fill, index_at
    string_vec.push_back("hello");
    string_vec.push_back("world");
    std::cout << string_vec <<" ";
    string_vec.assign("world","hi");
    std::cout << string_vec <<"\n";
    std::cout << "hi is index at:"<<string_vec.index_at("hi")<<"\n";
    string_vec.status();
    string_vec.~Vector();           // deconstructor!

    return 0;
}
