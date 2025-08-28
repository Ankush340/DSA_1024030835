#include<iostream>
using namespace std;
int main()
{
	int max=4;
	int i,j,a[max];
	cout<<"Enter elementd row major : "<<endl;
	for(i=0;i<max;i++)
	{
		cin>>a[i];
	}
	cout<<"The matrix is : "<<endl;
	for(i=0;i<max;i++)
	{
		for(j=0;j<max;j++)
		{
			if(i==j)
			cout<<a[i]<<" ";
			else
			cout<<0<<" ";
		}
		cout<<endl;
	}
}
