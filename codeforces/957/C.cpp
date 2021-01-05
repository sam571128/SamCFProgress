#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n,m;
	cin >> n >> m;
	int arr[n];
	set<int,greater<int>> s;
	for(int i = 0;i < n;i++){
		int tmp;
		cin >> tmp;
		arr[i] = tmp;
		s.insert(tmp);
	}
	double ans = -1;
	s.erase(arr[0]);
	for(int i = 0;i < n;i++){
		s.erase(arr[i+1]);
		auto itr = s.lower_bound(arr[i]+m);
		if(itr==s.end()) continue;
		ans = max(1.0*(*itr-arr[i+1])/(*itr-arr[i]),ans);
	}
	cout << setprecision(10) << fixed << ans << "\n";
}