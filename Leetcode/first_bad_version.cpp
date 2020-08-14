// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
      int start = 1 , end = n , ans;
      while(start<=end){
        int middle = start + (end-start)/2;
        if(isBadVersion(middle)){
          ans = middle;
          end = middle-1;
        }else{
          start = middle+1;
        }
      }
      return ans;
    }
};
