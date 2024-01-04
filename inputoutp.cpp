#include<iostream>
#include<algorithm>
using namespace std;


int  main(){
    string s = "000B10";
    string ans = "";
    int size = 1;
    for(int i=0;i<s.length();i++){
         if(s[i]=='0'){
           ans[size] = '0';
           size++;
        }     
        else if(s[i]=='1'){
            ans[size] = '1';
            size++;
        }  
        else if(s[i]=='B'){
            size--;
        }   
        
    }
    
    cout<<ans;

    cout<<endl;
    return 0;
}