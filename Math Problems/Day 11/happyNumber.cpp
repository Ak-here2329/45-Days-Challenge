    int helper(int n){
        int sum = 0;
        while(n){
            sum += (n%10) * (n%10);
            n /= 10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        map<int, bool> m;
        bool check = true;
        while(n != 1){
            int curr = helper(n);
            if(m[curr] == true){
                check = false;
                break;
            }
            m[curr] = true;
            n = curr;
        }
        return check;
    }
