/*
	Auto
			*/
#include <iostream>
#include <typeinfo>
template <typename T, typename U>
class MojaKlasa
{
};
			
int main()
{
	
	auto a = 7; // auto=int;
	
	a = 7.1;
	auto b = 7.1; // auto = double
	
	MojaKlasa<int,double> c;
	auto d = c; //auto = MojaKlasa<int,double>
	//auto e; blad
	std::cout << typeid(a).name() << std::endl;
	std::cout << typeid(b).name() << std::endl;
	std::cout << typeid(c).name() << std::endl;
	std::cout << typeid(d).name() << std::endl;
}
