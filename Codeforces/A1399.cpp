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
		ll n,x,tot,ans=0,a,b;
		cin>>n;
		bool ok=true;
		vector<int>v(n);
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		for(int i= 0;i<n-1;i++){
			if(v[i+1]-v[i]>1)ok=false;
		}
		if(ok)cout<<"YES";
		else cout<<"NO";
		cout<<endl;
	}
	return 0;
}