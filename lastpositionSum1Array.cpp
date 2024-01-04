#include<iostream>
using namespace std;

int arraysum(int digits[], int e){
        
        
        if(digits[e-1]<9){
        digits[e-1]+=1;
        }
        else{
        int num = digits[e-1]+1;
        do{
            num = num/10;
            digits[e-1]=num;
            if(num==1||num==0)
            e++;
            num = num % 10; 
        }while(num!=0);
        }
        for(int i=0;i<e;i++){
            cout<<digits[i]<<" ";
        }cout<<endl;
        return 0;
}
int main(){
  int digits[2] = {1,9};
  int e = 2;
  arraysum(digits, e);
  return 0;
}