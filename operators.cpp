#include <iostream>
#include <fstream>
#include "vector.h"
using namespace std;
Vector<int>v;
int main(){
	int n,multiplier=10,sum=15;
	std::cin>>n;
	for(int i=0;i<n;i++)
		v.push_back(i);
    v=v*multiplier;
    (std::ofstream &)std::cout<<v;
    v=v+sum;
	(std::ofstream &)std::cout<<v;
}
