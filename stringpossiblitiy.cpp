#include<iostream>
using namespace std;

void stringGet(string str){
    string str1;
     for(int i=0;i<str.length();i++){
         str1[i]=str[i];
         cout<<str1<<endl;
     }
}


int main(){
    string str = "code";
    
    stringGet(str);

    return 0;
}