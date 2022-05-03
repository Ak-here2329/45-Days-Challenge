    int maxProfit(vector<int>& prices) {
        int i = 0, ans = 0, buy = 0, sell = 0, n = prices.size();
        while(i<n){
            while(i < n-1 and prices[i] > prices[i+1])
                i++;
            if(i==n-1)
                break;
            buy = prices[i];
            i++;
            while(i < n-1 and prices[i] < prices[i+1])
                i++;
            sell = prices[i];
            if(buy != -1 and sell != -1)
                ans += (sell - buy);
            i++;
            buy = -1, sell = -1;
        }
        return ans;
    }
