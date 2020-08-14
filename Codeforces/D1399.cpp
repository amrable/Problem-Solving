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
		ll n,b=0;
		string s;
		cin>>n>>s;
		vector<int>one;
		vector<int>zero;
		vector<int> nextone(n,-1);
		vector<int> nextzero(n,-1);
		vector<int> ans(n,-1);
		for(int i=0;i<n;i++){
			if(s[i]=='0')zero.push_back(i);
			else one.push_back(i);
		}
		int oneptr=0 , zeroptr=0;
		for(int i=0;i<n;i++){
			if(s[i]=='0'){
				b--;
				while(oneptr<one.size() && one[oneptr]<i){
					oneptr++;
				}
				if(oneptr<one.size())nextone[i]=one[oneptr++];
			}else{
				b++;
				while(zeroptr<zero.size() && zero[zeroptr]<i){
					zeroptr++;
				}
				if(zeroptr<zero.size())nextzero[i]=zero[zeroptr++];
			}
		}
		int curr = 0;
		for(int i=0;i<n;i++){
			bool oneismore = b>0;
			bool zeroismore = b<0;
			if(s[i]=='0' && ans[i]==-1){
				curr++;
				bool ptr_z = false;
				int next = nextone[i];
				ans[i]=curr;
				b++;
				while(next != -1){
					ans[next]=curr;
					if(ptr_z)next = nextone[next] , b++;
					else next=nextzero[next] , b--;
					
					ptr_z = !ptr_z;
				}
			}else if(s[i]=='1' && ans[i]==-1){
				curr++;
				bool ptr_z = true;
				int next = nextzero[i];
				ans[i]=curr;
				b--;
				while(next != -1){
					ans[next]=curr;
					if(ptr_z)next = nextone[next],b++;
					else next=nextzero[next],b--;
					
					ptr_z = !ptr_z;

				}
			}
		}
		cout<<curr<<endl;
		for(int i=0;i<n;i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}