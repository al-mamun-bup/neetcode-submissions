class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>mp1;
        for(auto c : s1) mp1[c]++;
        int need = mp1.size();
        for(int i = 0 ; i < s2.size(); i++){
            unordered_map<char,int>mp2;
            int curr = 0;
            for(int j = i; j < s2.size(); j++){
                char c = s2[j];
                mp2[c]++;

                if(mp1[c] < mp2[c]){
                    break;
                }else if(mp1[c]==mp2[c]){
                    curr++;
                }

                if(curr==need){
                    return true;
                }
            }
        }

        return false;
    }
};
