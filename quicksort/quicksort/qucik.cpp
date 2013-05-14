#include<iostream>
using namespace std;
int main()
{




return 0;


}


int quick(int a[],int x,int left,int rihgt)
{
	int par=patrition(left,right);
    size= right-left+1;
	int temp;
	
	temp=a[size];
	a[size]=a[par];
	a[par]=temp;

     if (a[par]==x)
			return par;




}

int partition(int left,int right)
{
   return (left+right)/2;

}

swap(int & a,int &b)
{




}