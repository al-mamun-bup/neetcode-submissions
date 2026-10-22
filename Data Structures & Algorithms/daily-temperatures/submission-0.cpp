class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>ans(n,0);
        stack<pair<int,int>>st; // pair : {temparature, index}

        for(int i = 0 ; i < n ; i++){
            int t = temperatures[i];
            while(!st.empty() && t > st.top().first){
                auto it = st.top();
                st.pop();
                ans[it.second] = i - it.second; // curr index - that index
            }
            st.push({t,i});
        }

        return ans;
    }
};
