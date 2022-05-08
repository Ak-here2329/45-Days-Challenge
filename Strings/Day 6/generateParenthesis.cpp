    void helper(int open, int close, vector<string> &ans, string curr){
        if(open <= 0 && close <= 0){
            ans.push_back(curr);
            return;
        }
        
        if(open > 0)
            helper(open - 1, close + 1, ans, curr + "(");
        if(close > 0)
            helper(open, close - 1, ans, curr + ")");

    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr = "";
        helper(n, 0, ans, curr);
        return ans;
    }
