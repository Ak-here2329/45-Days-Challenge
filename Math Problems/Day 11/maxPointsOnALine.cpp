    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), ans = 0;
        
        for(int i=0; i<n; i++){
            map<pair<int, int>, int> m;
            for(int j=0; j<n; j++){
                if(i != j){
                    int x = points[j][0] - points[i][0];
                    int y = points[j][1] - points[i][1];
                    int p = __gcd(x,y);
                    x /= p, y /= p;
                    m[{x,y}]++;
                }
            }
            int cnt = 0;
            for(auto i : m)
                cnt = max(cnt, i.second);
            ans = max(ans, 1 + cnt);
        }
        return ans;
    }
