/*
	
	Klasy szablonowe
						*/
						
#include <iostream>

template <typename T>
class Pojemnik
{
public:
	Pojemnik<T>()
	{
		
	}
	Pojemnik<T>(T t) : wartosc(t)
	{
		
	}
	~Pojemnik()
	{
		
	}
	T wezWartosc()
	{
		return wartosc;
	}
	void ustawWartosc(T t)
	{
		wartosc=t;
	}
private:
		
	T wartosc;	
};
template <typename T>
class Pojemnik<T*>
{
public:
	Pojemnik<T*>()
	{
		
	}
	Pojemnik<T*>(T* t) : wartosc(t)
	{
		
	}
	~Pojemnik()
	{
		
	}
	T wezWartosc()
	{
		return *wartosc;
	}
	void ustawWartosc(T* t)
	{
		wartosc=t;
	}
private:
		
	T* wartosc;	
};
template <> int Pojemnik<int>::wezWartosc() { return wartosc+7; }
template <>
class Pojemnik<double>;


template <unsigned i>
class Fibonacci
{
public:
	static const unsigned wartosc=Fibonacci<i-1>::wartosc+Fibonacci<i-2>::wartosc;		
};
template <>
class Fibonacci<1>
{
public:
	static const unsigned wartosc=1;
};
template <>
class Fibonacci<0>
{
public:
	static const unsigned wartosc=0;
};



int main()
{
	//Pojemnik a(7); nie poprawne
	//Pojemnik<void> blad;
	double siedem=7;
	Pojemnik<int> a(7);
	Pojemnik<double*> b(&siedem);
	siedem=8;
	std::cout << b.wezWartosc() << std::endl;
	std::cout << a.wezWartosc() << std::endl;
	std::cout << Fibonacci<10>::wartosc << std::endl;
}


