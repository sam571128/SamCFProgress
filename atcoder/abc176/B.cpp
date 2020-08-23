#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int ans = 0;
	string s;
	cin >> s;
	for(auto x : s){
		ans = (ans+(x-'0'));
	}
	cout << (ans%9==0 ? "Yes" : "No");
} 