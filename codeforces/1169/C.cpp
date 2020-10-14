#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<int> arr;

bool check(int x, int m){
	int n = arr.size();
	int tmp = 0;
	for(int i = 0;i < n;i++){
		if(arr[i]+x<tmp) return false;
		if((arr[i]<=tmp&&tmp<=arr[i]+x)||(arr[i]<=tmp+m&&tmp+m<=arr[i]+x)) continue;
		tmp = arr[i];
	}
	return true;
}

void solve(){
	int n,m;
	cin >> n >> m;
	for(int i = 0, tmp;i < n;i++){
		cin >> tmp;
		arr.push_back(tmp);
	}
	int l = 0, r = m;
	while(l < r){
		int mid = l+r>>1;
		if(check(mid,m)) r = mid;
		else l = mid+1;
	}
	cout << l << "\n";
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}