#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n;
	cin >> n;
	vector<pair<int,int>> v;
	int sum = 0, sum2 = 0;
	for(int i = 0;i < n;i++){
		int x,y;
		cin >> x >> y;
		v.push_back({x,y});
		sum += x+y;
	}
	sort(v.begin(),v.end(),[&](pair<int,int> a, pair<int,int> b){
		return 2*a.first + a.second < 2*b.first + b.second;
	});
	int ans = n;
	for(int i = 0;i < n;i++){
		sum2 += v[i].first;
		sum -= v[i].first+v[i].second;
		if(sum > sum2) ans = min(n-i-1,ans);
	}
	cout << ans << "\n";
}