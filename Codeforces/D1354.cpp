#include <bits/stdc++.h>
#define SLAY ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PI 3.141592653589793238
#define ll long long
#define pii pair<int , int>
#define pll pair<long long , long long>
#define INPUT freopen("inp.txt", "r", stdin);
using namespace std;

bool ok(int val , vector<int>& v, vector<int>& k){
	int cnt=0;
	for(int i =0;i<v.size();i++){
		if(val>=v[i])cnt++;
		else break;
	}
	for(int i = 0 ; i < k.size();i++){
		if(k[i]>0){
			if(k[i]<=val)cnt++;
		}else{
			if(abs(k[i])<=cnt)cnt--;
		}
	}
	return cnt>0; 
}
int main(){
	SLAY
	int _=1 , tc=1;
	ll n,m;
	while(_--){
		cin>>n>>m;
		vector<int>v(n);
		vector<int>k(m);
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		for(int i=0;i<m;i++){
			cin>>k[i];
		}
		int start = 1 , end = n+1 , ans = -1;
		while(start<end){
			int mid = start + (end - start ) / 2;
			// cout<<mid<<endl;
			if(ok(mid,v,k)){
				end = mid;
				ans = mid;
			}else{
				start = mid+1;
			}
		}
		if(ans == -1)cout<<0;
		else cout<<ans;
		cout<<endl;
	}
	return 0;
}