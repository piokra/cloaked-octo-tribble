#include <iostream>

int main()
{
	int a=0;
	int b=0;
	int c=0;
	int d=0;
	auto lambda1 = [](int a){ return a;};
	auto lambda2 = [&]() { a++; };
	auto lambda3 = [=]()->int{ int z=b; z++; return z;	}; //ok
	// auto lambda4 = [=](){ b++ return b; };
	auto lambda5 = [=]()mutable{ b++; return b; }; // ok
	int s=10;
	while(s--)
	{
		lambda2();
		c = lambda3();
		d = lambda5();
	} 
	std::cout << lambda1(a) << std::endl;
	std::cout << lambda1(b) << std::endl;
	std::cout << lambda1(c) << std::endl;
	std::cout << lambda1(d) << std::endl;
	return 0;
}
