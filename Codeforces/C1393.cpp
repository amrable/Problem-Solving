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

// sieve
int MAXN = 46341 + 1;
int spf[46341+1];
int d,x,y;
int gcd(int a , int b){
	if(b==0)return a;
	return gcd(b , a%b);
}
void sieve(){
	for(int i = 1 ; i<MAXN ; i++)spf[i]=i;
	for(int i = 4 ; i<MAXN ; i+=2)spf[i]=2;
	for(int i = 3; i*i<MAXN; i+=2){
		if(spf[i]==i){
			for(int j = i*i ; j<MAXN ; j+=i){
				if(spf[j]==j)spf[j]=i;
			}
		}
	}
}


void extended_gcd(int a , int b){
	if(b==0){
		d=a;
		x=1;
		y=0;
	}else{
		extended_gcd(b,a%b);
		int temp = y;
		y = x - y * (a/b);
		x = temp;	
	}
}

int main(){
	SLAY
	int _=1 , tc=1;
	ll n,m;
	int cnt[100001];
	cin>>_;
	while(_--){
		ll mx =0,ans=0,ones=0;
		cin>>n;
		vector<int>v(n);
		vector<int> p;
		set<int> s;
		for(int i=0;i<n;i++){
			cin>>v[i];
			s.insert(v[i]);
		}
		memset(cnt , 0 , sizeof(cnt));
		for(int i =0;i<n;i++){
			cnt[v[i]]++;
		}
		for(int x: s){
			p.push_back(cnt[x]);
		}
		sort(p.rbegin(),p.rend());
		int curr = 0 , gaps = p[0]-1;
		for(int i = 1 ; i < p.size();i++){
			if(p[i]>=p[0]-1)ans++;
			else{
				curr += p[i];
			}
			if(curr>= gaps){
				ans += curr/gaps;
				curr %= gaps;
			}
		}
		cout<<ans;
		cout<<endl;
	}
	return 0;
}