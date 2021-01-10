#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n;
	cin >> n;
	int a[n];
	int sum = 0;
	for(auto &x : a) cin >> x;
	for(auto x : a){
		int y;
		cin >> y;
		sum += x*y;
	}
	cout << (sum==0 ? "Yes\n" : "No\n");
}