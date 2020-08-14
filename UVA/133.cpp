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
	ll n,k,m;
	while(_--){
		cin>>n>>k>>m;
		if(!n && !k && !m)break;
		vector<int>v(n);
		for(int i=0;i<n;i++){
			v[i]=i+1;
		}
		int nextk = 0, nextm = n-1;
		k--;
		m--;
		while(v.size()>0){
			int size = v.size();
			int i = getmod(nextk,0-k,size);
			int j = getmod(nextm,  m,size);
			// cout<<i<<"-"<<j<<endl;
			int fr = v[i];
			int sc = v[j];
			if(fr == sc){
				cout<<fr<<", ";
				v.erase(v.begin()+i);
				nextk = getmod(i,0-1,v.size()) , nextm= getmod(j,1,v.size());
			}else{
				cout<<fr<<" "<<sc<<", ";
				v.erase(v.begin()+i);
				v.erase(v.begin()+j);
				if(j-i==1){
					nextk = getmod(i,0-2,v.size()) , nextm= getmod(j,2,v.size());
				}else{
					nextk = getmod(i,0-1,v.size()) , nextm= getmod(j,1,v.size());
				}
			}
			nextk = i , nextm=j;
		}
		cout<<endl;
	}
	
	return 0;
}