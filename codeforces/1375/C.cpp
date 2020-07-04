#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int arr[n];
	for(auto &x : arr) cin >> x;
	cout << (arr[0] < arr[n-1] ? "YES\n" : "NO\n");
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}