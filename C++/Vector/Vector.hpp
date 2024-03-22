#include <iostream>
#include <cstring> 
#include <type_traits>
#include <algorithm>

template<typename T>
struct Vector {
    T* data;
    size_t v_size;
    
    Vector() : data(nullptr), v_size(0) {}
    
    int push_back(T value) {
        T* tempData = new T[v_size + 1];
        if(tempData==nullptr) {
            std::cerr<<"push_back: allocation error or Vector is NULL\n";
            return -1;
        }
        for (size_t i = 0; i < v_size; ++i) tempData[i] = data[i];
        tempData[v_size] = value;
        delete[] data; // after deleted data its not pointing anything;
        data = tempData; // after this actually tempData and data are same;
        v_size++;
        return 0;
    }
    int pop_back() {
        if(v_size == 0 || data==nullptr) {
            std::cerr<<"pop_back: Vector is empty or NULL\n";
            return -1;
        }
        T* tempData = new T[v_size -1];
        for (size_t i = 0; i < v_size-1; ++i) tempData[i] = data[i];
        delete[] data;
        data = tempData;
        v_size--;
        return 0;
    }
    int delete_element(T element) {
        if(v_size == 0 || data==nullptr) {
            std::cerr<<"delete_element: Vector is empty or NULL\n";
            return -1;
        }
        int index = -1;
        int* tempData = new int[v_size -1];
        for(int i=0;i<v_size;i++) {
            if(data[i] == element) {
                index = i;
                break;
            }
        }
        if(index != -1) {
            for(int i=0;i<index;i++)
                tempData[i] = data[i];
            for(int i=index;i<v_size;i++)
                tempData[i] = data[i];
            delete[] data;
            data = tempData;
            v_size--;
            return 0;
        }
        else {
            std::cerr << "vector_delete("<<element<<"): Element not found\n";
            return -1;
        }
    }
    int reverse() {
        if(v_size == 0 || data==nullptr) {
            std::cerr<<"reverse: Vector is empty or NULL\n";
            return -1;
        }
        for(size_t i=0;i<v_size/2;i++) {
            T tempVal = data[i];
            data[i] = data[v_size-1-i];
            data[v_size-1-i] = tempVal;
        }
        return 0;
    }
    int sort() {
        if(v_size == 0 || data==nullptr) {
            std::cerr<<"sort: Vector is empty or NULL\n";
            return -1;
        }
        std::sort(data,data + v_size);
        return 0;
    }
    int print_vector() {
        if(v_size == 0 || data==nullptr) {
            std::cerr<<"print_vector: Vector is empty or NULL\n";
            return -1;
        }
        if(std::is_same_v<T,std::string>)
            for(size_t i=0;i<v_size;i++)
                std::cout << data[i] << "\n";
        else {
            for(size_t i=0;i<v_size;i++)
                std::cout << data[i] << " ";
            std::cout<<"\n";
        }
        return 0;
    }
    int get_last_element() {
        if(v_size == 0 || data==nullptr) {
            std::cerr<<"get_last_element: Vector is empty or NULL\n";
            return -1;
        }
        return data[v_size-1];
    }
    int begin() {
        if(v_size == 0 || data==nullptr) {
            std::cerr<<"begin: Vector is empty or NULL\n";
            return -1;
        }
        return data[0];
    }
    
    ~Vector() {
        delete[] data;
    }
};
