#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e5+5;
int bit[N], arr[N];

void modify(int pos, int val){
	while(pos < N){
		bit[pos] += val;
		pos += pos&-pos;
	}
}

int query(int pos){
	int res = 0;
	while(pos){
		res += bit[pos];
		pos -= pos&-pos;
	}
	return res;
}

void solve(){
	int n;
	cin >> n;
	int ma = 0;
	for(int i = 0,tmp;i < n;i++){
		cin >> tmp;
		ma = max(tmp,ma);
		int cnt = query(tmp);
		if(cnt==i) arr[ma]--;
		if(cnt==i-1) arr[ma]++;
		modify(tmp,1);
	}
	int ans = 1, cnt = -1;
	for(int i = 1;i <= n;i++){
		if(arr[i] > cnt){
			cnt = arr[i];
			ans = i;
		}
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}