class Solution {
public:
  
    /*
    
    solve( i  , opened ) == balance (i  -> end)
    
    */
  
  int dp [101][101];
  string S;
  int N , inf = 200;
  
  int solve(int i, int open){
    if(i==N){
      if(open>0)return 0-inf;
      return 0;
    }
    
    if(open<0)return 0-inf;
    
    int &ret = dp[i][open];
    
    if( ret != -1 )return ret;
    
    if(S[i]=='('){
      ret = solve(i+1 , open+1)+1;
    }else if(S[i]==')'){
      ret = solve(i+1 , open-1)-1;
    }else{
      int try_open =  solve(i+1 , open+1)+1;
      int try_close =  solve(i+1 , open-1)-1;
      int skip = solve(i + 1 , open);
      
      if(open+try_open == 0){
        ret = try_open;
      }else if(open+try_close == 0){
        ret = try_close;
      }else if(open+skip == 0){
        ret = skip;
      }else{
        return 0-inf;
      }
      
      
    }
    
    return ret;
    
    
  }
  
  
  bool checkValidString(string s) {

    if(s.length()==0)return true;
    S=s;
    N=s.length();
    memset(dp , -1 , sizeof(dp));
    
    return solve(0 , 0)==0;

  }
};
