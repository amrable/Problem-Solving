class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n);
        int temp = 1;
        
        for(int i  = n - 1 ; i>=0 ; i--){
            temp*= nums[i];
            output[i]=temp;
        }
        
        temp=1;
        
        for(int i = 0 ; i < n-1 ; i++){
            output[i] = temp* output[i+1];
            temp*=nums[i];
        }
        
        output[n-1]=temp;
        
        return output;
    }
};
