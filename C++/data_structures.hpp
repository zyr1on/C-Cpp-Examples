#include <iostream>
#define INITIAL_CAPACITY 5

template <typename T>
class Stack_A { // stack with arrays, fast but more memory usage;
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

//		void print() { 
// 			if(empty()) {
// 				std::cout << "stack is empty!\n";
// 				return ;
// 			}
// 			for(int i=0;i<size();i++) std::cout << stack[i]<<" -> ";
// 			std::cout << std::endl;
// 		}
		~Stack() {
			if(stack != nullptr) delete[] stack;
		}
};


template <typename T>
class Stack_L { // stack with nodes, slower but less memory usage;
private:
	struct Node
	{
		Node* next;
		T data;
		Node(T data) : data(data),next(nullptr) {}
		Node() : next(nullptr) {}
	};
	Node* head;
public:
	Stack_l() : head(nullptr) {};
	void push(T data) {
    	Node* newNode = new Node(data);
    	if (!head)
    	    head = newNode;
    	else {
    	    Node* current = head;
    	    while (current->next)
    	        current = current->next;
    	    current->next = newNode; 
    	}
	}
	T pop() {
    	if (!head)
    	    throw std::out_of_range("Stack_l<T>::pop() Stack is empty");
    	if (!head->next) {
    	    delete head;
    	    head = nullptr;
    	}
    	Node* current = head;
    	while (current->next && current->next->next)
    	    current = current->next;
		T temp = current->next->data;
    	delete current->next;  
    	current->next = nullptr;
		return temp;
	}

//	void print() {
//		if (!head)
//    	    throw std::out_of_range("Stack_l<T>::print() Stack is empty");
//		else {
//			Node* current = head;
//			while(current) {
//				std::cout << current->data <<"\n";
//				current = current->next;
//			}
//		}
//		return;
//	}

	bool empty() {
		if(head == nullptr)
			return true;
		return false;
	}
	T peek() {
		if (!head)
    	    throw std::out_of_range("Stack_l<T>::peek() Stack is empty");
		else {
			Node* current = head;
			while(current->next)
				current = current->next;
			return current->data;
		}
	}
	int size() {
		int counter = 0;
		Node* current = head;
		while(current) {
			current = current->next;
			counter++;
		}
		return counter;
	}
	
	~Stack_l() {
		if(!head) {
			while(head) {
				Node* temp = head;
				head = head->next;
				delete temp;
			}	
		}
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

