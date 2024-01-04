#include<iostream>
using namespace std;


int findSimilarity(int arr1[], int arr2[], int n, int m) 
{
    int count1 = 0;
    int count2 = m+n;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(arr1[i]==arr2[j]){
                count2--;
                count1++;
            }
        }
    }
    cout<<count1<<" "<<count2;
    return 0;
}

int  main(){

   int arr1[5]={7, 12, 2, 8, 13};
   int arr2[5]={6, 15, 12, 4, 10};
   int n = 5;
   int m = 5;
   findSimilarity(arr1, arr2, n, m);   

    return 0;
}