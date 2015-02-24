/*

		Przeladowywanie i specyfikacja funkcjii

							    	*/
#include <iostream>
#include <math.h>

template <typename T> bool porownaj(T t1, T t2);
template <typename T> bool porownaj(T* t1, T* t2);
template <> bool porownaj<double>(double t1, double t2);
template <typename T> T wartoscBezwzgledna(T a);


int main()
{
	double a=1,b=1;

	
	std::cout << "&a=&b " << porownaj(&a,&b) << std::endl;
	std::cout << "sqrt2*sqrt2=2 " << porownaj(sqrt(2)*sqrt(2),2.) << std::endl;
	
	
}

template <typename T> /* typename T wymienne na class T (typename jest zdecydowanie bardziej stylowe!) */
bool porownaj(T t1, T t2)
{
	return t1==t2;
}
template <>
bool porownaj<double>(double t1, double t2)
{
	return wartoscBezwzgledna(t2-t1)<0.001; // wybrana mala wartosc
}
template <typename T>
bool porownaj(T* t1, T* t2)
{
	return *t1==*t2;
}

template <typename T>
T wartoscBezwzgledna(T a)
{
	return a>0?a:-a;
}
