    int numDistinct(string s, string t) {
        int m = t.size(), n = s.size();
        vector<long long> curr(m+1, 0);
        curr[0] = 1;
        for(int j=1; j<=n; j++){
            int pre = 1;
            for(int i=1; i<=m; i++){
                int temp = curr[i];
                curr[i] += (t[i-1] == s[j-1] ? pre : 0);
                pre = temp;
            }
        }
        return curr[m];
    }
