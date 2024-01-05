// geeks for geeks -> anagram

bool isAnagram(string a, string b){
        
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
        if(a == b){
            return true;
            
        }
        else{
            return false;
        }
        
    }