#include<iostream>
using namespace std;
int main()
{
	char S1[100]="ThaparTIET";
	int len=0,temp;
	while(S1[len] != '\0')
	len++;
	for(int i=0;i<len/2;i++)
	{
		temp=S1[i];
		S1[i]=S1[len-i-1];
		S1[len-i-1]=temp;
	}
	for(int i=0;i<len;i++)
	cout<<S1[i];
}
