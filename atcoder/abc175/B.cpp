#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n;
	cin >> n;
	int a[n];
	for(auto &x : a) cin >> x;
	int ans = 0;
	for(int i = 0;i < n;i++){
		for(int j = i+1;j < n;j++){
			for(int k = j+1;k < n;k++){
				if(a[i]+a[j]<=a[k]||a[k]+a[j]<=a[i]||a[i]+a[k]<=a[j]||a[i]==a[j]||a[j]==a[k]||a[i]==a[k]) continue;
				ans ++;
			}
		}
	}
	cout << ans << "\n";

}