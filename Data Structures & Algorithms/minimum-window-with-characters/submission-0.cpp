class Solution {
public:
    string minWindow(string s, string t) {
        int minLen = 1e9, sIndex = -1, cnt = 0;
        int l = 0, r = 0;
        unordered_map<char,int>mp;
        int m = t.size();

        for(auto c : t){
            mp[c]++;
        }

        while(r < s.size()){
            if(mp[s[r]] > 0) cnt++;
            mp[s[r]]--;

            // to shrink and get the min
            while(cnt==m){
                if(minLen > (r-l+1)){
                    minLen = r-l+1;
                    sIndex = l;
                }

                mp[s[l]]++;
                if(mp[s[l]] > 0){
                    cnt--;
                }
                l++;
            }

            r++;
        }

        return sIndex == -1 ? "": s.substr(sIndex,minLen);
    }
};
