#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

void solve(){
	int n;
	cin >> n;
	int arr[n];
	for(auto &x : arr) cin >> x;
	int pref[n]; pref[0] = 1;
	for(int i = 1;i < n;i++){
		if(arr[i]>=arr[i-1]) pref[i] = pref[i-1] + 1;
		else pref[i] = 1;
	}
	int ind = n-1;
	for(int i = n-2;i >= 0;i--){
		if(arr[i]<arr[i+1]) break;
		ind = i+1; 
	}
	cout << ind-pref[ind-1] << "\n";
}

int main(){
	fastio
	int t;
	cin >> t;
	while(t--) solve();
}