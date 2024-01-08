#include<iostream>
using namespace std;

int countWays(int nStairs){
    if(nStairs<0){
        return 0;
    }
    if(nStairs==0){
        return 1;
    }
    int ans = countWays(nStairs-1) + countWays(nStairs-2);

    return ans;
}

int main(){
   int nStairs;
   cin>>nStairs;

   int ans = countWays(nStairs);
   cout<<"Ans: "<<ans<<endl;
return 0;
}