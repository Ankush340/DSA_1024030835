#include<iostream>
using namespace std;
int main()
{
	char arr[]={4,5,3,2,6,9,7};
	int a = sizeof(arr)/sizeof(arr[0]);
	int i,j,count=0;
	for(i=0;i<a;i++)
	{
		for(j=i+1;j<a;j++)
		{
			if(arr[i]>arr[j])
			count++;
		}
	}
	cout<<count;
}
