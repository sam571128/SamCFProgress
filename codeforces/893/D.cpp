#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n,d;
	cin >> n >> d;
	int arr[n], now = 0;
	bool ok = true;
	for(int i = 0;i < n;i++){
		cin >> arr[i];
		now += arr[i];
		if(arr[i]==0) now = max((int)0,now);
		if(now > d){
			ok = false;
		}
	}
	if(!ok){
		cout << "-1\n";
		return 0;
	}
	int ans = 0; now = 0;
	for(int i = 0;i < n;i++){
		now += arr[i];
		if(now > d) now = d;
		if(arr[i]==0){
			if(now < 0) ans++, now = d;
		}
	}
	cout << ans << "\n";
}