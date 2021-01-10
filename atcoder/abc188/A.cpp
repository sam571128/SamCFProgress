#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int x,y;
	cin >> x >> y;
	if(abs(x-y) < 3) cout << "Yes\n";
	else cout << "No\n";
}