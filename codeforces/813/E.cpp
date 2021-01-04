#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
 
const int N = 1e5+5;
vector<int> bit[N], arr[N];

void update(int pos, int val){
	while(pos < N){
		bit[pos].push_back(val);
		pos += pos & -pos;
	}
}

int query(int pos, int val){
	int res = 0;
	while(pos){
		res += upper_bound(bit[pos].begin(),bit[pos].end(),val) - bit[pos].begin();
		pos -= pos&-pos;
	}
	return res;
}

signed main(){
	fastio
	int n,k;
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		int tmp;
		cin >> tmp;
		arr[tmp].push_back(i);
	}
	for(int i = 1;i < N;i++){
		for(int j = k;j < arr[i].size();j++){
			update(arr[i][j-k],arr[i][j]);
		}
	}
	for(int i = 1;i < N;i++){
		sort(bit[i].begin(),bit[i].end());
	}
	int q, last = 0;
	cin >> q;
	while(q--){
		int x,y;
		cin >> x >> y;
		int l = (x+last)%n+1, r = (y+last)%n+1;
		if(l > r) swap(l,r);
		last = r-l+1-query(n,r)+query(l-1,r);
		cout << last << "\n";
	}
}