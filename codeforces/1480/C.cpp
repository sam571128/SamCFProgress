#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n;
	cin >> n;
	if(n==1){
		cout << "! " << 1 << endl;
		return 0;
	}
	int arr[n+2] = {};
	arr[0] = 1e18, arr[n+1] = 1e18;
	int l = 0, r = n;
	while(l+1 < r){
		int mid = l+r>>1;
		cout << "? " << mid+1 << endl;
		cin >> arr[mid+1];
		cout << "? " << mid << endl;
		cin >> arr[mid];
		if(arr[mid] > arr[mid+1]){
			l = mid;
		}else{
			r = mid;
		}
	}
	cout << "! " << l+1 << endl;
}