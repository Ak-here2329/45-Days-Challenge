    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> dist(6);
        dist[0] = pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2);
        dist[1] = pow(p1[0] - p3[0], 2) + pow(p1[1] - p3[1], 2);
        dist[2] = pow(p1[0] - p4[0], 2) + pow(p1[1] - p4[1], 2);
        dist[3] = pow(p2[0] - p3[0], 2) + pow(p2[1] - p3[1], 2);
        dist[4] = pow(p2[0] - p4[0], 2) + pow(p2[1] - p4[1], 2);
        dist[5] = pow(p3[0] - p4[0], 2) + pow(p3[1] - p4[1], 2);
        sort(dist.begin(), dist.end());
        if(dist[0] == dist[1] && dist[0] == dist[2] && dist[0] == dist[3] && dist[0] != dist[4] && dist[4] == dist[5])
            return true;
        return false;
    }
