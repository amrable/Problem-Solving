#include <bits/stdc++.h>
#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))
#define lp(n) for (int i=0; i<n; i++)

using namespace std;

int n,m,temp,temp1,c=0,src=-1,d=-1;
int mx=-1;
int graph[10000][10000];
set<int> visited;

void dfs(int v ,int cd ) {

    //cout<<"Current depth : "<<d<<" at vertex"<< v<<endl;
    if(cd>d)src=v;
    d=max(cd,d);
    visited.insert(v);
    vector<int> adj;
    for(int i = 0 ; i < n ; i++){

        if(graph[v][i]){

            if(visited.find(i) != visited.end())
                continue;

            dfs(i,cd+1);
        }
    }



}

int main(int argc, const char * argv[]) {

    cin>>n;

    lp(n-1){
        cin>>temp>>temp1;
        temp--; temp1--;
        graph[temp][temp1]=1;
        graph[temp1][temp]=1;
    }

    dfs(0,0);
    visited.clear();
    dfs(src,0);
    cout<<d<<endl;
    return 0;
}
