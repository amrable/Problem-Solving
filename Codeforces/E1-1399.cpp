#include <bits/stdc++.h>
#define SLAY ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PI 3.141592653589793238
#define ll long long
#define pii pair<int , int>
#define pll pair<long long , long long>
#define INPUT freopen("inp.txt", "r", stdin);
using namespace std;
int dx[] = { 0 , 0 , 1 , -1};
int dy[] = { 1 , -1 , 0 , 0};
int getmod(int x, int y , int mod ){return (((x - y)%mod)+mod)%mod;}

int solve(int node , int anc, int cost, vector< vector<pll> >&g , vector<pll>&tbd, vector<bool>& visited){
	int ret = 0;
	bool leaf = true;
	for(int i=0;i<g[node].size();i++){
		if(!visited[g[node][i].first]){
			leaf = false;
			visited[g[node][i].first]=true;
			ret+=solve(g[node][i].first , node ,g[node][i].second , g , tbd , visited );
		}
	}
	if(leaf)ret = 1;
	if(anc!=-1){
		tbd.push_back( make_pair(cost,ret));
	}
	
	return ret;
}

int main(){SLAY
	int _=1 , tc=1;
	cin>>_;
	while(_--){
		ll n,s,ans=0;
		cin>>n>>s;
		vector< vector< pair<ll , pll> > >g(n+1);
		for(int i =0;i<n-1;i++){
			ll x,y,w,c;
			cin>>x>>y>>w>>c;
			g[x].push_back(make_pair(y,make_pair(w,c)));
			g[y].push_back(make_pair(x,make_pair(w,c)));
		}
		vector<ll>cost;
		vector<make_pair(ll , pll)>tbd;
		vector<bool>visited(n+1,false);
		visited[1]=true;
		solve(1 , -1 , 0 , g, tbd , visited);
		
		ll tot = 0;
		for(int i =0;i<tbd.size();i++){
			ll value = tbd[i].first;
			ll cnt = tbd[i].second;
			// cout<<tbd[i].first<<" "<<tbd[i].second<<endl;;
			tot += value*cnt;
			while(value>0){
				ll curr = value/2;
				ll save = (value - curr)*cnt;
				cost.push_back(save);
				value /=2;
			}
		}
		sort(cost.rbegin(),cost.rend());
		ll need = tot-s;
		// cout<<tot<<endl;
		int i=0;
		while(need>0 && i<cost.size()){
			ans++;
			need -= cost[i];
			i++;
		}
		cout<<ans;
		cout<<endl;
	}
	return 0;
}