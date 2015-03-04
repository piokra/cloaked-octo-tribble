#include <iostream>

template <typename T, typename U>
T _pomnoz(T t, U u)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	return t*u;
}

template <typename T, typename U>
auto pomnoz(T t, U u)->decltype(t*u)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	return t*u;
}

int main()
{
	std::cout << _pomnoz(7,7.1) << std::endl;
	std::cout << pomnoz(7,7.1) << std::endl;
 	return 0;
}
