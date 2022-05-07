    int strStr(string haystack, string needle) {
        int n = haystack.size(), k = needle.size();
        for(int i=0; i<=n-k; i++){
            if(haystack.substr(i, k) == needle)
                return i;
        }
        return -1;
    }
