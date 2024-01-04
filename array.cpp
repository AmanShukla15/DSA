#include <iostream>
using namespace std;

int removeElement(int nums[], int val, int n)
{
    int count = 1;
    for (int i = 0; i < n ; i++)
    {

        if (nums[i] == val)
        {
            cout << nums[i] << " " << val << endl;
            for(int j=i;j<n-1;j++){
            nums[j] = nums[j + 1];
            cout << count << " iteration: ";
            for (int k = 0; k < n; k++)
            {
                cout << nums[k] << " ";
            }
            cout << endl;
            count++;
            // n--;
        }
    }
    }

    for (int i = n; i >= 1; i--)
    {
        if(nums[i]==val){
            n--;
        }
    }
    for(int i = 0; i<n;i++)
    cout<<nums[i]<<" ";

    cout << endl;
    return 0;
}

int main()
{
    int nums[10] = {1, 6, 9, 3, 10, 4,2,7, 5, 2};
    int val = 2;
    int n = 10;
    removeElement(nums, val, n);
}
