#include <bits/stdc++.h>
#define ll long long
#define SLAY ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

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
			lazy.resize(N<<1,-1);
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
 
		void update_range(int i, int j, int val){
			update_range(1 , 1 , N , i , j , val);
		}
 
		void update_range(int node ,int b , int e, int i ,int j,int val){
			if(lazy[node]!=-1){
				stree[node] = lazy[node] * (e - b + 1);
			    if(e != b){
			      lazy[node<<1] = lazy[node];
			      lazy[node<<1|1] = lazy[node];
			    }
			    lazy[node] = -1;
			}
			if(b>j || e<i)return;
			
			if(b>=i && e<=j){
				stree[node] = val * (e-b+1);
				lazy[node] = val;
				if(b != e){
			      lazy[node<<1] = lazy[node];
			      lazy[node<<1|1] = lazy[node];
			    }
			    lazy[node] = -1;
				return;
			}
			int mid = b + (e-b)/2;
			update_range(node<<1, b, mid ,i , j , val);
			update_range(node<<1|1, mid+1, e ,i , j , val);
			stree[node]=stree[node<<1]+stree[node<<1|1];
		}
		
		void f(int node , int b , int e, string& s , int j){
			if(lazy[node]!=-1){
				stree[node] = lazy[node]*(e-b+1);
				if(b!=e)lazy[node<<1]=lazy[node];
				if(b!=e)lazy[node<<1|1]=lazy[node];
				lazy[node]=-1;
			}
			if(stree[node]==0)return;
			if(e==b){
				s[b-1]=j+'a';
				return;
			}
			f(node<<1 , b , b + (e-b)/2 , s , j );
			f(node<<1|1 , b + (e-b)/2 + 1 , e, s , j );
		}
 
		int query(int i, int j){
			return query(1,1,N,i,j);
		}
 
		int query(int node, int b, int e, int i, int j){
			
			if(lazy[node]!=-1){
				stree[node] = lazy[node] * (e - b + 1);
			    if(e != b){
			      lazy[node<<1] = lazy[node];
			      lazy[node<<1|1] = lazy[node];
			    }
			    lazy[node] = -1;
			}
			
			if(i>e || j <b)
				return 0;		
			if(b>= i && e <= j)
				return stree[node];
			int mid = b + (e-b)/2;
			int q1 = query(node<<1,b,mid,i,j);
			int q2 = query(node<<1|1,mid+1,e,i,j);
			return q1 + q2;	
		}
};
 
int main(){
	SLAY
	int n, N=1,m;
	cin>>n>>m;
	while(N<n)N<<=1;
	string str;
	cin>>str;
	vector< vector<ll> > arr(26, vector<ll>(N+1));
	for(int i = 0 ;i<n ; i++){
		arr[str[i]-'a'][i+1]++;
	}
	vector<SegmentTree>segtrees;
	for(int i = 0;i<26;i++){
		segtrees.push_back(SegmentTree(arr[i]));
	}
	
	while(m--){
		int type , l , r;
		cin>>l>>r>>type;
		vector<int>cnt(26,0);
		
		for(int j = 0 ; j<26 ; j++){
			cnt[j]=segtrees[j].query(l,r);
			segtrees[j].update_range(l,r,0);
		}
		
		int curr = l;
		if(type==0){
			for(int j = 25 ; j>=0 ; j--){
				if(cnt[j]==0)continue;
				int end_curr = curr+cnt[j]-1;
				segtrees[j].update_range(curr,end_curr,1);
				curr = end_curr + 1;
			}
		}else{
			for(int j = 0 ; j<26 ; j++){
				if(cnt[j]==0)continue;
				int end_curr = curr+cnt[j]-1;
				segtrees[j].update_range(curr,end_curr,1);
				curr = end_curr + 1;
			}
		}
	}
	for(int j = 0 ;j<26;j++){
		segtrees[j].f(1 , 1, N , str , j);
	}
	
	cout<<str<<endl;
	
 	return 0;
}