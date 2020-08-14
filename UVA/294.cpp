#include <bits/stdc++.h>
#define SLAY ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PI 3.141592653589793238
#define ll long long
#define pii pair<int , int>
#define pll pair<long long , long long>
#define INPUT freopen("inp.txt", "r", stdin);
using namespace std;

int cnt(ll n){
	int ret = 0;
	for(int i = 1 ; i*i<=n ;i++){
		if(n%i==0){
			if(n/i == i)ret++;
			else{
				ret+=2;
			}
		}
	}
	return ret;
}
int main(){
	SLAY
	int _=1 , tc=1;
	cin>>_;
	ll a,b;
	while(_--){
		cin>>a>>b;
		ll mx = 0 , ans = 0;
		for(int i = a ; i<=b;i++){
			int cand = cnt(i);
			if(cand>mx){
				mx = cand;
				ans= i;
			}
		}
		cout<<"Between "<<a<<" and "<<b<<", "<<ans<<" has a maximum of "<<mx<<" divisors.";
		cout<<endl;
	}
	return 0;
}