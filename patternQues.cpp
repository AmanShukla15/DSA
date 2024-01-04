#include <iostream>
using namespace std;

int main()
{
    int n = 4;
    
    for (int i = 1; i <= n; i++)
    {
        for (int s = i; s < n; s++)
        {
            cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout <<i+j-1;

        }
        for(int k=i+1; k>=n;k--){
            cout<<k;
        }
        
        cout << endl;
    }

    return 0;
}