    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int low = INT_MAX, ans = 0, curr = 0;
        for(int i=0; i<n; i++){
            low = min(low, prices[i]);
            curr = prices[i] - low;
            ans = max(ans, curr);
        }
        return ans;
    }
