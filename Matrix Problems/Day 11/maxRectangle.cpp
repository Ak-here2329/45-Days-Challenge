class Solution{
  private:
    vector<int> prevSmallerElement(int *a, int n){
        stack<int> s;
        vector<int> ans(n);
        s.push(-1);
        for(int i=0; i<n; i++){
            int curr = a[i];
            while(s.top() != -1 && a[s.top()] >= curr)
                s.pop();
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    vector<int> nextSmallerElement(int *a, int n){
        vector<int> ans(n);
        stack<int> s;
        s.push(-1);
        for(int i=n-1; i>=0; i--){
            int curr = a[i];
            while(s.top() != -1 && a[s.top()] >= curr)
                s.pop();
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    int largestArea(int *heights, int n){
        int ans = INT_MIN;
        vector<int> prev = prevSmallerElement(heights, n);
        vector<int> next = nextSmallerElement(heights, n);
        
        for(int i=0; i<n; i++){
            if(next[i] == -1)
                next[i] = n;
            ans = max(ans, heights[i] * (next[i] - prev[i] - 1));
        }
        return ans;
    }
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int ans = largestArea(M[0], m);
        
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                if(M[i][j] == 1)
                    M[i][j] = M[i][j] + M[i-1][j];
                else
                    M[i][j] = 0;
            }
            ans = max(ans, largestArea(M[i], m));
        }
        return ans;
    }
};
