    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string a = strs[0], b = strs[strs.size() - 1], ans = "";
        int i = 0;
        while(i < a.size()){
            if(a[i] == b[i])
                ans += a[i++];
            else
                break;
        }
        return ans;
    }
