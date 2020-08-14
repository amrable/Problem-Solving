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
		ll n,m;
		cin>>n>>m;
		bool ok=true;
		ll temp=n,j=0,ans=0 , tot;
		vector<int> bin(64,0);
		vector<int> have(64,0);
		vector<ll> v(m);
		while(temp){
			bin[j] += (temp & 1);
			temp = temp >> 1;
			j++;
		}
		for(int i=0;i<m;i++){
			cin>>v[i];
			int id = log2(v[i]);
			have[id]++;
			tot += v[i];
		}
		
		if(tot<n)ok=false;
		
		for(int i = 0 ; i< 63 ; i++){
			if(bin[i]==0){
				have[i+1] += have[i]/2;
			}else{
				if(have[i]>0){
					have[i]--;
					have[i+1]+= have[i]/2;
				}else{
					int pos = -1;
					for(int j = i+1 ; j<63 ; j++){
						if(have[j]>0){
							pos=j;
							break;
						}
					}
					if(pos==-1)ok=false;
					else{
						have[pos]--;
						ans+= pos-i;
						for(int j = pos-1 ; j>=i ; j--){
							have[j]=1;
						}
					}
				}
			}
		}
		
		
		
		if(ok)cout<<ans;
		else cout<<-1;

		
		cout<<endl;
	}
	return 0;
}