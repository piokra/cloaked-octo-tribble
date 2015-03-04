#include <iostream>

class MojaKlasa
{
public:
	int a;
};


int main()
{
	MojaKlasa a = {1};
	int* wsk1 = &a.a;
	int MojaKlasa::*wsk2 = &MojaKlasa::a;
	std::cout << *wsk1 << std::endl;
	std::cout << a.*wsk2 << std::endl;	
	return 0;
}
