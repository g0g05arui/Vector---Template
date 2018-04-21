#include <iostream>
#include <fstream>
#include "vector.h"
Vector<int>v;
int main(){
	int n;
	std::cin>>n;
	for(int i=0;i<n;i++)
		v.push_back(i);
	std::cout<<v.size()<<'\n';
    (std::ofstream &)std::cout<<v;
}
