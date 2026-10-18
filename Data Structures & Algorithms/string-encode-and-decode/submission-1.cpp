class Solution {
public:

    string encode(vector<string>& strs) {
        vector<int>sizes;
        string res = "";
        for(auto s : strs){
            sizes.push_back(s.size());
            res += to_string(s.size())+",";
        }

        res += "#";
        
        for(auto s : strs){
            res += s;
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<int>sizes;
        string res = "";
        int i = 0;
        while(s[i] != '#'){
            string curr = "";
            while(s[i] != ','){
                curr += s[i];
                i++;
            }

            sizes.push_back(stoi(curr));
            i++;
        }

        i++;

        vector<string>ans;
        for(auto it : sizes){

            ans.push_back(s.substr(i,it));
            i += it;
        }

        return ans;
    }
};
