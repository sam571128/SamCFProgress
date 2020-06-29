#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n, sum = 0, ans = 0;
	cin >> n;
	int a[n];
	for(int i = 0;i < n;i++) cin >> a[i], sum += a[i];
	sort(a,a+n);
	for(int i = 0;i < n;i++){
		if(a[i]!=0) continue;
		sum++, ans++;
	}
	if(sum == 0) ans++;
	cout << ans << "\n"; 
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}