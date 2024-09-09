#include <iostream>
#include <vector>

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
public: tuple() {}
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
    tuple<std::string,std::string,std::string> temp("Year","Length","Name");
    printTuple(temp);

    using component = tuple<int,float,std::string>;
    
    std::vector<component> vec;
    vec.emplace_back(component(1975,97.38,"Seventh Seal"));
    vec.emplace_back(component(1979,161.44,"Stalker"));
    vec.emplace_back(component(1993,131.48,"Naked"));
    vec.emplace_back(component(2011,101.08,"Shame"));
    
    for(auto film : vec) 
       printTuple(film);

    return 0;
}
