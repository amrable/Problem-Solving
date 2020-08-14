#include <bits/stdc++.h>
#define ll long long
using namespace std;

class SegmentTree{
	public:
		int N;
		vector<ll> stree;
		vector<ll> lazy;
		vector<ll> array;
 
		SegmentTree(vector<ll>& v){
			N = v.size()-1;
			array = v;
			lazy.resize(N<<1);
			stree.resize(N<<1);
			build(1,1,N);
		}
 
		void build(int node , int b , int e){
			if(b==e)stree[node]=array[b];
			else{
				int mid = b + (e-b)/2;
				build(node<<1, b, mid);
				build(node<<1|1, mid+1, e);
				stree[node] = stree[node<<1]+stree[node<<1|1];
			}
		}
 
		void update_point(int index, int val){
			index += N-1;
			stree[index]=val;
			while(index>1){
				index>>=1;
				stree[index]=stree[index<<1]+stree[index<<1|1];
			}
		}
 
		void update_range(int i, int j, int val){
			update_range(1 , 1 , N , i , j , val);
		}
 
		void update_range(int node ,int b , int e, int i ,int j,int val){
			if(b>j || e<i)return;
			if(b>=i && e<=j){
				stree[node] += val * (e-b+1);
				lazy[node] += val;
				return;
			}
			int mid = b + (e-b)/2;
			propagate(node, b, mid, e);
			update_range(node<<1, b, mid ,i , j , val);
			update_range(node<<1|1, mid+1, e ,i , j , val);
			stree[node]=stree[node<<1]+stree[node<<1|1];
		}
 
		void propagate(int node, int b, int mid, int e){
			lazy[node<<1] += lazy[node];
			lazy[node<<1|1] += lazy[node];
			stree[node<<1] += (mid-b+1)*lazy[node];		
			stree[node<<1|1] += (e-mid)*lazy[node];		
			lazy[node] = 0;
		}
 
		int query(int i, int j){
			return query(1,1,N,i,j);
		}
 
		int query(int node, int b, int e, int i, int j){
			if(i>e || j <b)
				return 0;		
			if(b>= i && e <= j)
				return stree[node];
			int mid = b + (e-b)/2;
			propagate(node, b, mid, e);
			int q1 = query(node<<1,b,mid,i,j);
			int q2 = query(node<<1|1,mid+1,e,i,j);
			return q1 + q2;	
		}
};
 
int main(){
	int tc=1;
	bool f = false;
	while(true){
		int n, N=1,m;
		cin>>n;
		if(n==0)break;
		if(f)cout<<endl;
		while(N<n)N<<=1;
		vector<ll> arr(N+1,0);
		for(int i = 1 ;i<=n ; i++)cin>>arr[i];
		SegmentTree st(arr);
		cout<<"Case "<<tc++<<":"<<endl;
		while(true){
			string s;
			cin>>s;
			if(s=="END")break;
			
			if(s=="M"){
				int l,r;
				cin>>l>>r;
				cout<<st.query(l,r)<<endl;
			}else if(s=="S"){
				int val,node;
				cin>>node>>val;
				st.update_point(node,val);
			}
		}
		f=true;
	}
 
}