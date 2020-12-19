#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n,m;
	cin >> n >> m;
	if(n==1){
		int num;
		cin >> num;
		while(m--){
			int tt;
			cin >> tt;
			cout << num+tt << " ";
		}
		return 0;
	}
	int arr[n];
	for(auto &x : arr)  cin >> x;
	sort(arr,arr+n);
	int num = arr[1] - arr[0];
	for(int i = 2;i < n;i++){
		num = gcd(num,arr[i]-arr[i-1]);
	}
	while(m--){
		int tt;
		cin >> tt;
		cout << gcd(num,tt+arr[0]) << " ";
	}
}