#include <iostream>

auto f(double t)->double
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	return 0;
}

auto g(int a, double b)->int
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	return 1;
}
auto h(double a, double b)->decltype(a+b)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	return 2;
}


int main()
{
	f(1);
	g(2,3);
	h(3,4);
}
