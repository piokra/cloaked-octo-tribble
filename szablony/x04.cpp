#include <iostream>
#include <iterator>
template <typename T>
void forEachPtr(T* start, T* end, void (*func)(T*) )
{
	func(start);
	while(start!=end)
	{
		start++;
		func(start);
	}
}
int main()
{
	int array[10]; 
	forEachPtr<int>(&array[0], array+9, [](int* i){*i=i;});
	forEachPtr<int>(array, array+9, [](int* i){std::cout << *i << std::endl;});
}
