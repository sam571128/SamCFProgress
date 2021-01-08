#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int a,b,c;
	cin >> a >> b >> c;
	vector<int> v1(a), v2(b), v3(c);
	for(auto &x : v1) cin >> x;
	for(auto &x : v2) cin >> x;
	for(auto &x : v3) cin >> x;
	int arr[3];
	arr[0] = *min_element(v1.begin(),v1.end()), arr[1] = *min_element(v2.begin(),v2.end()), arr[2] = *min_element(v3.begin(),v3.end());
	sort(arr,arr+3);
	int ans = arr[0]+arr[1];
	int sum = accumulate(v1.begin(),v1.end(),0LL)+accumulate(v2.begin(),v2.end(),0LL)+accumulate(v3.begin(),v3.end(),0LL);
	ans = min(ans,accumulate(v1.begin(),v1.end(),0LL));
	ans = min(ans,accumulate(v2.begin(),v2.end(),0LL));
	ans = min(ans,accumulate(v3.begin(),v3.end(),0LL));
	cout << sum-2*ans << "\n";
}