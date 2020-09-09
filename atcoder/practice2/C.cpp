#include <bits/stdc++.h>
#include <atcoder/all>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
using namespace atcoder;

signed main(){
	fastio
	int n;
	cin >> n;
	while(n--){
		int n,m,a,b;
		cin >> n >> m >> a >> b;
		cout << floor_sum(n,m,a,b) << "\n";
	}
}