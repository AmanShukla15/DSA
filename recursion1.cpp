#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n == 0)
    {
        // cout<<"Inside base"<<endl;
        return 1;
    }

    // cout<<"n: "<<n<<endl;
    // int small = factorial(n-1);
    // cout<<"small: "<<small<<endl;
    // int big = n*small;
    // cout<<"n: "<<n<<" big: "<<big<<endl;


    // cout<<"n1: "<<n<<endl;
    return n * factorial(n - 1);
}

int main()
{
    int n;
    cin >> n;

    int ans = factorial(n);

    cout << "ans: " << ans << endl;

    return 0;
}