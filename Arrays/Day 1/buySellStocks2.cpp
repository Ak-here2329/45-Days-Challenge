    int maxProfit(vector<int>& prices) {
        int i = 0, ans = 0, buy = 0, sell = 0, n = prices.size();
        while(i<n-1){
            while(i < n-1 and prices[i] >= prices[i+1])
                i++;
            buy = prices[i];
            while(i < n-1 and prices[i] < prices[i+1])
                i++;
            sell = prices[i];
            
            ans += (sell - buy);
        
        }
        return ans;
    }
