#include <iostream>
#include <fstream>
#include "vector.h"
Vector<int>v;
int main(){
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
		v.push_back(i);
	for(auto it=v.begin();it!=v.end();it++)
        std::cout<<*it<<" ";
    std::cout<<'\n';
    for(Vector<int>::iterator it=v.begin();it!=v.end();it++)
        std::cout<<*it<<" ";
    std::cout<<'\n';
}
