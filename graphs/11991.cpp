#include <bits/stdc++.h>
#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))
#define lp(n) for (int i=0; i<n; i++)

using namespace std;

int n,m,k,v,temp,src=-1,d=-1;
int mx=-1;
int graph[10000][10000];
set<int> visited;

int main(int argc, const char * argv[]) {

    vector<vector<int> > data;
    while (scanf("%d %d", &n, &m) != EOF) {
        data.assign(1000000, vector<int>());

        for(int i=0; i<n; i++){
            cin>>temp;
            data[temp].push_back(i);
        }
        for (int i=0; i<m; i++){
            cin>>k>>v;
            if(data[v].size()>=k){
                cout<<data[v][k-1]+1<<endl;
            }else{
                cout<<0<<endl;
            }
        }
    }

    return 0;
}
