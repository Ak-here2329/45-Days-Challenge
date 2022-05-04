    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> m;
        int i=0, csum = 0;
        m[0] = 1;
        while(i<n){
            csum += nums[i++];
            int rem = csum % k;
            if(rem < 0)
                rem += k;
            if(m.find(rem) != m.end())
                ans += m[rem];
            m[rem]++;
        }
        return ans;
    }
