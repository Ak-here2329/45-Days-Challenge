    int minMoves(vector<int>& nums) {
        int m = *min_element(nums.begin(), nums.end());
        long ans = 0;
        for(int i=0; i<nums.size(); i++)
            ans += nums[i] - m;
        return ans;
    }
