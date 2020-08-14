class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0 , end = nums.size() , mid;
        while(start<end){
            mid = start + (end - start)/2;
            int val = nums[mid];
            bool even = mid % 2 == 0;
            if(mid>0 && mid<nums.size()-1){
                if(nums[mid-1] != val && nums[mid+1]!=val)return val;
            }else if(mid == 0 && mid+1<nums.size()){
                if(nums[mid+1]!=val)return val;
            }else if(mid == nums.size()-1 && mid-1>=0){
                if(nums[mid-1]!=val)return val;
            }
            if(even){
                if(mid<nums.size()-1){
                    if(val==nums[mid+1]){
                        start = mid+1;
                    }else{
                        end = mid;
                    }
                }else{
                    if(mid-1>=0){
                        if(val == nums[mid-1]){
                            end = mid;
                        }else{
                            return val;
                        }
                    }else{
                        return val;
                    }
                }
            }else{
                if(mid-1>=0){
                    if(val == nums[mid-1]){
                        start = mid+1;
                    }else{
                        end = mid;
                    }
                }
            }
        }
        return nums[mid];
    }
};
