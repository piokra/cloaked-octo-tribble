/*
	Deklaracje aliasow w C++11
								*/

template <typename T, unsigned X, unsigned Y>
class Macierz
{
public:
	T wartosci[X][Y];
};
template<typename T, unsigned X>
using Wektor = Macierz<T,X,1>;

template<unsigned X>
using WektorR = Macierz<double,X,1>;

int main()
{
	Macierz<double,5,1> a;
	Wektor<double,5> b;
	WektorR<5> c;
	a=b=c;
	return 0;
}
