/*
	Typedef i szablony
						*/

template <typename T, unsigned X, unsigned Y>
class Macierz
{
public:
	T wartosc[X][Y];
};

template <typename T, unsigned X>
class Wektor
{
public:
	typedef Macierz<T,X,1> type;
};
template <unsigned X>
class WektorR
{
public:
	typedef Macierz<double,X,1> type;
};
int main()
{
	Macierz<double,5,1> a;
	Wektor<double,5>::type b;
	WektorR<5>::type c;
	a=b;
	b=c;
	
	return 0;
}
