class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, maxLen = 0, maxFreq = 0;
        vector<int>freq(26,0);
        while(r < s.size()){

            freq[s[r]-'A']++;
            maxFreq = max(maxFreq, freq[s[r]-'A']);

            while((r-l+1)-maxFreq > k){
                freq[s[l]-'A']--;
                maxFreq = 0;
                for(int i = 0; i < 26; i++){
                    maxFreq = max(maxFreq, freq[i]);
                }

                l++;
            }

            if((r-l+1)-maxFreq <= k){
                maxLen = max(maxLen, r-l+1);
            }

            r++;
        }

        return maxLen;

    }
};
