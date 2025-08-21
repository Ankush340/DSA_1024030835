#include<iostream>
using namespace std;
int main()
{
	char S1[100] = "Hello";
	char S2[100] = "World";
	int i=0,a=0;
	while(S1[i] != '\0')
	i++;
	
	for(int j=0;j<100;j++)
	{
		if(S2[j] != '\0')
		S1[i++] = S2[j];
	}
	
	for(int i=0;i<100;i++)
	{
		if(S1[i] != '\0')
		cout<<S1[i];
	}
}
