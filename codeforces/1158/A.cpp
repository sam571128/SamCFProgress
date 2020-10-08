#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n,m;
	cin >> n >> m;
	int arr1[n], arr2[m];
	int sum = 0;
	for(int i = 0;i < n;i++){
		cin >> arr1[i];
		sum += arr1[i];
	}
	sum *= m;
	for(int i = 0;i < m;i++){
		cin >> arr2[i];
		sum += arr2[i];
	}
	sort(arr1,arr1+n);
	sort(arr2,arr2+m);
	if(arr1[n-1] > arr2[0]) cout << -1 << "\n";
	else if(arr1[n-1]==arr2[0]) cout << sum - arr1[n-1]*m << '\n';
	else cout << sum-arr1[n-1]*m+arr1[n-1]-arr1[n-2] << "\n";
}