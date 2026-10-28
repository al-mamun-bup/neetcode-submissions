class Solution {
public:
    void solve(string digits,vector<string>& mp, int idx, string curr, vector<string>& ans){
        if(idx == digits.size()){
            ans.push_back(curr);
            return;
        }

        string words = mp[digits[idx]-'0'];
        for(char ch : words){
            solve(digits,mp,idx+1,curr+ch, ans);
        }
    }


    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }

        vector<string> mp = {
            "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
        };
        vector<string>ans;

        solve(digits,mp,0, "",ans);

        return ans;


    }
};
