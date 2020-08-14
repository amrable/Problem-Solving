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
		ll n,c,m,ans=0;
		cin>>n>>m>>c;
		vector<ll>a(n+1);
		vector<ll>prea(n+1);
		vector<ll>b(m+1);
		vector<ll>preb(m+1);
		for(int i = 1 ; i <= n ; i ++){
			cin>>a[i];
			prea[i]+= a[i]+prea[i-1];
		}
		for(int i = 1 ; i <= m ; i ++){
			cin>>b[i];
			preb[i]+= b[i]+preb[i-1];
		}
		
		for(int i = 1 ; i <= n ; i++ ){
			ll pay = prea[i];
			if(pay>c)break;
			if(pay==c)ans=max(ans , (ll)i);
			ll rem = c-pay;
			
			int start = 0 , end = m+1 , pos=-1;
			while(start<end){
				int mid = start+(end-start)/2;
				if(preb[mid]<=rem){
					pos = mid;
					start=mid+1;
				}else{
					end = mid;
				}
			}
			ans = max(ans , (ll)i+pos);
		}
		
		for(int i = 1 ; i <= m ; i++ ){
			ll pay = preb[i];
			if(pay>c)break;
			if(pay==c)ans=max(ans , (ll)i);
			ll rem = c-pay;
			
			int start = 0 , end = n+1 , pos=-1;
			while(start<end){
				int mid = start+(end-start)/2;
				if(prea[mid]<=rem){
					pos = mid;
					start=mid+1;
				}else{
					end = mid;
				}
			}
			ans = max(ans , (ll)i+pos);
			
		}
		cout<<ans;
		cout<<endl;
	}
	return 0;
}
