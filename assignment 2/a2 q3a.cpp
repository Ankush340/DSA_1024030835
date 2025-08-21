#include<iostream>
using namespace std;
int linear(int ary[],int n)
{
	for(int i = 1 ;i<= n ; i++)
	{
		if((ary[i+1]-ary[i]) != 1)
		{
			return ary[i]+1;
		}
	}
};
int main()
{
	int ary[] = {1,2,3,5,6};
	int n = 6;
	cout<<"Missing number : "<<linear(ary,n);
}
