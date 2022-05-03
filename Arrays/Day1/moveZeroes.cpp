    void moveZeroes(vector<int>& a) {
        int count = 0, n = a.size();
        for(int i=0; i<n; i++){
            if (a[i] == 0)
                count++;
            else
                a[i-count] = a[i];
        }
        for(int i=n-count; i<n; i++)
            a[i] = 0;
    }
};
