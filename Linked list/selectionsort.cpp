#include<iostream>
using namespace std;

int selectionSort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";

    }cout<<endl;
    return 0;
}
int main(){
    int arr[10]={0,0,0,1,0,0,0,0,1,0};
    int n = 10;
    selectionSort(arr, n);
    return 0;
}