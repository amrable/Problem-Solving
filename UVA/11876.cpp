#include <bits/stdc++.h>
#define SLAY ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PI 3.141592653589793238
#define ll long long
#define pii pair<int , int>
#define pll pair<long long , long long>
#define INPUT freopen("inp.txt", "r", stdin);
using namespace std;

int main(){
	SLAY
	int _=1 , tc=1;
	int MAXN = 1000000;
	vector<int> factors(MAXN+1 , 0);
	vector<int> seq(MAXN+1 , 0);
	for(int i = 1;i<=MAXN;i++){
		for(int j = i ; j<=MAXN ; j+=i){
			factors[j]++;
		}
	}
	seq[0]=1;
	for(int i =1 ; i<=MAXN ; i++){
		seq[i] = seq[i-1]+factors[seq[i-1]];
	}
	cin>>_;
	ll a,b;
	while(_--){
		cin>>a>>b;
		cout<<"Case "<<tc++<<": ";
		cout<< upper_bound(seq.begin(),seq.end(),b) - lower_bound(seq.begin(),seq.end(),a);
		cout<<endl;
	}
	return 0;
}