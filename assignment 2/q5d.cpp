#include<iostream>
using namespace std;
int main()
{
	int max=4;
	int i,j,k=0,a[max],size=(max*(max+1))/2;
	cout<<"Enter elementd row major : "<<endl;
	for(i=0;i<size;i++)
	{
		cin>>a[i];
	}
	cout<<"The matrix is : "<<endl;
	for(i=0;i<max;i++)
	{
		for(j=0;j<max;j++)
		{
			if(i<=j)
			{
			cout<<a[k]<<" ";
			k++;
		    }
			else
			cout<<0<<" ";
		}
		cout<<endl;
	}
}
