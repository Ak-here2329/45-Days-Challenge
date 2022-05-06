    int majorityElement(vector<int>& nums) {
        int major = nums[0], count = 1, n = nums.size();
        for(int i=1; i<n; i++){
            if(count == 0){
                major = nums[i];
                count++;
            }else if (nums[i] == major)
                count++;
            else
                count--;
        }
        return major;
    }
