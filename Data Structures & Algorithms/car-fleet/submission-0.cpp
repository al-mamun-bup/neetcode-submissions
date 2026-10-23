class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>v;
        int n = speed.size();
        for(int i = 0 ; i < n ; i++){
            v.push_back({position[i],speed[i]});
        }

        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        // to reach the target formula : time to reach = (target-position)/speed
        stack<double>st;
        for(int i = 0; i < n ; i++){
            double curr_time = (double)(target-v[i].first) / (double)v[i].second;
             if (st.empty() || curr_time > st.top()) {
                st.push(curr_time);
            }
        }

        return st.size();
    }
};
