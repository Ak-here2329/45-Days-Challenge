    int maxProduct(vector<int>& nums) {
        int ans = nums[0], l = 0, r =  0;
        for(int i=1; i<nums.size(); i++){
            l = (l ? l : 1) * nums[i];
            r = (r ? r : 1) * nums[nums.size() - i - 1];
            
            ans = max(ans, max(l, r));
        }
        return ans;
    }
