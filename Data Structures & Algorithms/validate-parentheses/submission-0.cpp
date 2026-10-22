class Solution {
public:
    bool isOpen(char c){
        return (c=='(' or c=='{' or c=='[');
    }
    bool isValid(string s) {
        stack<char>st;
        for(auto it : s){
            if(isOpen(it)){
                st.push(it);
            }else{
                if(st.empty()){
                    return false;
                }else{
                    char curr = st.top();
                    if(curr=='(' && it==')'){
                        st.pop();
                    }else if(curr=='{' && it=='}'){
                        st.pop();
                    }else if(curr=='[' && it==']'){
                        st.pop();
                    }else{
                        return false;
                    }
                }
            }
        }

        if(st.empty()){
            return true;
        }else{
            return false;
        }
    }
};
