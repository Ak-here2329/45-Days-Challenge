    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int exp = (n * (n+1))>>1, sum = 0;
        for(auto i : nums)
            sum += i;
        return exp - sum;
    }
