#include <iostream>
#include<vector>

using namespace std;
int lsearch(int n, int arr[], int x){
    
    int value = -1;
    for(int i=0; i<n-1;i++){
        if(x==arr[i]){
            cout<<x<<" "<<arr[i]<<endl;
        for(int j=i+1;j<n;j++){
        if(x==arr[j]){
            cout<<x<<" "<<arr[j]<<endl;
            value = arr[j];
            break;
        }
        
        }
        }
        
    }
    return value;
    
}
int main(){
     
    int arr[8] ={7, 5, 2, 11, 2, 43, 1, 1}; 
    int N=8;
    int x=43;
    
    
    
    int ans=lsearch(N, arr, x);
    cout<<ans;
    return 0;
}