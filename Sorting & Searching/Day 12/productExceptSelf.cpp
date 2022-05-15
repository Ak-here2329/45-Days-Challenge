  vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
        //code here
        vector<long long int> ans(n);
        long long int prod = 1;
        int check = 0;
        for(int i=0; i<n; i++){
            if(nums[i] != 0)
                prod *= nums[i];
            else
                check++;
        }
        
        for(int i=0; i<n; i++){
            if(check >= 2)
                ans[i] = 0;
            else if(check == 1){
                if(nums[i] == 0)
                    ans[i] = prod;
                else
                    ans[i] = 0;
            }else
               ans[i] = prod / nums[i]; 
        }

        return ans;
    }
