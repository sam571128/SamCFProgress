#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

signed main(){
	fastio
	int n,m;
	cin >> n >> m;
	vector<pair<int,int>> v;
	for(int i = 0;i < n;i++){
		int x,y;
		cin >> x >> y;
		v.push_back({x,y});
	}
	int arr[101] = {};
	arr[0] = 1;
	sort(v.begin(),v.end());
	for(int i = 0;i < n;i++){
		if(!arr[v[i].first]){
			continue;
		}
		for(int j = v[i].first; j <= v[i].second;j++){
			arr[j]++;
		}
	}
	if(arr[m]) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}