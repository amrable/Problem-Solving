class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int pre = 0;
        unordered_map<int , int>first_appear;
        first_appear[0]=0;
        int ans = 0;
        for(int i = 1 ; i <=n ; i++ ){
            pre+=nums[i-1]==1? 1:-1;
            if(first_appear.find(pre)==first_appear.end()){
                first_appear[pre]=i;
            }else{
                ans = max(ans , i-first_appear[pre]);
            }
            
        }
        return ans;
    }
};
