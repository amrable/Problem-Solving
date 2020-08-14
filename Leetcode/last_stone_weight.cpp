class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> p;
        for(int x :stones){
            p.push(x);
        }
        
        while(p.size() > 1){
            int y = p.top();
            p.pop();
            int x = p.top();
            p.pop();
            if(x!=y){
                p.push(y-x);
            }
        }
        
        if(p.size()>0)return p.top();
        return 0;
    }
};
