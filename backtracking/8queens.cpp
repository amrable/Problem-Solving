#include <bits/stdc++.h>
#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))

using namespace std;
map<string , int> mymap;
map<int , string> intToString;
long long a[100000];
long long b[100000];
char str[20],str2;
long long n,m;
long long mx=INT_MIN;
int mn=INT_MAX,x,y;
long long e = 0.0000000001;
long long start=0,myend,mid=-1,cash=0,q,c,ones=0,tempx=0,tempy=0 ;
vector <int> queens(8);
vector <vector<int>> ans;
int chess [8][8];

bool safe(int col,int row){

    for(int i = 0 ; i < 8 ; i++){
        for(int j =0;j<8;j++){

            if(chess[i][j]==1){
                if(i==row || j==col || abs(i-row)==abs(j-col)){
                    return false;
                }
            }
        }

    }


    return true;
}

void solve(int n,int col){

    if(n==col){
        ans.push_back(queens);
        return ;
    }
    if(col==y-1){
        solve(n,col+1);
        return;
    }

    for(int row=0;row<n;row++){
        queens[col]=row;

        if(safe(col,row)){
            chess[row][col]=1;
            solve(n, col+1);
        }
        chess[row][col]=0;
        queens[col]=-1;

    }
    return ;
}

void nqueen(int n ){
    queens.clear();
    ans.clear();
    for(int j =0;j<8;j++){
        queens.push_back(-1);
    }
    for(int i=0;i<8;i++){
        for(int j =0;j<8;j++){
            chess[i][j]=0;
        }
    }

    chess[x-1][y-1]=1;
    queens[y-1]=x-1;
    solve(n,0);
}

int main(int argc, const char * argv[]) {

    cin>>q;


    while(q--){
        cin>>x>>y;

        nqueen(8);

        cout<<endl;

        cout<<"SOLN\t   COLUMN"<<endl;
        cout<<" #  \t1 2 3 4 5 6 7 8\n"<<endl;
    for(int i = 0 ; i < ans.size() ; i++){
        cout<<" "<<i+1<<"  \t";
        for(int j =0;j<queens.size();j++){

            cout<<ans[i][j]+1;
            if(j+1<queens.size())cout<<" ";
        }
        cout<<endl;
    }

    }

    return 0;
}
