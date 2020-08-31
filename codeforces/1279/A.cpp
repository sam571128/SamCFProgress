//#pragma GCC optimize ("O3,unrolled-loops")
#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int t;
	cin >> t;
	while(t--){
		int arr[3];
		for(auto &x : arr) cin >> x;
		sort(arr,arr+3);
		if(arr[0]+arr[1]>=arr[2]-1){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}
	}
}