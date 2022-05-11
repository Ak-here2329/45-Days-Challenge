    vector<string> fullJustify(vector<string>& words, int m) {
        vector<string> ans;
        for(int i = 0, j; i < words.size(); i = j){
            int width = 0;
            for(j = i; j < words.size() && width + words[j].size() + j - i <= m; j++)
                width += words[j].size();
            int space = 1, extra = 0;
            if(j - i != 1 && j != words.size()){
                space = (m - width) / (j - i - 1);
                extra = (m - width) % (j - i - 1);
            }
            string line(words[i]);
            for(int k = i + 1; k < j; k++){
                line += string(space, ' ');
                if (extra-- > 0)
                    line += " ";
                line += words[k];
            }
            line += string(m - line.size(), ' ');
            ans.push_back(line);
        }
        return ans;
    }
