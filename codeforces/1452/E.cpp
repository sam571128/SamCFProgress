#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n, m, k;
	cin >> n >> m >> k;
	vector<pair<int,int>> v;
	for(int i = 0;i < m;i++){
		int l,r;
		cin >> l >> r;
		l--;
		v.push_back({l,r});
	}
	sort(v.begin(),v.end(),[&](pair<int,int> a, pair<int,int> b){
		return a.first + a.second < b.first + b.second;
	});
	int arr[m+1] = {};
	for(int i = 0;i < n-k+1;i++){
		int tmp = 0;
		for(int j = m-1;~j;j--){
			tmp += max((int)0,min(i+k,v[j].second)-max(i,v[j].first));
			arr[j] = max(arr[j], tmp);
		}
	}
	int ans = arr[0];
	for(int i = 0;i < n-k+1;i++){
		int tmp = 0;
		for(int j = 0;j < m;j++){
			tmp += max((int)0,min(i+k,v[j].second)-max(i,v[j].first));
			ans = max(ans,arr[j+1]+tmp);
		}
	}
	cout << ans << "\n";
}