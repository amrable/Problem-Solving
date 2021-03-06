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
		ll n,x,tot,ans=0,mna=INT_MAX,mnb=INT_MAX;
		cin>>n;
		bool ok=true;
		vector<ll>a(n);
		vector<ll>b(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
			mna=min(a[i],mna);
		}
		for(int i=0;i<n;i++){
			cin>>b[i];
			mnb=min(b[i],mnb);
		}
		
		for(int i= 0;i<n;i++){
			if(a[i]>mna && b[i]>mnb){
				ll opt1 = a[i]-mna;
				ll opt2 = b[i]-mnb;
				ans+= max(opt1,opt2);
			}
			else if(a[i]>mna)ans+=(a[i]-mna);
			else if(b[i]>mnb)ans+=(b[i]-mnb);
		}
		
		cout<<ans;
		cout<<endl;
	}
	return 0;
}