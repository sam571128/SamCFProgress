#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e6+5;
int bit[N];

void update(int pos, int val){
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

map<int,int> cnt;
signed main(){
	fastio
	int n;
	cin >> n;
	int arr[n], tmp[n];
	for(auto &x : arr) cin >> x;
	for(int i = 0;i < n;i++){
		int x = arr[i];
		cnt[x]++;
		update(cnt[x],1);
		tmp[i] = cnt[x];
	}
	cnt.clear();
	int ans = 0;
	for(int i = n-1;~i;i--){
		int x = arr[i];
		update(tmp[i],-1);
		cnt[x]++;
		ans += query(N)-query(cnt[x]);
	}
	cout << ans << "\n";
}