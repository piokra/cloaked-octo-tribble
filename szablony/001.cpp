/*

		Funkcje szablonowe

								*/

#include <iostream>
#include <math.h>

template <typename T> /* typename T wymienne na class T (typename jest zdecydowanie bardziej stylowe!) */
bool porownaj(T t1, T t2)
{
	return t1==t2;
}

template <int l, int p>
int pomnoz()
{
	return l*p;
}

int main()
{
	double a=1,b=1;
	int c=0, d=1;
	int siedem=7;
	
	std::cout << "a=b " << porownaj(a,b) << std::endl;
	std::cout << "c=d " << porownaj(c,d) << std::endl;
	std::cout << "'a'='b' " << porownaj('a','b') << std::endl;
	//std::cout << porownaj(1,1.f) << std::endl; Nie poprawne
	std::cout << "(int)'a'=(int)7123123.3333 " << porownaj<int>('a',7123123.3333) << std::endl; 
	std::cout << "&a=&b " << porownaj(&a,&b) << std::endl;
	std::cout << "sqrt2*sqrt2=2 " << porownaj(sqrt(2)*sqrt(2),2.) << std::endl;
	
	
	std::cout << "7*7 = " << pomnoz<7,7>() << std::endl;
	//std::cout << pomnoz<siedem,siedem>() << std::endl; Nie poprawne
	
	
}
