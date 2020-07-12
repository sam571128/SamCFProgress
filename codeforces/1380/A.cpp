#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int arr[n];
	for(auto &x : arr) cin >> x;
	for(int i = 1;i < n-1;i++){
		if(arr[i] > arr[i-1]&&arr[i] > arr[i+1]){
			cout << "YES\n";
			cout << i << " " << i+1 << " " << i+2 << "\n";
			return;
		}
	}
	cout << "NO\n";
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}