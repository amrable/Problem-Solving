class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int final_shift_value=0 , final_direction=1;
        int n = shift.size();
        int str_len = s.length();
        for(int i=0; i < n ; i++){
            if(shift[i][0]==0){
                final_shift_value -= shift[i][1]; 
            }else{
                final_shift_value += shift[i][1]; 
            }
        }
        
        if ( final_shift_value<0){
            final_direction = 0 ;
            final_shift_value *= -1; 
        }
        
        final_shift_value %= str_len;
        
        if(final_shift_value == 0){
            return s;
        } 
            
        string ret = "";
        
        
        // if i shift Hello to the right by 3 
        // result: llohel , observation, i start the answer by the 3rd element from the end
        
        // if i shift hello to the left by 2
        // result: llohe, observation: i start thr naswer by the second element from the beggining
        
        int start_pos = (final_direction == 0? final_shift_value : str_len - final_shift_value );
        
        int done =0;
        
        while(done<str_len){
            ret+=s[start_pos];
            start_pos++;
            start_pos %= str_len;
            done++;
        }
        
        return ret;
        
    }
};
