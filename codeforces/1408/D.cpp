#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e6+5;
int arr[N];

signed main(){
	fastio
	int n,m;
	cin >> n >> m;
	vector<pair<int,int>> rb,sl;
	for(int i = 0;i < n;i++){
		int x,y;
		cin >> x >> y;
		rb.push_back({x,y});
	}
	for(int i = 0;i < m;i++){
		int x,y;
		cin >> x >> y;
		sl.push_back({x,y});
	}
	for(auto x : rb){
		for(auto y : sl){
			if(x.first > y.first) continue;
			arr[y.first-x.first] = max(arr[y.first-x.first],y.second-x.second+1);
		}
	}
	int ans = INT_MAX;
	for(int i = N-1;~i;i--){
		arr[i] = max(arr[i],arr[i+1]);
		ans = min(arr[i]+i,ans);
	}
	cout << ans << "\n";
}