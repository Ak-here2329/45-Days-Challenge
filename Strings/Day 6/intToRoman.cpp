    void helper(string &s, int n, char c){
        for(int i=0; i<n; i++)
            s += c;
    }
    
    string intToRoman(int num) {
        string ans = "";
        
        while(num){
            if(num / 1000 > 0){
                int n = num / 1000;
                num = num % 1000;
                helper(ans, n, 'M');
            }else if (num / 500 > 0){
                int n = num / 500;
                if(num / 100 == 9){
                    helper(ans, 1, 'C');
                    helper(ans, 1, 'M');
                    num = num % 100;
                }else{
                    helper(ans, n, 'D');
                    num = num % 500;
                }
            }else if (num / 100 > 0){
                int n = num / 100;
                if(num / 100 == 4){
                    helper(ans, 1, 'C');
                    helper(ans, 1, 'D');
                }else{
                    helper(ans, n, 'C');
                }
                num = num % 100;
            }else if (num / 50 > 0){
                int n = num / 50;
                if(num / 10 == 9){
                    helper(ans, 1, 'X');
                    helper(ans, 1, 'C');
                    num = num % 10;
                }else{
                    helper(ans, n, 'L');
                    num = num % 50;
                }
            }else if (num / 10 > 0){
                int n = num / 10;
                if(num / 10 == 4){
                    helper(ans, 1, 'X');
                    helper(ans, 1, 'L');
                }else{
                    helper(ans, n, 'X');
                }
                num = num % 10;
            }else if (num / 5 > 0){
                int n = num / 5;
                if(num == 9){
                    helper(ans, 1, 'I');
                    helper(ans, 1, 'X');
                    num = 0;
                }else{
                    helper(ans, n, 'V');
                    num = num % 5;
                }
            }else if (num > 0){
                if(num == 4){
                    helper(ans, 1, 'I');
                    helper(ans, 1, 'V');
                }else
                    helper(ans, num, 'I');
                num = 0;
            }
        }
        return ans;
    }
