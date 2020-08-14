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


int main(){SLAY
	int _=1 , tc=1;
	// cin>>_;
	while(_--){
		ll n,h,k,ans=0;
		cin>>n>>h>>k;
		vector<ll>v(n);
		for(int i = 0;i<n;i++)cin>>v[i];
		
		int i =0;
		ll inside=0;
		while(i<n && h-inside >= v[i]){
			inside +=v[i];
			i++;
		}
		for(;i <n ;){
			ll need = v[i]- (h-inside);
			ll loops = ceil(1.0*need/k);
			ans += loops;
			inside -= loops*k;
			inside = max(inside , (ll)0);
			while(i<n && h-inside >= v[i]){
				inside +=v[i];
				i++;
			}
		}
		ans+= ceil(1.0*inside/k);
		cout<<ans;
		cout<<endl;
	}
	return 0;
}