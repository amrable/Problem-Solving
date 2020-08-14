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
	cin>>_;
	while(_--){
		int n,x,ans=0;
		cin>>n>>x;
		string str;
		cin>>str;
		
		map<int , int> mp;
		int b=0 , hi=0,lo=0;
		for(int i=0;i<n;i++){
			if(str[i]=='0')b++;
			else b--;
			hi=max(hi,b);
			lo=min(lo,b);
		}
		
		if(b==0){
			if(x>=lo && x<=hi)ans=-1;
			else ans=0;
		}else if(b>0){
			int k = (int) ceil(1.0*hi/b);
			int newb=0 , j=0;
			while(k--){
				for(int j=0;j<n;j++){
					if(str[j]=='0')b++;
					else b--;
					mp[b]++;
				}
			}
			if(x>hi){
				ans=mp[hi];
			}else if(x>=lo)ans = mp[x];
			else ans=0;
		}else{
			int k = (int) ceil(1.0*hi/abs(b));
			int newb=0 , j=0;
			while(k--){
				for(int j=0;j<n;j++){
					if(str[j]=='0')b++;
					else b--;
					mp[b]++;
				}
			}
			if(x<lo){
				ans=mp[lo];
			}else if(x<=hi)ans = mp[x];
			else ans=0;
		}
		
		
		
		cout<<ans;
		cout<<endl;
	}
	return 0;
}
