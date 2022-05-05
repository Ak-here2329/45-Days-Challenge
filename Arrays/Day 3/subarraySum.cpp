    int subarraySum(vector<int>& nums, int k) {
       int ans = 0, sum = 0;
        unordered_map<int, int> m;
        m[0] = 1;
        for(auto i : nums){
            sum += i;
            int rem = sum - k;
            if(m.find(rem) != m.end())
                ans += m[rem];
            m[sum]++;
        }
        return ans;
    }
