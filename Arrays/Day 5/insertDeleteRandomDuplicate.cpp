class RandomizedCollection {
private:
    vector<pair<int, int>> nums;
    unordered_map<int, vector<int>> m;
public:
    
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool ans = m.find(val) == m.end();
        m[val].push_back(nums.size());
        nums.push_back(make_pair(val, m[val].size() - 1));
        
        return ans;
    }
    
    bool remove(int val) {
        bool ans = m.find(val) != m.end();
        if(ans){
            auto last = nums.back();
            m[last.first][last.second] = m[val].back();
            nums[m[val].back()] = last;
            m[val].pop_back();
            if(m[val].empty())
                m.erase(val);
            nums.pop_back();
        }
        return ans;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()].first;
    }
};
