#include "vector.h"
#include <cstring>
#include <string>
#include <typeinfo>
template<class T>
int Vector<T>::size()const
{
    return _size;
}
template<class T>
int Vector<T>::capacity()const
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
    if(x<_capacity && x<_size)
        return vector[x];
    return vector[this->_size-1];
}
template<class T>
void Vector<T>::reserve(int x)
{
    T *aux=new T[_capacity+x];
    _capacity+=x;
    for(int i=0; i<_size; i++)
        aux[i]=vector[i];
    delete[]vector;
    vector=aux;
}
template<class T>
void Vector<T>::insert(int pos,T x)try
{
    if(pos>=_capacity)
        throw(1);
    T *aux=new T[_capacity*2];
    for(int i=0; i<pos; i++)
        aux[i]=vector[i];
    aux[pos]=x;
    for(int i=pos+1; i<=_size; i++)
        aux[i]=vector[i-1];
    delete []vector;
    vector=aux;
    _size++;
    _capacity*=2;
}catch(int error){
    return ;
}
template<class T>
void Vector<T>::erase(int x)try
{
    if(x<0 || x>capacity())
        throw (1);
    T *aux=new T[_capacity];
    for(int i=0; i<x; i++)
        aux[i]=vector[i];
    for(int i=x; i<_size-1; i++)
        aux[i]=vector[i]+1;
    _size--;
    delete []vector;
    vector=aux;
}
catch(int error){
    return;
}
template<class T>
void Vector<T>::pop_back()
{
    _size=std::max(0,_size-1);
}
template<class T>
typename Vector<T>::iterator Vector<T>::begin()
{
    return (iterator)
    {
        &vector[0]
    };
}
template <class T>
typename Vector<T>::iterator  Vector<T>::end()
{
    return (iterator)
    {
        &vector[size()-1]+1
    };
}

template <class T>
T& Vector<T>::front()
{
    return vector[0];
}
template <class T>
T& Vector<T>::back()
{
    return vector[_size-1];
}
template <class T>
void Vector<T>::clear()
{
    delete []vector;
    _size=_capacity=0;
}
template <class T>
Vector<T> Vector<T>::operator +(Vector<T>aux)
{
    Vector<T>v(aux.size()+_size);
    v._size=v._capacity;
    for(int i=0; i<_size; i++)
        v[i]=vector[i];
    for(int i=_size; i<_size+aux.size(); i++)
        v[i]=aux[i-_size];
    return v;
}

template <class T>
Vector<T> Vector<T>::operator +(int x)
{
    Vector<T>aux(_size+1);
    aux._size=_size;
    for(int i=0; i<_size; i++)
        aux[i]=vector[i]+x;
    return aux;
}

template <class T>
Vector<T> Vector<T>::operator -(int x)
{
    Vector<T>aux(_size+1);
    aux._size=_size;
    for(int i=0; i<_size; i++)
        aux[i]=vector[i]-x;
    return aux;
}

template <class T>
Vector<T> Vector<T>::operator /(int x)
{
    Vector<T>aux(_size+1);
    if(x==0)
        return (*this);
    aux._size=_size;
    for(int i=0; i<_size; i++)
        aux[i]=vector[i]/x;
    return aux;
}
template <class T>
Vector<T> Vector<T>::operator %(int x)
{
    Vector<T>aux(_size+1);
    if(x==0)
        return (*this);
    aux._size=_size;
    for(int i=0; i<_size; i++)
        aux[i]=vector[i]%x;
    return aux;
}
template <class T>
Vector<T> Vector<T>::operator *(int x)
{
    Vector<T>aux(_size+1);
    if(x==0)
        return (*this);
    aux._size=_size;
    for(int i=0; i<_size; i++)
        aux[i]=vector[i]*x;
    return aux;
}
template<class T>
void Vector<T>::pop_front()
{
    vector++;
    _size--;
    _capacity--;
}
template <class T>
void operator << (std::ofstream & out,Vector<T> v)
{
    for(int i=0; i<v.size(); i++)
        out<<v[i],out<<' ';
    out<<'\n';
}

template<class T>
T & Vector<T>::iterator::operator *()
{
    return *x;
}
template<class T>
void Vector<T>::iterator::operator =(const Vector<T>::iterator & it)
{
    x=it.x;
}

template<class T>
bool Vector<T>::iterator::operator !=(const Vector<T>::iterator & it)
{
    return (x!=it.x);
}

template<class T>
void Vector<T>::iterator::operator ++ ( int )
{
    x++;
}

template<class T>
Vector<T>::iterator::iterator(const T * aux)
{
    x=(T*)aux;
}
template<class T>
Vector<T>::iterator::iterator()
{
    x=0;
}

template<class T>
bool Vector<T>::operator == (Vector<T>  v)
{
    if(v.size()!=this->size())
        return 0;
    for(int i=0; i<v.size(); i++)
        if(v[i]!=vector[i])
            return 0;
    return 1;
}

template<class T>
bool Vector<T>::operator = (Vector<T>  v)
{
    delete []vector;
    _size=v.size();
    this->_capacity=v.capacity();
    vector = new T[_capacity];
    for(int i=0; i<_size; i++)
        vector[i]=v[i];
    return 1;
}

template<class T>
bool Vector<T>::operator > (Vector<T> v)
{
    if(v.size()<this->size())
        return 1;
    if(v.size()>this->size())
        return 0;
    for(int i=0; i<this->size(); i++)
        if(vector[i]>v[i])
            return 1;
        else if(vector[i]<v[i])
            return 0;
    return 0;
}

template<class T>
bool Vector<T>::operator < (Vector<T> v)
{
    return (v>*this);
}

template<class T>
bool Vector<T>::operator >= (Vector<T> v)
{
    return (*this>v || *this==v);
}

template<class T>
bool Vector<T>::operator <= (Vector<T> v)
{
    return (*this<v || *this==v);
}

template<class T>
void Vector<T>::erase (const Vector<T>::iterator & it)
{
    erase((int) (it-begin()));
}

template<class T>
Vector <T>::iterator::operator T*()
{
    return x;
}

template<class T>
void Vector<T>::insert (const Vector<T>::iterator &it,T x)
{

    insert((int)((T *)it-(T *)begin()),x);
}

template<class T>
T & Vector<T>::reverse_iterator::operator *()
{
    return *x;
}

template<class T>
void Vector<T>::reverse_iterator::operator ++()
{
    x--;
}

template<class T>
void Vector<T>::reverse_iterator::operator++(int)
{
    x--;
}

template<class T>
const typename Vector<T>::iterator Vector<T>::cbegin()
{
    return (iterator)
    {
        &vector[0]
    };
}

template<class T>
const typename Vector<T>::iterator Vector<T>::cend()
{
    return end();
}

template<class T>
T * Vector<T>::data(){
    return this->vector;
}

template<class T>
typename Vector<T>::reverse_iterator Vector<T>::rbegin(){
     return (reverse_iterator)
    {
        &vector[size()-1]
    };
}

template<class T>
typename Vector<T>::reverse_iterator Vector<T>::rend(){
     return (reverse_iterator)
    {
        vector-1
    };
}


template<class T>
Vector<T>::reverse_iterator::reverse_iterator(const T* aux){
    this->x=(int*)aux;
}

template<class T>
void Vector<T>::reverse_iterator::operator =(const Vector<T>::reverse_iterator &it){
    this->x=(int *)it.x;
}

template<class T>
bool Vector<T>::reverse_iterator::operator !=(const Vector<T>::reverse_iterator & it){
    return (this->x != it.x);
}

template<class T>
Vector<T>::reverse_iterator::reverse_iterator(){

}

template<class T>
Vector<T>::Vector(const Vector<T> & v2){
    _capacity=0;
    _size=v2.size();
    reserve(v2.capacity()+1);
    for(int i=0;i<_size;i++)
        vector[i]=v2.vector[i];
}

template<class T>
T & Vector<T>::at(int x){
    return this->operator[](x);
}

template<class T>
void Vector<T>::shrink_to_fit(){
    T * aux = new T[size()];
    for(iterator it=begin();it!=end();++it)
        aux[(int)(it-begin())]=*it;
    delete[]this->vector;
    this->vector=aux;
    this->_capacity=this->_size;
}

template<class T>
Vector<T>::Vector(T* begin,T* end){
    this->vector= new T [(int)(end-begin)+1];
    this->_capacity=(int)(end-begin)+1;
    for(this->_size=0;begin!=end;++begin,this->_size++)
        this->vector[this->_size]=*begin;
}

template<class T>
Vector<T>::Vector(std::initializer_list<T> il){
    this->vector=new T[il.size()];
    this->_capacity=il.size();
    this->_size=0;
    for(auto it=il.begin();it!=il.end();++it)
        this->vector[this->_size++]=*it;
}

template<class T>
Vector<T>::Vector(int num,T aux){
    this->vector=new T[num];
    this->_capacity=num;
    this->_size=0;
    for(int i=0;i<num;i++)
        this->vector[_size++]=aux;
}

template<class T>
Vector<T>::~Vector(){
    delete[]this->vector;
    _size=0;
    _capacity=0;
}

template<class T>
std::string Vector<T>::name_()const{
    std::string name="Vector";
    name+=" ";
    name+=typeid(T()).name();
    return name;
}

template<class T>
void Vector<T>::resize(int size){
    if(size<=this->_size){
        this->_size=size;
        return ;
    }
    for(int i=_size;i<size;i++)
        this->push_back(T());
}

template<class T>
void Vector<T>::resize(int size,T val){
    if(size<=this->_size){
        this->_size=size;
        return ;
    }
    for(int i=_size;i<size;i++)
        this->push_back(val);
}

template<class T>
void Vector<T>::assign(std::initializer_list<T>il){
    this->clear();
    this->vector=new T[il.size()];
    this->_capacity=il.size();
    for(auto it=il.begin();it!=il.end();it++)
        this->vector[_size++]=*it;
}

template<class T>
void Vector<T>::assign(int size,const T & val){
    this->clear();
    this->vector=new T[size];
    this->_capacity=size;
    for(int i=0;i<size;i++)
        this->vector[_size++]=val;
}

template<class T>
template<class InpIterator>void Vector<T>::assign(InpIterator a,InpIterator b){
    this->clear();
    for(InpIterator c=a;c!=b;c++)
        this->push_back(*c);
}

template<class T>
bool Vector<T>::operator = (std::initializer_list<T> il){
    this->assign(il);
    return 1;
}

template<class T>
void Vector<T>::swap(Vector<T> & aux){
    T * ap=this->vector;
    int size_=this->_size,capacity_=this->_capacity;
    this->vector=aux.vector;
    aux.vector=ap;
    this->_size=aux._size;
    aux._size=size_;
    this->_capacity=aux._capacity;
    aux._capacity=capacity_;

}
