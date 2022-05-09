    int solveWordWrap(vector<int>nums, int k) 
    {   
        int n = nums.size();
        int extra[n+1][n+1], lc[n+1][n+1], ans[n+1];
        
        for(int i=1; i<=n; i++){
            extra[i][i] = k - nums[i-1]; 
            for(int j=i+1; j<=n; j++){
                extra[i][j] = extra[i][j-1] - nums[j-1] - 1;
            }
        }
        
        for(int i=1; i<=n; i++){
            for(int j=i; j<=n; j++){
                if(extra[i][j] < 0)
                    lc[i][j] = INT_MAX;
                else if (j == n && extra[i][j] >= 0)
                    lc[i][j] = 0;
                else
                    lc[i][j] = extra[i][j] * extra[i][j];
            }
        }
        
        ans[0] = 0;
        for(int j=1; j<=n; j++){
            ans[j] = INT_MAX;
            for(int i=1; i<=j; i++){
                if(ans[i-1] != INT_MAX && lc[i][j] != INT_MAX)
                    ans[j] = min(ans[j], ans[i-1] + lc[i][j]);
            }
        }
        return ans[n];
    } 
