#ifndef VECT_H_INCLUDED
#define VECT_H_INCLUDED
#include <fstream>
#include <typeinfo>
template<class T>
class Vector
{
private:
    T *vector;///Vector
    int _size,_capacity;///Current size and capacity
public:
    class iterator;
    const bool container=true;
    int size();///Returns the size of the vector
    int capacity();///Returns the capacity of the vector
    Vector();///Basic construct
    Vector(int __capacity);///Constructor which specifies the initial size of the vector
    void push_back(T x);///Adds x to the end of the vector
    T &operator [](int x);///The x-th element of the vector
    void reserve(int x);///Reserves x more elemnts
    void insert(int pos,T x);///Inserts on pozition pos the element X
    void erase(int x);///Erases the x-th element of the vector
    void erase (iterator it);
    void insert (iterator,T);
    void pop_back();///Erases the last element of the vector
    void pop_front();///Erases the first element
    void clear();///Clears the vectors
    T &back();///Last element
    T &front();///First element
    Vector<T> operator + (Vector<T> aux);///Returns the current elemnts with the elements of aux in the back
    Vector<T> operator * (int x);///Applies *=x to all elements of a Vector;
    Vector<T> operator - (int x);///Applies -=x;
    Vector<T> operator + (int x);///Applies +=x;
    Vector<T> operator / (int x);///Applies /=x;
    Vector<T> operator % (int x);///Applies %=x;
    class iterator
    {
    private:
        T *x;///Pointer to the current value
    public:
        const std::string TypeName=typeid(T*).name();///Name of the pointer's class
        T & operator *();///Returns the value of the pointer
        void operator ++ ();///Goes to the next pointer
        void operator ++ (int);///Postfix
        void operator =(const iterator &);///....(self-exp)
        bool operator !=(const iterator &);///....(self-exp)
        iterator(const T*);///constructor to a pointer
        iterator();///NULL constructor
        using Type=T;
        operator T*();
    };
    using Type=T;///TypeOfElements
    iterator begin();///First position
    iterator end();///Last position
    /// Operators
    bool operator ==(const Vector<T>);
    bool operator = (const Vector<T>);
    bool operator > (const Vector<T>);
    bool operator < (const Vector<T>);
    bool operator >= (const Vector<T>);
    bool operator <= (const Vector<T>);
};
template <class T>
void operator <<(std::ofstream & out,Vector<T> v);///Outputs the vector v to the ofstream out;
#include "vector.hpp"
#endif

