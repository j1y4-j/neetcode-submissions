class Solution {
public:
    bool freqEqual(vector<int> &f1, vector<int> &f2){
        for(int i=0;i<26;i++){
            if(f1[i]!=f2[i]) return false;
        }
        return true;
    }
    bool isAnagram(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<int>f1(26,0);
        vector<int>f2(26,0);
      for(int i=0;i<s.length();i++){
            f1[s[i]-'a']++;
      }  
    for(int i=0;i<m;i++){
            f2[t[i]-'a']++;
      } 
      if(freqEqual(f1,f2)) return true;
      return false;
    }
};
