  //Solution using Priority Queue  
  int findMaxValueOfEquation(vector<vector<int>>& a, int k) {
        priority_queue<pair<int, int>> pq;
        pq.push({a[0][1] - a[0][0], a[0][0]});
        int ans = INT_MIN, n = a.size();
        
        for(int i=1; i<n; i++){
            int sum = a[i][0] + a[i][1];
            while(!pq.empty() and a[i][0] - pq.top().second > k)
                pq.pop();
            if(!pq.empty())
                ans = max(ans, sum + pq.top().first);
            pq.push({a[i][1] - a[i][0], a[i][0]});
        }
        return ans;
    }
