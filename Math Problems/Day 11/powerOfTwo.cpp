    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;
        return ((long long)n & (long long)(n-1)) == 0;
    }
