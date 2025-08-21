#include<iostream>
using namespace std;
int main()
{
	char S1[100]="TIET";
	int i=0;
	while(S1[i] != '\0')
	{
		if(S1[i]>='A'&&S1[i]<='Z')
		S1[i]=S1[i]+32;
		i++;
	}
	for(i=0;i<100;i++)
	cout<<S1[i];
}
