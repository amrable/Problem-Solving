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
		ll n;
		cin>>n;
		vector<ll>a(n);
		vector<ll>b(n);
		vector<ll> in(n,0);
		vector<bool> vis(n,false);
		stack<ll> post;
		stack<ll> now;
		ll ans=0;
		for(int i = 0 ; i < n ; i++){
			cin>>a[i];
		}
		for(int i = 0 ; i < n ; i++){
			cin>>b[i];
			if(b[i]!=-1){
				b[i]--;
				in[b[i]]++;
			}
		}
		for(int i = 0 ; i < n ; i++){
			
			if(in[i]==0 && !vis[i]){
				vis[i]=true;
				if(a[i]>=0){
					ans+=a[i];
					now.push(i);
				}else{
					ans+=a[i];
					post.push(i);
				}

				if(b[i]!=-1){
					in[b[i]]--;
					if(a[i]>0)a[b[i]]+=a[i];
				}
				int j = i;
				while(b[j]!=-1 && in[b[j]]==0 && !vis[b[j]] ){
					vis[b[j]]=true;
					j=b[j];
					if(a[j]>=0){
						ans+= a[j];
						now.push(j);
					}else{
						ans+= a[j];
						post.push(j);
					}
					// cout<<ans<<" "<<j<<endl;
					// if(b[j]!=-1)in[b[j]]--;
					if(b[j]!=-1){
						in[b[j]]--;
						if(a[j]>0)a[b[j]]+=a[j];
					}
				}
				
			}
		}
		
		cout<<ans<<endl;
		stack<ll> temp;
		while(!now.empty()){
			temp.push(now.top());
			now.pop();
		}
		while(!temp.empty()){
			cout<<temp.top()+1<<" " ;
			temp.pop();
		}
		while(!post.empty()){
			cout<<post.top()+1<<" " ;
			post.pop();
		}
		cout<<endl;
	}
	return 0;
}