#include <bits/stdc++.h>
#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))
#define lp(n) for (int i=0; i<n; i++)

using namespace std;

int n,m,temp,temp1,c=0;

int graph[10000][10000];
set<int> visited;

bool dfs(int v , int parent ) {

    visited.insert(v);
    c++;
    for(int i = 0 ; i < n ; i++){

        if(graph[v][i]){
            if(i==parent){
                continue;
            }


            if(visited.find(i) != visited.end())
                return true;

            if(dfs(i, v))
                return true;
        }
    }
    return false;


}
bool hasCycle(){


        if(dfs(0, -1)) {
            return true;
        }
        return false;

}
int main(int argc, const char * argv[]) {

    cin>>n>>m;

    lp(m){
        cin>>temp>>temp1;
        temp--; temp1--;
        graph[temp][temp1]=1;
        graph[temp1][temp]=1;
    }


    if(!hasCycle() && c==n){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}
