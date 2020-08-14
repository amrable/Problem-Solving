/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
      int ans = -1;
      int cand_ans = INT_MAX;
      
      vector<int> dim = binaryMatrix.dimensions();
      int rows = dim[0];
      int cols = dim[1];
      int k=0 , j=cols-1;
      
      while(k<rows && j>=0){
        if(binaryMatrix.get(k,j)==1){
          cand_ans = j;
          j--;
        }else{
          k++;
        }
      }
      if(cand_ans != INT_MAX){
        ans = cand_ans;
      }
      return ans;
    }
};
