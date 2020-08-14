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
	cin>>_;
	while(_--){
		ll n,x,tot,ans=0,mna=INT_MAX,mnb=INT_MAX;
		cin>>n;
		bool ok=true;
		vector<ll>v(n);
		map<int,int>mp;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		
		
		for(int i=2;i<=100;i++){
			ll curr =0;
			mp.clear();
			for(int j=0;j<n;j++){
				mp[v[j]]++;
			}
			for(int j=0;j<n;j++){
				int target = i-v[j];
				if(target>0 && mp[target]>0 && mp[v[j]]>0){
					if(target == v[j]){
						if(mp[target]>1){
							mp[target]-=2;
							curr++;
						}
					}else{
						mp[target]--;
						curr++;
						mp[v[j]]--;
					}
				}
			}
			ans = max(ans , curr);
		}
		
		cout<<ans;
		cout<<endl;
	}
	return 0;
}