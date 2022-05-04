    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int,int> m;
        vector<int> ans;
        for(int i=0; i<n; i++){
            int curr = target - nums[i];
            if(m.find(curr) != m.end()){
                ans.push_back(i);
                ans.push_back(m[curr]);
                return ans;
            }
            m[nums[i]] = i;
        }
        return ans;
    }
