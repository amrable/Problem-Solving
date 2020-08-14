#include <bits/stdc++.h>
#define SLAY ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PI 3.141592653589793238
#define ll long long
#define pii pair<int , int>
#define pll pair<long long , long long>
#define INPUT freopen("inp.txt", "r", stdin);
using namespace std;
void solve(){
	ll n , m;
	cin>>n>>m;
	ll mx = max(m,n);
	ll mn = min(m,n);
	while(mx - mn > 1 && mn>0 && mx>0){
		ll diff = mx - mn ;
		diff -= diff%2;
		if(mn<diff/2)break;
		mx -= diff;
		mn -= diff/2;
	}
	
	if( mx-mn <=1 && (mn+mx) %3 == 0)cout<<"YES";
	else cout<<"NO";
	cout<<endl;
	
}
int main(){
	SLAY
	int _=1,tc=1;
	cin>>_;
	while(_--){
		solve();
	}
	return 0;
}