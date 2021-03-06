class WordFilter {
    public:
        unordered_map<string, int> dict;
        WordFilter(vector<string>& words) {
            int n = words.size();
            
            for(int i=0; i<n; i++){
                string p = "";
                for(int j=0; j<words[i].size(); j++){
                    p += words[i][j];
                    string s = "";
                    for(int k=words[i].size()-1; k>=0; k--){
                        s = words[i][k] + s;
                        dict[p + "|" + s] = i+1;  // to handle the no word case in dictionary
                    }
                }
            }
    }
    
    int f(string prefix, string suffix) {
        return dict[prefix + "|" + suffix] - 1;  // to handle the no word case in dictionary
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */