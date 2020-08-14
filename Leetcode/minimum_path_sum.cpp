class Solution {
public:
  
    int n , m ;
    vector< vector<int> >dp;
    vector<vector<int>> g;
  
    int solve( int i , int j  ){
      
      int &ret = dp[i][j];
      
      if(ret != 0)return ret;
      
      ret = g[i][j];
      
      int try_down = INT_MAX , try_right=INT_MAX;
      
      if(i+1<n && j+1<m){
        try_down = solve(i+1 , j);
        try_right = solve(i , j+1);
        
        ret += min(try_down , try_right);
      }else if(i+1<n){
        try_down = solve(i+1 , j);
        
        ret += try_down;
      }else if(j+1<m){
        try_right = solve(i , j+1);
        
        ret += try_right;
      }
      
      return ret;

    }
  
    int minPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        g=grid;
        if(n==0)return 0;
        m = grid[0].size();
        dp.resize(n);
        for(int i = 0 ; i< n ;i++){
          dp[i].resize(m);
        }
        return solve(0,0);
    }
};
