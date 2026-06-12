class Solution {
public:
    vector<string> mp = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    void solve(int idx,string digits,vector<string> &ans, string s){
        if(s.length()==digits.length()){
            ans.push_back(s);
            return;
        }
        string chars = mp[digits[idx]-'0'];
        for(char c: chars){
            solve(idx+1,digits,ans,s+c);
        }


    }
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0) return {};
        vector<string> ans;
        string s;
        solve(0,digits,ans,s);
        return ans;
    }
};
