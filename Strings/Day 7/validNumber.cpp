    bool isNumber(string s) {
        int n = s.size(), i = 0, digits = 0, dots = 0;
        
        for(; i<n && isspace(s[i]); i++);
        
        if(s[i] == '+' || s[i] == '-')
            i++;
        
        for(; i<n && (isdigit(s[i]) || s[i] == '.'); i++)
            s[i] == '.' ? dots++ : digits++;
        
        if(!digits || dots > 1)
            return false;
        
        if(s[i] == 'e' || s[i] == 'E'){
            i++;
            digits = 0;
            
            if(s[i] == '+' || s[i] == '-')
                i++;
            
            for(; i<n && isdigit(s[i]); i++)
                digits++;
            if(!digits)
                return false;
        }
        
        for(; i<n && isspace(s[i]); i++);
        
        return i == n;
    }
