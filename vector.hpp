#include "vector.h"
#include <cstring>
template<class T>
int Vector<T>::size()
{
    return _size;
}
template<class T>
int Vector<T>::capacity()
{
    return _capacity;
}
template<class T>
Vector<T>::Vector()
{
    _size=0;
    _capacity=0;
    vector=new T[1];
}
template<class T>
Vector<T>::Vector(int __capacity)
{
    _size=0;
    _capacity=0;
    reserve(__capacity);
}
template<class T>
void Vector<T>:: push_back(T x)
{
    if(_size==_capacity)
        reserve(_capacity);
    vector[_size++]=x;
    if(_capacity==0)
        _capacity++;
}
template<class T>
T & Vector<T>::operator [](int x)
{
    T *aux=new T;
    if(x<_capacity && x<_size)
        return vector[x];
    return vector[0];
}
template<class T>
void Vector<T>::reserve(int x)
{
    T *aux=new T[_capacity+x];
    _capacity+=x;
    for(int i=0; i<_size; i++)
        aux[i]=vector[i];
    if (vector != NULL)
        delete [] vector;
    vector=aux;
}
template<class T>
void Vector<T>::insert(T x,int pos)
{
    if(_size==_capacity)
        reserve(_capacity);
    T *aux=new T[_size+1];
    for(int i=0; i<pos; i++)
        aux[i]=vector[i];
    aux[pos]=x;
    for(int i=pos+1; i<=_size; i++)
        aux[i]=vector[i-1];
    delete []vector;
    vector=aux;
    _size++;
}template<class T>
void Vector<T>::erase(int x)
{
    T *aux=new T[_size];
    for(int i=0; i<x; i++)
        aux[i]=vector[i];
    for(int i=x; i<_size-1; i++)
        aux[i]=vector[i]+1;
    _size--;
    delete []vector;
    vector=aux;
}
template<class T>
void Vector<T>::pop_back()
{
    _size--;
}
template<class T>
T* Vector<T>::begin(){
    return &vector[0];
}
template <class T>
T* Vector<T>::end(){
    return &vector[_size];
}

template <class T>
T& Vector<T>::front(){
    return vector[0];
}
template <class T>
T& Vector<T>::back(){
    return vector[_size-1];
}
template <class T>
void Vector<T>::clear(){
    delete []vector;
    _size=_capacity=0;
}
template <class T>
Vector<T> Vector<T>::operator +(Vector<T>aux){
    Vector<T>v(aux.size()+_size);
    v._size=v._capacity;
    for(int i=0;i<_size;i++)
        v[i]=vector[i];
    for(int i=_size;i<_size+aux.size();i++)
        v[i]=aux[i-_size];
    return v;
}

template <class T>
Vector<T> Vector<T>::operator +(int x){
    Vector<T>aux(_size+1);
    aux._size=_size;
    for(int i=0;i<_size;i++)
        aux[i]=vector[i]+x;
    return aux;
}

template <class T>
Vector<T> Vector<T>::operator -(int x){
    Vector<T>aux(_size+1);
    aux._size=_size;
    for(int i=0;i<_size;i++)
        aux[i]=vector[i]-x;
    return aux;
}

template <class T>
Vector<T> Vector<T>::operator /(int x){
    Vector<T>aux(_size+1);
    if(x==0)
        return (*this);
    aux._size=_size;
    for(int i=0;i<_size;i++)
        aux[i]=vector[i]/x;
    return aux;
}
template <class T>
Vector<T> Vector<T>::operator %(int x){
    Vector<T>aux(_size+1);
    if(x==0)
        return (*this);
    aux._size=_size;
    for(int i=0;i<_size;i++)
        aux[i]=vector[i]%x;
    return aux;
}
template <class T>
Vector<T> Vector<T>::operator *(int x){
    Vector<T>aux(_size+1);
    if(x==0)
        return (*this);
    aux._size=_size;
    for(int i=0;i<_size;i++)
        aux[i]=vector[i]*x;
    return aux;
}
template<class T>
void Vector<T>::pop_front(){
    vector++;
    _size--;
    _capacity--;
}
template <class T>
void operator << (std::ofstream & out,Vector<T> v){
    for(int i=0;i<v.size();i++)
        out<<v[i],out<<' ';
    out<<'\n';
}
