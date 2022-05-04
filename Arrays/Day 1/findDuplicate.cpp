    int findDuplicate(vector<int>& nums){
        map<int, bool> m;
        for(auto i : nums){
            if(m[i] == true)
                return i;
            m[i] = true;
        }
        return 0;
    }
