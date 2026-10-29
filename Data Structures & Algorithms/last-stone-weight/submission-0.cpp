class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(auto it : stones){
            pq.push(it);
        }

        while(!pq.empty()){
            int x = pq.top();
            pq.pop();
            if(!pq.empty()){
                int y = pq.top();
                pq.pop();
                if(x==y){
                    continue;
                }else{
                    pq.push(x-y);
                }
            }else{
                return x;
            }
        }
        
        if(pq.size()==1){
            return pq.top();
        }else{
            return 0;
        }
    }
};
