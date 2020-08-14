#include <bits/stdc++.h>
#define SLAY ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;
long long mod(long long x, long long y, long long m) {
	long long tmp = x, ans = 1;
	while(y) {
		if(y&1) {
			ans *= tmp;
			ans %= m;
		}
		tmp = tmp*tmp, tmp %= m;
		y >>= 1;
	}
	return ans;
}
bool prime[65002];

void sieve() {
	int i, j;
	for(i = 2; i <= 65000; i++) {
		if(prime[i]) {
			for(j = 2; i*j <= 65000; j++)
				prime[i*j] = false;
		}
	}
}
int check(int n) {
	int i;
	for(i = 2; i <= n-1; i++) {
		if(mod(i, n, n) != i)
			return 0;
	}
	return 1;
}

int main(){
	SLAY
	int n;
	memset(prime , true , sizeof(prime));
	prime[0]=prime[1]=false;
	sieve();
	while(scanf("%d", &n)==1 && n){
		if(!prime[n] && check(n))
			printf("The number %d is a Carmichael number.\n", n);
		else 
			printf("%d is normal.\n", n);
	}
	return 0;
}