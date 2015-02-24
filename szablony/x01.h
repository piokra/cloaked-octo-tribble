#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <iostream>

template <class T> bool defcomp ( T a, T b )
{
	return  a < b;
}

template <class T, bool (*func)(T,T)=defcomp>
class Heap
{
public:
	Heap ( T def )
	{
		m_comp = func;
		m_def = def;
	}

	Heap()
	{
		m_def = T();
		m_comp = func;


	};
	~Heap()
	{

	};
	void push_heap ( T val )
	{
		unsigned pos = m_vec.size();
		m_vec.push_back ( val );
		upheap ( pos );


	}
	T pop_heap()
	{
		return pop_heap ( 0 );
	}
	T pop_heap ( unsigned pos )
	{
		if ( m_vec.size() <= pos ) return m_def;
		T ret = m_vec.at ( pos );
		m_vec->at( pos ) = m_vec->at( m_vec->size() - 1 );
		m_vec.pop_back();

		downheap ( pos );
		return ret;
	}
	void update ( unsigned pos )
	{

		upheap ( pos );
		downheap ( pos );

	}
	unsigned size()
	{
		return m_vec.size();
	}

	
protected:
	void upheap ( unsigned pos )
	{

		while ( 1 )
		{


			if ( pos == 0 ) return;
			if ( pos >= m_vec.size() ) return;
			if ( m_comp ( m_vec.at ( pos ), m_vec.at ( ( pos - 1 ) / 2 ) ) )
			{
				swap ( pos, ( pos - 1 ) / 2 );
				pos = ( ( pos - 1 ) / 2 );
			}
			else
				return;

		}

	}
	void downheap ( unsigned pos )
	{
		//std::cout << pos << std::endl;
		while ( 1 )
		{


			if ( pos >= m_vec.size() ) return;
			if ( m_comp ( left ( pos ), right ( pos ) ) )
			{
				if ( m_comp ( left ( pos ), m_vec.at ( pos ) ) )
				{
					swap ( pos, pos * 2 + 1 );
					pos = ( pos * 2 + 1 );
				}
				else return;
			}
			else
			{
				if ( m_comp ( right ( pos ), m_vec.at ( pos ) ) )
				{
					swap ( pos, pos * 2 + 2 );
					pos = ( pos * 2 + 2 );
				}
				else return;
			}

		}
	}
	T& left ( unsigned pos )
	{
		if ( ( pos * 2 + 1 ) >= m_vec.size() ) return m_def;
		return m_vec.at ( pos * 2 + 1 );
	}
	T& right ( unsigned pos )
	{
		if ( ( pos * 2 + 2 ) >= m_vec.size() ) return m_def;
		return m_vec.at ( pos * 2 + 2 );
	}
	void swap ( unsigned p1, unsigned p2 )
	{
		T temp;
		temp = m_vec.at ( p1 );
		m_vec.at ( p1 ) = m_vec.at ( p2 );
		m_vec.at ( p2 ) = temp;

	}

private:
	std::vector<T> m_vec;
	T m_def;

	bool ( *m_comp ) ( T, T );
};

#endif // HEAP_H
