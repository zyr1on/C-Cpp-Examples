#include <iostream>
#include <algorithm>
template <typename T>
class Vector {
	public:
		Vector() {
			size_vec = 0;
			this->capacity = 5;
			vector = new T[5];
		}
		Vector(int cap) {
			size_vec = 0;
			this->capacity = cap;
			vector = new T[cap];
		}
		int push_back(T element) {
			if (vector == nullptr || capacity == 0) {
            	std::cerr << "push_back: Vector is null or empty\n";
            	return -1;
        	}
			if(size_vec >= capacity) {
				resize(capacity *2);
				vector[size_vec] = element;
				size_vec++;
			}
			else {
				vector[size_vec] = element;
				size_vec++;
			}
			return 0;
		}
		int print_vector() {
			if (vector == nullptr || size_vec == 0 || capacity == 0) {
            	std::cerr << "print_vector: Vector is null or empty\n";
            	return -1;
        	}
			if(!std::is_same_v<T,std::string>) {
				std::cout << "[";
				for(int i=0;i<size_vec;i++)
					if(i!=size_vec-1)
						std::cout << vector[i] << ",";
					else
						std::cout << vector[i] << "]\n";
			}
			else {
				std::cout << "[";
				for(int i=0;i<size_vec;i++)
					if(i!=size_vec-1)
						std::cout << "'"<<vector[i]<<"'" << ",";
					else
						std::cout << "'"<<vector[i]<<"'" << "]\n";
			}
			return 0;
		}
		int pop_back() {
			if (vector == nullptr || size_vec == 0 || capacity == 0) {
            	std::cerr << "pop_back: Vector is null or empty\n";
            	return -1;
        	}
			T* tempData = new T[capacity];
			size_vec--;
			for(int i=0;i<size_vec;i++)
				tempData[i] = vector[i];
			delete[] vector;
			vector = tempData;
			return 0;
		}
		int delete_element(T element) {
			if(!control("delete_element"))
				return -1;
			int index=-1;
			for(int i=0;i<size_vec;i++) {
				if(vector[i] == element) {
					index=i;
					break;
				}
			}
			if(index != -1) {
				T* tempData = new T[capacity];
				for(int i=0;i<index;i++)
					tempData[i] = vector[i];
				for(int i=index;i<size_vec;i++)
					tempData[i] = vector[i];
				delete[] vector;
				vector = tempData;
				size_vec--;
			}
			else {
				std::cerr<<"Element not found!\n";
				return -1;
			}
			return 0;
		}
		int sort() {
			if(!control("sort"))
				return -1;
			std::sort(vector,vector+size_vec);
			return 0;
		}
		size_t size() {
			return size_vec;
		}
		size_t get_capacity() {
			return capacity;
		}
		T get_last_element() {
			return vector[size_vec-1];
		}
		bool empty() {
			if(size_vec == 0 ||capacity == 0) {
				return true;
			}
			else {
				return false;
			}
		}
		int status()  {
			if(control("status")) {
				std::cout << "Vector size: "<<size_vec<<"\n";
				std::cout << "Vector capacity: "<<capacity<<"\n";
				std::cout << "Vector rate: %"<< (float)size_vec / (float)capacity*100 <<"\n";
				std::cout << "Vector address: "<<vector<<"\n";
				return 0;
			}
			else {
				return -1;
			}
		}
		int reverse() {
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
		int begin() {
			if(!control("begin"))
				return -1;
			return vector[0];
		}
		int end() {
			if(!control("end"))
				return -1;
			return vector[size_vec-1];
		}
		~Vector() {
			delete[] vector;
			vector = nullptr;
			size_vec = 0;
			capacity = 0;
		}
	private:
		T* vector;
		size_t size_vec;
		size_t capacity;
		void resize(int size) {
			T* tempData = new T[size];
			for(int i=0;i<this->size_vec;i++)
				tempData[i] = vector[i];
			delete[] vector;
			vector = tempData;
			this->capacity = size;
		}
		bool control(const char* name_) {
			if (vector == nullptr || size_vec == 0 || capacity == 0) {
            	std::cerr << name_ <<": Vector is null or empty\n";
            	return false;
        	}
			return true;
		}
	
};
