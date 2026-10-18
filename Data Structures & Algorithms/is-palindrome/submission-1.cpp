class Solution {
public:
    bool isPalindrome(string s) {
        string temp1,temp2;
        for(int i = 0; i < s.size(); i++){
            if(isalnum(s[i])){
                temp1.push_back(tolower(s[i]));
            }
        }
        temp2 = temp1;
        reverse(temp2.begin(),temp2.end());

        return (temp1==temp2);
    }
};
