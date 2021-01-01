#pragma comment(linker,"/stack:200000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

bool check(int n){
	int tmp = n;
	int g = 1;
	while(n){
		if(n%10!=0) g = lcm(g,n%10);
		n/=10;
	}
	return tmp%g==0;
}

void solve(){
	int n;
	cin >> n;
	while(true){
		if(check(n)){
			cout << n << "\n";
			return; 
		}
		n++;
	}
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}