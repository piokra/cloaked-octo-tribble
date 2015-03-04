#include <iostream>
#include <string>
#include <vector>
template <typename>
class PioFunction;
template <typename R, typename...Args>
class PioFunction<R(Args...)>
{
public:
	virtual R operator()(Args...args){ return R(); };	
};

template <typename>
class StandardFunction;

template <typename R, typename...Args>
class StandardFunction<R(Args...)> : public PioFunction<R(Args...)>
{
	//typedef R(*Function)(Args...);
public:

	StandardFunction(R(*func)(Args...)) {m_function=func;
	}
	virtual R operator()(Args...args)
	{
		return m_function(args...);
	}
private:
	
	R(*m_function)(Args...);
};
template <typename T, typename R, typename...Args>
class ObjectFunction : public PioFunction<R(Args...)>
{
public:
	ObjectFunction(T object) : m_object(object) { }
	virtual R operator()(Args...args) { return m_object(args...);}
private:
	
	T m_object;
};

template <typename R, typename...Args>
StandardFunction<R(Args...)>* generate(R(*function)(Args...))
{
	
	typedef StandardFunction<R(Args...)> Type;
	return new Type(function);
}

template <typename T, typename R, typename...Args>
ObjectFunction<T,R,Args...>* generate(T* obj)
{
	return new ObjectFunction<T,R,Args...>(*obj);	
} 

int func(int x)
{
	return x;
}


int main()
{
	int a = 7;
	PioFunction<int(int)>* function, *function2;
	auto lambda = [=](int x)->int{ return x+a;};
	function2 = generate(func);
	function = generate<decltype(lambda),int,int>(&lambda);
	std::cout << (*function)(10) << " " <<(*function2)(10) << std::endl;	
	return 0;
}
