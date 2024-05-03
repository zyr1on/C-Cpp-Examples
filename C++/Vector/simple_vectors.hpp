#include <iostream>
#include <initializer_list>

#define INITIAL_CAPACITY 5 // YOU CAN CHANGE HERE!
template <typename T>
class Vector {
	public:
		Vector() {
			size_vec = 0;
			this->capacity = INITIAL_CAPACITY;
			vector = new T[INITIAL_CAPACITY];
		}
		Vector(std::initializer_list<T> args) : size_vec(args.size()) , capacity(args.size()*2) {
			vector = new T[capacity];
			size_t i = 0;
			for(const auto& element : args) {
				vector[i++] = element;
			}
		}
		Vector(size_t cap) {
			size_vec = 0;
			this->capacity = cap;
			vector = new T[cap];
		}
		int push_back(T element) {
			if (vector == nullptr) {
            	std::cerr << "push_back: Vector is null\n";
            	return -1;
        	}
			if(size_vec >= capacity) {
				if(resize(capacity * 1.5) != 0) {
					std::cerr << "push_back: Resize operation failed\n";
					return -1;
				}
			}
			vector[size_vec++] = element;
			return 0;
		}
		int pop_back(void) {
			if (vector == nullptr || size_vec == 0 || capacity == 0) {
            	std::cerr << "pop_back: Vector is null or empty\n";
            	return -1;
        	}
			T* tempData = new T[capacity];
			if(tempData == nullptr) {
				std::cerr << "resize: Memory allocation failed!\n";
				return -1;
			}
			size_vec--;
			for(int i=0;i<size_vec;i++)
				tempData[i] = vector[i];
			delete[] vector; // deleting vector;
			vector = tempData;
			return 0;
		}
		size_t size(void) {
			return size_vec;
		}
		size_t get_capacity(void) {
			return capacity;
		}
		bool empty(void) {
			if(size_vec == 0 ||capacity == 0) {
				return true;
			}
			else {
				return false;
			}
		}
		int status(void)  {
			if(control("status")) {
				std::cout << "Vector size: "<<size_vec<<"\n";
				std::cout << "Vector capacity: "<<capacity<<"\n";
				std::cout << "Vector rate: %"<< (float)size_vec / (float)capacity*100 <<"\n";
				return 0;
			}
			else {
				return -1;
			}
		}
		int reverse(void) {
			if(!control("reverse"))
				return -1;
			for(int i=0;i<size_vec/2;i++) {
				T temp = vector[i];
				vector[i] = vector[size_vec -i -1];
				vector[size_vec-i-1] = temp;
			}
			return 0;
		}
		int fill(T value) {
			if(!control("fill"))
				return -1;
			for(int i=0;i<size_vec;i++) {
				vector[i] = value;
			}
			return 0;
		}
		~Vector() {
    		if (vector != nullptr) {
        		delete[] vector;
        		vector = nullptr;
    		}
    		size_vec = 0;
    		capacity = 0;
		}
		
		T* begin() const {return vector;}
		T* end() const {return vector + size_vec;}
		T& operator[](size_t index) {
			if(size_vec == 0) {
				throw std::empty("vector empty!");	
			}
			if(index >= size_vec)
				throw std::out_of_range("Index out of range!");
			return vector[index];
		}
	private:
		T* vector;
		size_t size_vec;
		size_t capacity;
		int resize(size_t size) {
			T* tempData = new T[size];
			if(tempData == nullptr) {
				std::cerr << "resize: Memory allocation failed!\n";
				return -1;
			}
			for(int i=0;i<this->size_vec;i++)
				tempData[i] = vector[i];
			delete[] vector;
			vector = tempData;
			this->capacity = size;
			return 0;
		}
		bool control(const char* name_) {
			if (vector == nullptr || size_vec == 0 || capacity == 0) {
            	std::cerr << name_ <<": Vector is null or empty\n";
            	return false;
        	}
			return true;
		}		
};
