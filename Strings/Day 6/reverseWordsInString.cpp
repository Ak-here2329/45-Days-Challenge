    string reverseWords(string s) {
        stack<string> st;
        int n = s.size();
        for(int i=0; i<n; i++){
            if(s[i] == ' ')
                continue;
            string temp = "";
            while(i < n && s[i] != ' ')
                temp += s[i++];
            st.push(temp);
        }
        string ans = "";
        while(!st.empty()){
            ans += (" " + st.top());
            st.pop();
        }
        return ans.substr(1);
    }
