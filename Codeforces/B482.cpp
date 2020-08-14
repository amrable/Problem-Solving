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
		}
		
		void update_range(int i, int j, int val){
			update_range(1 , 1 , N , i , j , val);
		}
		
		void update_range(int node ,int b , int e, int i ,int j,int val){
			if(b>j || e<i)return;
			if(b>=i && e<=j){
				stree[node] |= val; 
				lazy[node] |= val;
				return;
			}
			int mid = b + (e-b)/2;
			propagate(node, b, mid, e);
			update_range(node<<1, b, mid ,i , j , val);
			update_range(node<<1|1, mid+1, e ,i , j , val);
			stree[node]= (stree[node<<1]&stree[node<<1|1]);
			
		}
		
		void propagate(int node, int b, int mid, int e){
			lazy[node<<1] |= lazy[node];
			lazy[node<<1|1] |= lazy[node];
			stree[node<<1] |= lazy[node];		
			stree[node<<1|1] |= lazy[node];		
			lazy[node] = 0;
		}
		
		int query(int i, int j){
			return query(1,1,N,i,j);
		}
	
		int query(int node, int b, int e, int i, int j){
			if(i>e || j <b)
				return -1;		
			if(b>= i && e <= j){
				return stree[node];
			}
			int mid = b + (e-b)/2;
			propagate(node, b, mid, e);
			int q1 = query(node<<1,b,mid,i,j);
			int q2 = query(node<<1|1,mid+1,e,i,j);
			if(q1 == -1)return q2;
			if(q2 == -1)return q1;
			return (q1 & q2);	
		}
		int get_parent_value(int index){
			while(index>1){
				if(stree[index]!=0)return stree[index];
				index >>= 1;
			}
			return stree[index];
		}
};

int main(){
	int n, N=1,m;
	cin>>n>>m;
	while(N<n)N<<=1;
	vector<ll> arr(N+1);
	SegmentTree st(arr);
	vector< vector<int> > v(m, vector<int>(3));
	bool ok= true;
	for(int i = 0;i<m;i++){
		cin >> v[i][0]>> v[i][1]>>v[i][2];
		st.update_range( v[i][0], v[i][1],v[i][2]);
	}
	for(int i = 0;i<m;i++){
		ll curr = st.query(v[i][0] , v[i][1]);
		if(curr != v[i][2]){
			ok=false;
		}
	}
	if(ok){
		cout<<"YES\n";
		for(int i = 1 ;i <= n ; i++){
			cout<<st.get_parent_value(i+N-1)<<" ";
		}
	}else cout<<"NO";
}