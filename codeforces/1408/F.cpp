#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<pair<int,int>> ans;

void change(int x, int y){
	if(x==y) return;
	int mid = x+y>>1;
	change(x,mid);
	change(mid+1,y);
	for(int i = x;i <= mid;i++){
		ans.push_back({i,mid+i-x+1});
	}
}

signed main(){
	fastio
	int n;
	cin >> n;
	int tmp = 1 << __lg(n);
	change(1,tmp);
	change(n-tmp+1,n);
	cout << ans.size() << "\n";
	for(auto x : ans) cout << x.first << " " << x.second << "\n";
}