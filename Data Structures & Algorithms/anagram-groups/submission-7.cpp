class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string,vector<string>>mp;
        for(auto s : strs){

            vector<int>freq(26);
            for(int i = 0 ; i < s.size(); i++){
                freq[s[i]-'a']++;
            }

            string key = "";
            for(int i = 0; i < 26; i++){
                key += to_string(freq[i])+"#";
            }

            mp[key].push_back(s);
        }

        vector<vector<string>> ans;

        for(auto it : mp){
            ans.push_back(it.second);
        }

        return ans;
    }
};
