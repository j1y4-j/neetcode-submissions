class Solution {
public:
    bool isOp(string s){
        if(s=="*" || s=="/" || s=="+" || s=="-") return true;
        return false;
    }
    int doEval(int a,int b,string it){
        if(it=="*") return a*b;
        if(it=="/") return b/a;
        if(it=="+") return a+b;
        if(it=="-") return b-a;
        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        if(tokens.empty()) return 0;
        stack<int> st;
        for(auto it:tokens){
            if(isOp(it)){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                int c=doEval(a,b,it);
                st.push(c);
            }
            else{
                st.push(stoi(it));
            }
        }
        return st.top();
    }
};
