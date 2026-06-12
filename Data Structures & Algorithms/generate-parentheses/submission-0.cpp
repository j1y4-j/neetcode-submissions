class Solution {
public:
    void solve(int left,int right,string s, vector<string> &ans){
        if(!left && !right) {
            ans.push_back(s);
            return;
        }

        if(left && left<=right) solve(left-1, right,s+'(',ans);
        if(right && left<=right) solve(left,right-1,s+')',ans);

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        //always start with left=n-1 and right =n cuz left<=right and alwasy sstarts with left paarenthesis
        s.push_back('(');
        solve(n-1,n,s,ans);
        return ans;
    }
};
