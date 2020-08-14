class Solution {
public:
    
    vector< vector<bool > > visited;
    int n , m;
    vector<vector<char>> g;
    void dfs( int i , int j ){
      
      if(visited[i][j])return;
      
      visited[i][j]=true;
      
      if(i-1>=0 && g[i-1][j]=='1'){
        dfs(i-1,j) ;
      }
      
      if(i+1<n && g[i+1][j]=='1'){
        dfs(i+1,j );
      }
      
      if(j+1<m && g[i][j+1]=='1'){
        dfs(i,j+1 );
      }
      
      
      if(j-1>=0 && g[i][j-1]=='1'){
        dfs(i,j-1);
      }
      
      return;
      
    }
    int numIslands(vector<vector<char>>& grid) {
          
      n = grid.size();
      
      g=grid;
      
      if(n==0)return 0;
      
      m = grid[0].size();
      
      int ans=0;
      
      visited.resize(n);
      
      
      for(int i = 0 ; i< n ; i++){
        visited[i].resize(m);
      }
      
      for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j< m ; j++){
          
          
          if(grid[i][j]=='1' && !visited[i][j]){
            
          
            dfs(i , j);
            
            ans++;
          }
          
          
        }
      }
      return ans;
    }
};
