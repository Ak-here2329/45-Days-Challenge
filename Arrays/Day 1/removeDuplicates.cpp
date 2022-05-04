    int removeDuplicates(vector<int>& a){
        int n = a.size(), count = 0;
        for(int i=1; i<n; i++){
            if (a[i] == a[i-1])
                count++;
            else
                a[i-count] = a[i];
        }
        return n - count;
    }
