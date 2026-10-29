class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>, greater<pair<int,vector<int>>>>pq;
        for(auto vec : points){
            vector<int>temp = vec;
            int dis = (temp[0]*temp[0] + temp[1]*temp[1]);
            pq.push({dis,temp});
        }

        vector<vector<int>> ans;
        while(k-- && !pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
