#include <iostream>
using namespace std;
int main() {
    char S1[100] = "education";
    char S2[100];
    int i = 0, j = 0;

    while (S1[i] != '\0') {
        if (!(S1[i] == 'a' || S1[i] == 'e' || S1[i] == 'i' || S1[i] == 'o' || S1[i] == 'u')) 
		{
            S2[j] = S1[i];  
            j++;
        }
        i++;
    }

    cout << "String without vowels: " << S2 << endl;
    return 0;
}

