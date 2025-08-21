#include<iostream>
using namespace std;
int binary(int ary[],int n)
{
	int s = 0;
	int e = n-1-1;
	while(s <= e)
	{
		int mid = s+(e-s)/2;
		if((ary[mid+1]-ary[mid]) == 1)
		   s = mid+1;
		else
		   e = mid-1;
	}
	return (ary[s]+1);
};
int main()
{
	int ary[] = {1,2,3,5,6};
	int n = 6;
	cout<<"Missing number : "<<binary(ary,n);
}

