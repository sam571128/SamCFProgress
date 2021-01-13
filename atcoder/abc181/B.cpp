#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n;
	cin >> n;
	int ans = 0;
	for(int i = 0;i < n;i++){
		int a,b;
		cin >> a >> b;
		ans += (a+b)*(abs(a-b)+1)/2;
	}
	cout << ans << "\n";
}