///Fenvick tree based solution
    long search(vector<int> &bit, long i){
        long sum = 0, n = bit.size();
        while(i < n){
            sum += bit[i];
            i += i & -i;
        }
        return sum;
    }
    
    void insert(vector<int> &bit, int i){
        while(i > 0){
            bit[i] += 1;
            i -= i & -i;
        }
    }
    
    int index(vector<int> &copy, long val){
        int s = 0, e = copy.size() - 1, mid = 0;
        while(s <= e){
            mid = s + (e - s) / 2;
            if(val <= copy[mid])
                e = mid - 1;
            else
                s = mid + 1;
        }
        return s + 1;
    }
    
    int reversePairs(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int> bit(n+1, 0);
        vector<int> copy = nums;
        sort(copy.begin(), copy.end());
        
        for(auto i : nums){
            ans += search(bit, index(copy, 2l * i + 1));
            insert(bit, index(copy, i));
        }    
        return ans;
    }

///Merge Sort Based solution
    int helper(vector<int> &nums, int l, int r){
        if(l >= r)
            return 0;
        
        int mid = l + (r - l) / 2;
        int ans = helper(nums, l, mid) + helper(nums, mid+1, r);
        int i = l, j = mid + 1, p = mid + 1, k = 0;
        int merge[r-l+1];
        
        while(i <= mid){
            while(p <= r && nums[i] > (2l * nums[p]))
                p++;
            ans += (p - mid - 1);
            
            while(j <= r and nums[i] >= nums[j])
                merge[k++] = nums[j++];
            merge[k++] = nums[i++];
        }
        
        while(j <= r)
            merge[k++] = nums[j++];
        
        k = 0, i = l;
        while(i <= r)
            nums[i++] = merge[k++];
        
        return ans;
    }
    
    int reversePairs(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
