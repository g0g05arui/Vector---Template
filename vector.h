#ifndef VECT_H_INCLUDED
#define VECT_H_INCLUDED
#include <fstream>

template<class T>
class Vector{
	private:
		T *vector;///Vector
		int _size,_capacity;///Current size and capacity
	public:
		int size();///Returns the size of the vector
		int capacity();///Returns the capacity of the vector
		Vector();///Basic construct
        Vector(int __capacity);///Constructor which specifies the initial size of the vector
		void push_back(T x);///Adds x to the end of the vector
		T &operator [](int x);///The x-th element of the vector
		void reserve(int x);///Reserves x more elemnts
		void insert(T x,int pos);///Inserts on pozition pos the element X
		void erase(int x);///Erases the x-th element of the vector
		void pop_back();///Erases the last element of the vector
		void pop_front();///Erases the first element
		void clear();///Clears the vectors
		typedef T * iterator;///Iterator
		iterator begin();///First position
		iterator end();///Last position
		T &back();///Last element
		T &front();///First element
		Vector<T> operator + (Vector<T> aux);///Returns the current elemnts with the elements of aux in the back
		Vector<T> operator * (int x);///Applies *=x to all elements of a Vector;
		Vector<T> operator - (int x);///Applies -=x;
		Vector<T> operator + (int x);///Applies +=x;
		Vector<T> operator / (int x);///Applies /=x;
		Vector<T> operator % (int x);///Applies %=x;
};
template <class T>
void operator <<(std::ofstream & out,Vector<T> v);///Outputs the vector v to the ofstream out;
#include "vector.hpp"
#endif

