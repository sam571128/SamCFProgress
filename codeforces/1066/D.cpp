#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n,m,k;
	cin >> n >> m >> k;
	int arr[n];
	for(auto &x : arr) cin >> x;
	reverse(arr,arr+n);
	int now = 0, cnt = 0;
	m--;
	for(auto x : arr){
		if(x+now > k&&k >= now){
			if(m==0){
				cout << cnt << "\n";
				return 0;
			}
			m--, now = x;
		}else{
			now += x;
		}
		cnt++;
	}
	cout << cnt << "\n";
}