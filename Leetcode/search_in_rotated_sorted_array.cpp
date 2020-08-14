class Solution {
public:
    int search(vector<int>& nums, int target) {
      
      int start = 0;
      int end = nums.size();
      
      if(end==0)return -1;
      int ans = -1;
      int pos_max = 0;
      if(nums[end-1]<nums[start]){
        
        while(start<end){
          
          int mid = start+(end-start)/2;
          
          if(nums[mid]<nums[pos_max]){
            end = mid;
          }else{
            start = mid+1;
            pos_max = mid;
          }
        }

        
      }else{
        pos_max=end-1;
      }
      
      if(target>=nums[0]){
        // search  from 0 -> pos_max
        
        start = 0 ;
        end = pos_max+1;
        
      }else{
        // search from pos_max+1 -> end
        start = pos_max+1;
        end = nums.size();
      }
      
      while(start<end){
        int mid = start+(end-start)/2;
        
        if(nums[mid]==target){
          ans = mid;
          break;
        }else{
          if(nums[mid]>target){
            end = mid;
          }else{
            start=mid+1;
          }
        }
      }
      
      return ans;
    }
};
