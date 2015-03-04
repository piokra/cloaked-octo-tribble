#include <iostream>

class MojaKlasa
{
public:
	MojaKlasa(int a) : w(a)
	{
		
	}
	int f()
	{
		return w;
	}
private:
	int w;		
};

int main()
{
	MojaKlasa a(5);
	MojaKlasa b(10);
	int (MojaKlasa::*funkcja)()=&MojaKlasa::f;
	std::cout << (a.*funkcja)() << std::endl;
	std::cout << (b.*funkcja)() << std::endl;
}
