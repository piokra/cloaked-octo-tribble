
#include <iostream>
int x;
auto hello2 = []()->int{};
auto hello3 = []()->int{return 1;};
template <typename T>
void greetings(T t)
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}


int main()
{
	auto hello4=hello2;
	decltype(hello3) t = hello3;
	greetings(hello2);
	greetings(hello3);
	return 0;
}
