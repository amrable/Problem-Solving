#include <bits/stdc++.h>
#define SLAY ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PI 3.141592653589793238
#define ll long long
#define pii pair<int , int>
#define pll pair<long long , long long>
#define INPUT freopen(".txt", "r", stdin);
using namespace std;
int dx[] = { 0 , 0 , 1 , -1};
int dy[] = { 1 , -1 , 0 , 0};
int getmod(int x, int y , int mod ){return (((x - y)%mod)+mod)%mod;}
int main(){SLAY
	int _=1 , tc=1;
	// cin>>_;
	while(_--){
		ll n,a,b,c,m;
		ll ans=0;
		cin>>n>>m;
		vector< vector<ll> >table(m+1);
		vector< ll >cands(n,0);
		for(int i = 0;i<n ; i++){
			ll r ,s;
			cin>>s>>r;
			table[s].push_back(r);
		}
		for(int i = 1;i<=m;i++){
			sort(table[i].rbegin(),table[i].rend());
			ll pre=0;
			for(int j = 0;j<table[i].size();j++){
				pre+=table[i][j];
				table[i][j] = pre;
				
				if(pre>0)cands[j]+=pre;
			}
		}
		
		for(int i = 0;i<n;i++){
			ans = max((ll)ans,(ll)cands[i]);
		}
		
		cout<<ans;
		cout<<endl;
	}
	return 0;
}
