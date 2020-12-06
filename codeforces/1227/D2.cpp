#include <bits/stdc++.h>
#include <bits/extc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
using namespace __gnu_pbds;

signed main(){
	fastio
	int n;
	cin >> n;
	int arr[n];
	for(auto &x : arr) cin >> x;
	vector<pair<int,int>> v;
	for(int i = 0;i < n;i++){
		v.push_back({arr[i],i});
	}
	sort(v.begin(),v.end(),[&](pair<int,int> a, pair<int,int> b){
		return a.first==b.first ? a.second < b.second : a.first > b.first;
	});
	int m;
	cin >> m;
	vector<pair<pair<int,int>,int>> q;
	for(int i = 0; i < m;i++){
		int a,b;
		cin >> a >> b;
		q.push_back({{a,b},i});
	}
	sort(q.begin(),q.end());
	tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> s;
	int ans[m];
	int cnt = 0;
	for(int i = 0;i < m;i++){
		while(cnt < q[i].first.first) s.insert(v[cnt].second),cnt++;
		ans[q[i].second] = arr[*s.find_by_order(q[i].first.second-1)];
	}
	for(auto x : ans) cout << x << "\n";
}