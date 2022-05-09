    string numberToWords(int num) {
        if(num == 0)
            return "Zero";
        string one[] = {"", "One", "Two", "Three", "Four", "Five", "Six",
            "Seven", "Eight", "Nine"};
        string Ten1[] = {"Ten", "Eleven", "Twelve", "Thirteen", 
            "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", 
            "Nineteen"};
        string ten[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty",
            "Seventy", "Eighty", "Ninety"};
        string thous[] = {"", "Thousand", "Million", "Billion"};
        
        string ans = "";
        
        int i = 0;
        while(num != 0){
            string curr = "";
            int ones = 0, tens = 0, hunds = 0;
            ones = num % 10; 
            num /= 10;
            tens = num % 10;
            num /= 10;
            
            if(tens == 1)
                curr = Ten1[ones] + " " + curr;
            else{
                if(ones > 0)
                    curr = one[ones] + " " + curr;
                if(tens > 0)
                    curr = ten[tens] + " " + curr;
            }
            hunds = num % 10;
            num /= 10;
            if(hunds > 0)
                curr = one[hunds] + " Hundred" + " " + curr;
            
            if(i > 0 and curr.size() > 0)
                ans = curr + thous[i] + " " + ans;
            else
                ans = curr + ans;
            i++;
        }
    
        return ans.substr(0, ans.size() - 1);
    }
