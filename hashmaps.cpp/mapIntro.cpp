#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;


int main(){
    // creation 
   unordered_map<string, int> m;

    // insertion technique 1
    pair<string, int> p = make_pair("babbar", 3);
    m.insert(p);

    // insertion technique 2
    pair<string, int> pair2("love", 2);
    m.insert(pair2);

    // 3
    m["mera"]=1;
    m["mera"]=2; 

    // search 1
    cout<<m["mera"]<<endl;
    // 2
    cout<<m.at("babbar")<<endl;

    // if key is not present, it will give out_of_range error!!
    // cout<<m.at("unknownKey")<<endl;

    // it will create a mapping of an unknown key with zero
    cout<<m["unknownKey"]<<endl;

    // size
    cout<<m.size()<<endl;

    // to check presence
    cout<<m.count("love")<<endl;

    // erase
    m.erase("love");
    cout<<m.size()<<endl;

    // iterator
    unordered_map<string, int> :: iterator it = m.begin();
 
    while(it != m.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++; 
    }

    return 0;


}