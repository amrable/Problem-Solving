#include <bits/stdc++.h>
#define ll long long
#define SLAY ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

class SegmentTree{
	public:
		int N;
		vector< vector<int> > stree;
		string s;
 
		SegmentTree(string& str){
			N = str.size()-1;
			s = str;
			stree.resize(N<<1);
			for(int i = 0 ;i < stree.size();i++)stree[i].resize(3,0);
			build(1,1,N);
		}
 
		void build(int node , int b , int e){
			if(b==e){
				if(s[b]=='('){
					stree[node][1]=1;
				}else if(s[b]==')'){
					stree[node][2]=1;
				}
			}
			else{
				int mid = b + (e-b)/2;
				build(node<<1, b, mid);
				build(node<<1|1, mid+1, e);
				stree[node][0] = stree[node<<1][0]+stree[node<<1|1][0];
				int neo = min(stree[node<<1][1],stree[node<<1|1][2]);
				stree[node][0] += neo*2;
				stree[node][1] = stree[node<<1][1] + stree[node<<1|1][1]-neo;
				stree[node][2] = stree[node<<1][2] + stree[node<<1|1][2]-neo;
			}
		}
 
		int query(int i, int j){
			int ans=0,left=0 , right=0;
			query(1,1,N,i,j,ans,left , right);
			return ans;
		}
 
		void query(int node, int b, int e, int i, int j, int& ans, int& left, int& right){
			int ans1=0,left1=0 , right1=0;
			int ans2=0,left2=0 , right2=0;
			if(i>e || j <b)return;
			if(b>= i && e <= j){
				ans = stree[node][0];
				right = stree[node][1];
				left = stree[node][2];
				return;
			}
			int mid = b + (e-b)/2;
			query(node<<1,b,mid,i,j , ans1 , left1 , right1);
			query(node<<1|1,mid+1,e,i,j, ans2 , left2 , right2);
			int neo = min(right1,left2);
			ans = ans1 + ans2 + neo*2;
			right = right1 + right2 -neo;
			left = left1 + left2 -neo;
			return;	
		}
};
 
int main(){
	SLAY
	string s;
	cin>>s;
	ll n = s.length(),m,N=1;
	s = "-"+s;
	while(N<n)N<<=1;
	for(int i = n+1;i<=N;i++)s+='-';
	SegmentTree st(s);
	cin>>m;
	while(m--){
		int l , r;
		cin>>l>>r;
		cout<<st.query(l,r)<<endl;
	}
}