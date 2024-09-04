#include <iostream>

template<typename... Types> class tuple;

template<typename Head,typename... Tail> class tuple<Head,Tail...>  
{
public:
    tuple(Head head,Tail... tail) : head_(head),tail_(tail...) {}
    Head getHead() const {return head_;}
    tuple<Tail...> getTail()const{return tail_;}
private:
    Head head_;
    tuple<Tail...> tail_;
};

template<> class tuple<> 
{
public:
    tuple() {}
};

template<typename... Types> void printTuple(const tuple<Types...>& t) 
{
    printHelper(t);
}
template<typename Head> void printHelper(const tuple<Head>& t) 
{
    std::cout<<t.getHead()<<std::endl;
}
template<typename Head,typename... Tail> void printHelper(const tuple<Head,Tail...>& t) 
{
    std::cout<<t.getHead()<<" , ";
    printHelper(t.getTail());
}

int main() {
    tuple<int,float,std::string,double> temp(1,2.2,"hello world",3.14);
    printTuple(temp);
    return 0;
}
