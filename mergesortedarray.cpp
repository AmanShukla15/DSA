#include<iostream>

using namespace std;

void mergeArray(int num1[], int n, int num2[], int m){

    int j=0;
    int s=0;
    int e = n-1;
    for(int i=0;i<n;i++){
        if(num1[i]==0){
            num1[i]=num2[j];
            j++;
        }
    }
    
    while(s<=e){
        if(num1[s]>num1[e]){
        swap(num1[s],num1[e]);
        }
        s++;
        e--;
    }
    for(int i=0;i<n;i++){
        cout<<num1[i]<<" ";
    }cout<<endl;
}
int main(){
    int num1[6]={1,2,3,0,0,0};
    int n=6;
    int num2[3]={2,5,6};
    int m=3;

    mergeArray(num1, n, num2, m);
}