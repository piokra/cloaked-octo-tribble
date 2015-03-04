#include <iostream>

class ObiektFunkcyjny
{
public:
	ObiektFunkcyjny(int a) : x(a) 
	{
	}
	int operator()(int a) 
	{ 
		return a+x;
	}
private:
	int x;
	
};

int mojaFunkcja(int a, int (*funkcja)(int))
{
	return funkcja(a);
}
template<int(*funkcja)(int)>
int mojaFunkcja2(int a)
{
	return funkcja(a);
}
template<typename T>
int mojaFunkcja3(int a, T t)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	return t(a);
}
int dodaj5(int a)
{
	return a+5;
}
int main()
{
	int piec=5;
	auto lambda1 = [](int a){ return a+1; };
	auto lambda2 = [=](int a) { return a+piec; };
	auto dodaj10 = ObiektFunkcyjny(10);
	std::cout << mojaFunkcja(5,dodaj5) << std::endl; //ok
	std::cout << mojaFunkcja(5,lambda1) << std::endl; // ok
	//std::cout << mojaFunkcja(5,dodaj10) << std::endl; blad
	//std::cout << mojaFunkcja2<lambda1>(5) << std::endl; parametr szablonu
	// lambda jest rzutowana na int(*)(int)
	//std::cout << mojaFunkcja(5,lambda2) << std::endl; lambda z niepustymi opcjami chwytania nie
	// moze byc rzutowana na int(*)(int)
	std::cout << mojaFunkcja3(5,lambda1) << std::endl;
	std::cout << mojaFunkcja3(5,lambda2) << std::endl;
	std::cout << mojaFunkcja3(5,dodaj5) << std::endl;
	std::cout << mojaFunkcja3(5,dodaj10) << std::endl;
	
	
}
