  // Get less from left and less from right array  
  int largestRectangleArea(vector<int>& height) {
        int n = height.size();
        vector<int> left(n,0), right(n,0);
        left[0] = -1, right[n-1] = n;
        int p;
        for(int i=1; i<n; i++){
            p = i-1;
            while(p>=0 and height[p] >= height[i])
                p = left[p];
            left[i] = p;
        }
        
        for(int i=n-2; i>=0; i--){
            p = i+1;
            while(p<n && height[p] >= height[i])
                p = right[p];
            right[i] = p;
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            ans = max(ans, height[i] * (right[i] - left[i] - 1));
        }
        return ans;
    }
