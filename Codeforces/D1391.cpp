#include <bits/stdc++.h>
#define SLAY ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PI 3.141592653589793238
#define ll long long
#define pii pair<int , int>
#define pll pair<long long , long long>
using namespace std;

int dp[1<<3][1000005];
int v[4][1000005];
int n,m;
bool good_mask(int cmask , int pmask ){
	int ones = (cmask&1) + (pmask&1) + ((cmask>>1)&1) + ((pmask>>1)&1);
	if(ones%2==0)return false;
	if(n==2)return true;
	ones = ((cmask>>1)&1) + ((pmask>>1)&1) + ((cmask>>2)&1) + ((pmask>>2)&1);
	if(ones%2==0)return false;
	return true;
}

int cost(int col , int mask){
	return 	(int) (v[0][col] != ((mask>>0)&1))+
			(int) (v[1][col] != ((mask>>1)&1))+
			(int) (v[2][col] != ((mask>>2)&1));
}

int dp_(int pmask , int col){
	if(col==m)return 0;
	int& ret = dp[pmask][col];
	if(~ret)return ret;
	ret = INT_MAX;
	for(int cmask = 0 ; cmask< (1<<n) ; cmask++){
		if(good_mask(cmask,pmask)){
			int cst = cost(col,cmask);
			ret = min(ret , cst + dp_(cmask , col+1));
		}
	}
	return ret;
}

void solve(){
	cin>>n>>m;
	memset(dp , -1 , sizeof(dp));
	memset(v , 0 , sizeof(v));
	for(int i = 0;i<n;i++){
		string s;
		cin>>s;
		if(n>3)continue;
		for(int j=0;j<m;j++){
			v[i][j] = (int)s[j]-'0';
		}
	}
	if(n>3){
		cout<<-1;
		return;
	}
	if(n==1){
		cout<<0;
		return;
	}
	int ans = INT_MAX;
	for(int i=0 ; i< 1<<n ; i++){
		int cst = cost(0,i);
		ans = min(ans , cst+dp_(i , 1));
	}
	cout<<ans;
}

int main(){
	SLAY
	int _=1;
	while(_--){
		solve();
	}
	return 0;
}