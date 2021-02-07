#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int a,b,n;
	cin >> a >> b >> n;
	int arr1[n], arr2[n];
	for(auto &x : arr1) cin >> x;
	for(auto &x : arr2) cin >> x;
	int sum = 0;
	for(int i = 0;i < n;i++){
		sum += (arr2[i]+a-1)/a*arr1[i];
	}
	for(int i = 0;i < n;i++){
		sum -= (arr2[i]+a-1)/a*arr1[i];
		b -= sum;
		if((b+arr1[i]-1)/arr1[i] >= (arr2[i]+a-1)/a){
			cout << "YES\n";
			return;
		}
		b+=sum;
		sum += (arr2[i]+a-1)/a*arr1[i];
	}
	cout << "NO\n";
}

signed main(){
	fastio
	int t = 1;
	cin >> t;
	while(t--) solve();
}