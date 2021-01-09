#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int get(int n, int x){
	return min(n-x,x*(x-1)/2)+n-x;
}

void solve(){
	int n;
	cin >> n;
	int l = 0, r = n;
	while(r - l > 1){
		int mid = l+r>>1;
		if(get(n,mid) > get(n,mid+1)){
			r = mid;
		}else{
			l = mid;
		}
	}
	cout << get(n,l+1) << "\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}