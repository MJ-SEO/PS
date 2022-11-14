class Solution {
public:
    bool isSubsequence(string s, string t) {
        int cnt = 0;
        int pivot = 0;
        for(int i=0; i<s.length(); i++){
            for(int j=pivot; j<t.length(); j++){
                if(s[i] == t[j]){
                    cnt++;  
                    pivot = j+1;
                    break;
                }
            }
        }
              
        if(cnt == s.length()){
            return true;
        }
        else{
            return false;
        }
    }
};