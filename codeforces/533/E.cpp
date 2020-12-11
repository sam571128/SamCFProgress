#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n;
	cin >> n;
	string a,b;
	cin >> a >> b;
	int l = n, r = -1;
	for(int i = 0;i < n;i++){
		if(a[i]!=b[i]){
			l = min(l,i);
			r = max(r,i);
		}
	}
	int ans = (a.substr(l,r-l)==b.substr(l+1,r-l)) + (a.substr(l+1,r-l)==b.substr(l,r-l));
	cout << ans << "\n";
}