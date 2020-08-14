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

int gcd(int a, int b)  {  
    if (a == 0) 
        return b;  
    return gcd(b % a, a);  
}  
  
int lcm(int a, int b)  {  
    return (a*b)/gcd(a, b);  
}

int main(){SLAY
	int _=1 , tc=1;
	cin>>_;
	while(_--){
		ll n,a,b,c,m,q;
		cin>>a>>b>>q;
		ll l = lcm(a,b),ans=0 , tot=0;
		vector<ll> pre(l);
		for(int i = 0 ; i<l ; i++){
			if((i%a)%b != (i%b)%a){
				if(i)pre[i]=pre[i-1]+1;
				else pre[i]=1;
				tot++;
			}else{
				if(i)pre[i]=pre[i-1];
			}
		}
			
		while(q--){
			ans=0;
			ll x,y;
			cin>>x>>y;
			ll mx = max(x,y);
			ll mn = min(x,y);
			
			if(mx/l == mn/l){
				ans = pre[mx%l];
				if(mn%l>0)ans -= pre[mn%l-1];
			}else{
				if(mx%l != 0){
					int pos = mx%l;
					ans+= pre[pos];
					mx-= pos;
				}
				if(mn%l != 0){
					int pos = mn%l;
					ans+= pre[l-1]-pre[pos-1];
					mn += (l-mn%l);
				}
				if(mx>mn)ans+= ((mx-mn)/l)*tot;
				
			}
			cout<<ans<<" ";
		}
		cout<<endl;
	}
	return 0;
}