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
		int n,x,ans=0,tot;
		cin>>n>>x;
		string str;
		cin>>str;
		vector<int>pre(n);
		int b=0,hi=0,lo=0;
		for(int i=0;i<n;i++){
			pre[i]=b;
			if(str[i]=='0')b++;
			else b--;
			hi = max(hi,b);
			lo = min(lo,b);
			tot=b;
		}
		if(tot==0){
			if(x>=lo && x<=hi)ans =-1;
			else ans=0;
		}else{
			for(int i=0;i<n;i++){
				if( (x-pre[i])/tot >=0 && (x-pre[i]) % abs(tot)==0 )ans++;
			}
		}
		
			
		cout<<ans;
		cout<<endl;
	}
	return 0;
}
