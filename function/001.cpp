#include <functional>
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

int mojaFunkcja(int a, std::function<int(int)> funkcja)
{
	return funkcja(a);
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
	std::cout << mojaFunkcja(5,dodaj10) << std::endl; 
	std::cout << mojaFunkcja(5,lambda2) << std::endl; 

	
	
}
