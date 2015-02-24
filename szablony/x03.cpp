#include <iostream>


template <typename T>
void PrintAll(T t)
{
	std::cout << t << std::endl;
}
template <typename T, typename...Args>
void PrintAll(T t, Args...args)
{
	std::cout << t << " ";
	PrintAll(args...);
}


int main()
{
	PrintAll("yolo","swag",13);
	return 0;
}
