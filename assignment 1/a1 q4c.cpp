#include<iostream>
using namespace std;
class Transpose
{
	int a[10][10],b[10][10];
	int i,j,r,c;
	public:
		void create()
		{
			cout<<"Enter rows , columns respectively :";
			cin>>r>>c;
			cout<<"Enter the elements :";
			for(i=0;i<r;i++)
			{
				for(j=0;j<c;j++)
				{
					cin>>a[i][j];
				}
			}
		}
		void transpose()
		{
			for(i=0;i<r;i++)
			{
				for(j=0;j<c;j++)
				{
					b[j][i]=a[i][j];
				}
			}
		}
		void display()
		{
			for(i=0;i<r;i++)
			{
				for(j=0;j<c;j++)
				{
					cout<<b[i][j]<<endl;
				}
			}
		}
};
int main()
{
	Transpose t;
	t.create();
	t.transpose();
	t.display();
}
