class Solution {
public:
    bool isPalindrome(string s) {
        int j=0;
        for(int i=0;i<s.length();i++){
            if(isalnum(s[i])) s[j++]=tolower(s[i]);
        }
         s.resize(j);
        int p=0;
        int n=j-1;
        while(p<=n){
            if(s[p]!=s[n]) return false;
            p++;
            n--;
        }
        return true;
    }
};
