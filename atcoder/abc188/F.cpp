#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int x,y;
	cin >> x >> y;
	int ans = 1e18;
	for(int i = 0;i <= 63;i++){
		if(x > LLONG_MAX/2) break;
		int sum = i;
		int diff = abs(x-y);
		sum += diff/(1LL<<i);
		diff %= (1LL<<i);
		for(int j = 0;j <= i;j++){
			if (diff&(1LL<<j)) {
				if (diff&(1LL<<j+1)) diff+=1LL<<j;
				else diff-=1LL<<j;
				sum++;
			}
		}
		ans = min(ans,sum);
		x *= 2;
	}
	cout << ans << "\n";
}