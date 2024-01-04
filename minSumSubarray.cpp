#include<iostream>
using namespace std;


int minSubarraySum(int arr[], int n, int k) 
{
    int count = 1;
    int s = 0;
    int e = n-1;
    int min=arr[e]; 
    // int sum = 0;
    while(s<k-1){
    min += arr[s];
    s++;    
    }    
    cout<<"value of min = "<<min<<endl;
    for(int i=0;i<=e-k+1;i++){
        int sum = 0;
       for(int j=i;j<i+k;j++){
            
            sum +=arr[j];
       }
       cout<<count<<" iteration : sum = "<<sum<<endl;
        if(sum<min){
            min = sum;
        }
       cout<<count<<" iteration : min = "<<min<<endl;
        count++;
    }
    cout<<"value of minimum(answer)= "<< min<<endl;
    return 0;
}

int main(){
    int arr[9]={1, -4, 2, 10, -2, 3, 1,0, -20};
    int n=9;
    int k=4;

    minSubarraySum(arr,n,k);
   
    return 0;
}