#include<iostream>
using namespace std;
void quick( int a[], int b, int end)
{
if(end==b)
{
return;
}
else
{
	int size=end-b+1;
int * temp=new int[size];
int i;
int j;
int q;
for(i=b,j=0,q=size-1;i<end;i++)
{
	if(a[b]>a[end])
	{
		temp[j]=a[b];
		j++;
	}
	else 
	{
		temp[q]=a[b];
		q--;
      
	}
}
for(int i1=b,j1=0;i1<end;i1++,j1++)
{

	a[i1]=temp[j1];
}
	quick(a,b,b+j);
	quick(a,b+j+2,end);
}

}
int main()
{
	int t[10]={1,2,4,7,5,8,3,10,9,6};
quick(t,0,9);
for(int i=0;i<10;i++)
{
	cout<<t[i];
}
return 0;
}


