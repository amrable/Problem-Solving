#include <bits/stdc++.h>
#define SLAY ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PI 3.141592653589793238
#define ll long long
#define pii pair<int , int>
#define pll pair<long long , long long>
#define INPUT freopen("travel_restrictions_validation_input.txt", "r", stdin);
using namespace std;
int dx[] = { 0 , 0 , 1 , -1};
int dy[] = { 1 , -1 , 0 , 0};
int getmod(int x, int y , int mod ){return (((x - y)%mod)+mod)%mod;}
int main(){SLAY
	int _=1 , tc=1;
	// cin>>_;
	while(_--){
		ll n,a,b,c;
		string str;
		ll ans=0;
		cin>>n;
		for(int i = 1;i<=n ; i++){
			ll y = n/i;
			ans += i*y*(y+1)/2;
		}
		cout<<ans;
		cout<<endl;
	}
	return 0;
}
