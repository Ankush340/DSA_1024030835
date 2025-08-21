#include<iostream>
using namespace std;
class Array
{
	int a[20];
    int n,i,j;
	public :
		void create() {
        cout << "Enter number of elements: ";
        cin >> n;
        cout << "Enter elements:\n";
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
    }
		void reverseArray()
		{
			i = 0;
			j = n - 1;
			int temp;
			while(i< j)
			{
				temp = a[i];
				a[i] = a[j];
				a[j]= temp;
				i++;
				j--;
		    }
		}
		void display() {
        cout << "Array elements: ";
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    } 
};
int main()
{
	Array a;
	a.create();
	a.reverseArray();
	a.display();
}

