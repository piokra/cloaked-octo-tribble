/*
	Decltype
			*/
#include <iostream>
#include <typeinfo>

template <typename T>
class Klasa
{
public:
	typedef T type;
};
			
int main()
{
	auto a = 7; // auto=int;
	auto b = 7.1; // auto = double
	
	decltype(a+b) c;
	decltype(b+a) d;
	decltype(d) e;
	Klasa<int> klasa;
	decltype(klasa)::type integer;
	std::cout << typeid(a).name() << std::endl;
	std::cout << typeid(b).name() << std::endl;
	std::cout << typeid(c).name() << std::endl;
	std::cout << typeid(d).name() << std::endl;
	std::cout << typeid(e).name() << std::endl;
}
