#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int arr[n];
	bool ok = false;
	for(auto &x : arr) cin >> x;
	for(int i = 0; i < n;i++){
		for(int j = i+2;j < n;j++){
			if(arr[i]==arr[j]) ok = 1;
		}
	}
	cout << (ok ? "YES\n" : "NO\n");
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}