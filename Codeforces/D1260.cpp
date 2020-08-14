#include <bits/stdc++.h>
#define SLAY ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PI 3.141592653589793238
#define ll long long
#define pii pair<int , int>
#define pll pair<long long , long long>
using namespace std;
int _=1;
bool ok(int agile, int time, int n , vector< vector<int> >&bombs){
	vector<int> l(n+1,0);
	vector<int> r(n+1,0);
	for(int i = 0;i<bombs.size();i++){
		if(bombs[i][2]<=agile)continue;
		l[bombs[i][0]-1]++;
		r[bombs[i][1]]++;
	}
	int level = 0 , busy = 0;
	for(int i = 0 ; i<n+1;i++){
		level += l[i];
		level -= r[i];
		if(level > 0)busy++;
	}
	// cout<<agile<<" "<<busy<<" "<<busy*2+ n + 1<<endl;
	return busy*2+ n + 1 <= time;
}
void solve(){
	ll n,m,k,t;
	cin>>m>>n>>k>>t;
	vector<int> a(m);
	vector< vector<int> >bombs(k,vector<int>(3));
	for(int i=0;i<m;i++)cin>>a[i];
	for(int i=0;i<k;i++)cin>>bombs[i][0]>>bombs[i][1]>>bombs[i][2];
	sort(a.begin(),a.end());	
	int start = 0, end = m , ans = m;
	while(start<end){
		int mid = start+(end-start)/2;
		if(ok(a[mid], t, n ,bombs)){
			end = mid;
			ans = mid;
		}else{
			start = mid+1;
		}
	}
	cout<<m-ans;
}
int main(){
	SLAY
	// cin>>_;
	while(_--){
		solve();
	}
	return 0;
}