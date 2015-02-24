#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

template <typename T>
class Inprecise
{
public:
	Inprecise(T t) : m_value(t)
	{
		
	}
	operator T() 
	{
		return m_value;
	}
	bool operator == (const Inprecise<T>& tc) const
	{
		return abs(getValue()-tc.getValue())<0.01;
	}
	const T& getValue()
	{
		return m_value;
	}
private:
	T m_value;			
};

typedef Inprecise<double> InpreciseDouble;

InpreciseDouble operator "" _pd(long double val)
{
	return InpreciseDouble(val);
}



template<typename T,typename...Args>
class variadicContainer
{
public:
	variadicContainer(T t, Args...args) : m_container(args...)
	{
		m_value=t;
	}
	bool operator == (const variadicContainer<T,Args...>& tc) const
	{
		return (m_value==tc.getValue())&&(getContainer()==tc.getContainer());
	}
	
	const T& getValue() const
	{
		return m_value;
	};
	const variadicContainer<Args...>& getContainer() const
	{
		return m_container;
	};
	std::size_t hash() const
	{
		return (((std::hash<T>()(getValue())>>1)^(getContainer().hash()))<<1);
	}
	
	
protected:

	
private:
	T m_value;
	variadicContainer<Args...> m_container;
			
};

template<typename T>
class variadicContainer<T>
{
public:
	variadicContainer(T t)
	{
		m_value=t;
	}	
	const T& getValue() const
	{
		return m_value;
	}
	bool operator ==(const variadicContainer<T>& t) const
	{
		return getValue()==t.getValue();
	}
	std::size_t hash() const
	{
		return (std::hash<T>()(m_value)>>1)<<1;
	}
protected:

private:
	T m_value;
		
	
	
};

namespace std {

  template <>
  template <typename T, typename...Args>
  struct hash<variadicContainer<T,Args...>>
  {
    std::size_t operator()(const variadicContainer<T,Args...>& k) const
    {

      using std::hash;
      return k.hash();
    }
  };

}




template<typename T>
std::stringstream& toss(std::stringstream& stream, T t)
{
	stream << t;
	return stream;
}
template<typename T, typename... Args>
std::stringstream& toss(std::stringstream& stream, T t, Args... args )
{
	

	stream << t;
	toss(stream,args...);
	return stream;
}

template <typename>
class FunctionCacher;

template <typename T, typename...Args>
class FunctionCacher<T(Args...)>
{
	typedef T(*TArgsFunc)(Args...);
public:
	FunctionCacher(TArgsFunc func) : m_func(func)
	{
		
	}
	~FunctionCacher()
	{
		
	}
	
	T operator()(Args...args)
	{
		T ret;
		variadicContainer<Args...> cont(args...);
		auto it = m_cacher.find(cont);
		if(it!=m_cacher.end())
		{
			std::cout << "Arguments found\n" << std::endl;
			ret=it->second;
		}
		else
		{
			std::cout << "Caching value\n" << std::endl;
			ret=m_func(args...);
			m_cacher[cont]=ret;
		}
		return ret;
	}
private:
	
	TArgsFunc m_func;	
	std::unordered_map<variadicContainer<Args...>,int> m_cacher;
};
int retx(int x)
{
	return x;
}

int main()
{

	std::stringstream ss;
	std::string str;
	double d = 4.13;
	auto x = {1,2,3,4,5};
	std::size_t t;
	variadicContainer<int,int,int,int,int,double> a(7,4,55,4,6,4._pd);
	variadicContainer<int,int,int,int,int,int> b(7,4,4,4,6,4);
	std:: cout << a.hash() << std::endl << b.hash() << std::endl;
	FunctionCacher<int(int)> functionCatcher(retx);
	std::cout << functionCatcher(12366) << std::endl;
	std::cout << functionCatcher(12366) << std::endl;
	toss(ss,7,8,9,"banany",d);
	while (ss >> str) std::cout << str << std::endl;
	while (1);
	return 0;

	
}


