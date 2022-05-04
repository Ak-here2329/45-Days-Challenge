public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> m;
        vector<int> ans;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(m[nums[i]] == 1)
                ans.push_back(nums[i]);
            m[nums[i]]++;
        }
        return ans;
    }
