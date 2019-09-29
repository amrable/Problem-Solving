#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;
stack<char> s ;
long long ans,t,c=0,v;
string str;
int size[1000];
int sets[1000];
int n,q,p,a,b,m;
map <int,int> check;
const unsigned int M = 1000000007; //10^9+7
vector <pair<int, int>> extra;


int root (int i)
{
    while(sets[ i ] != i)
    {
        sets[ i ] = sets[ sets[ i ] ] ;
        i = sets[ i ];
    }
    return i;
}
bool unified(int a , int b){
    if(root(a)==root(b))return true;
    else return false;
}

void wunion(int set1,int set2){

//    if(unified(set1,set2))return;
    int root1=root(set1);
    int root2=root(set2);

    if(size[root1] > size[root2]){
        sets[root2]=root1;
        size[root1]+=size[root2];
    }else{
        sets[root1]=root2;
        size[root2]+=size[root1];
    }

}

int main()
{
    cin>>n;

    //initialize n sets ans Sizes array of size n initialized by 1

    for(int i = 0 ; i < n ; i ++){
        sets[i]=i;
        size[i]=1;
    }

    for(int i = 0 ; i < n-1 ; i ++){
        cin>>a>>b;
        a--;
        b--;

        if(unified(a,b)){
            c++;
            extra.push_back(make_pair(a,b));

        }else{
            wunion(a, b);
        }
    }
    cout<<c<<endl;

    while(c--){
        for(int i = 1 ; i < n ; i++){
            if( !unified(0, i)){
                wunion(0, i);
                cout<<extra.back().first+1<< " "<<extra.back().second+1<< " "<<1<<" "<<i+1<<endl;
                extra.pop_back();
                break;
            }
        }
    }



    return 0;
}
