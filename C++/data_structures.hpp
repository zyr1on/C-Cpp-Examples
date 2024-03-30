#include <iostream>
#define INITIAL_CAPACITY 5

template <typename T>
class Stack {
	private:
		int top;
		T* stack;
		int capacity;
	public:
		Stack() : stack(nullptr) , top(0), capacity(INITIAL_CAPACITY) {}
		Stack(int cap) : stack(nullptr),top(0),capacity(cap) {}
		bool empty() {
			if(top == 0 || stack == nullptr) return true;
			return false;
		}
		bool full() {
			if(top == capacity) return true;
			return false;
		}
		void push(T val) {
			if(full()) {
				std::cout << "Stack is full!\n";
				return ;
			}
			if(empty())
				stack = new T[capacity];
			stack[top++] = val;
		}
		T pop() {
			if(top == 0) {
				std::cout << "stack is empty!\n";
				return {}; // return nothing!;
			}
			else
				return stack[--top];
		}
		T peek(){
			return stack[top];
		}
		
		int size() {
			return top;
		}
		void display() {
			if(empty()) {
				std::cout << "stack is empty!\n";
				return ;
			}
			for(int i=0;i<size();i++) std::cout << stack[i]<<" -> ";
			std::cout << std::endl;
		}
		~Stack() {
			if(stack != nullptr) delete[] stack;
		}
};

template <typename T>
class Queue {
	private:
	    struct node {
	        T data;
	        node* next;
	        node(const T& val): data(val), next(nullptr) {}
	    };
	    node* root;
	    node* last;
	public:
	    Queue() : root(nullptr), last(nullptr) {}
	    bool empty(){ if(root == nullptr) return true; return false; }
		void enqueue(const T& val) {
	        if (empty()) {
	            root = new node(val);
	            last = root;
	        } else {
	            last->next = new node(val);
	            last = last->next;
	        }
	    }
	    T dequeue() {
	        if (empty()) {
	            std::cout << "linked list empty!\n";
	            return {};
	        }
	        T rValue = root->data;
	        node* temp = root;
	        root = root->next;
	        delete temp;
	        if (root == nullptr) last = nullptr;
	        return rValue;
	    }
		T front() {
			if(empty()) {
				std::cout << "linked list empty!\n";
				return {};
			}
			return root->data;
		}
		T rear() {
			if(empty()) {
				std::cout << "linked list empty!\n";
				return {};
			}
			return last->data;
		}
		int size() {
			node* temp = root;
			int size = 0;
			while(temp != nullptr){
				temp = temp->next;
				size++;
			}
			return size;
		}
		void display() {
			node* temp = root;
			while(temp != nullptr) {
				std::cout << temp->data << " -> ";
				temp = temp->next;
			}
			std::cout << std::endl;
		}
	    ~Queue() {
	        node* temp = root;
	        while (temp != nullptr) {
	            node* current = temp;
	            temp = temp->next;
	            delete current;
	        }
	    }
};

