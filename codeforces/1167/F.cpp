#include <bits/stdc++.h>
#include <bits/extc++.h>
#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
using namespace __gnu_pbds;

const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return x ^ RANDOM; }
};
gp_hash_table<int, int, chash> m;

const int N = 5e5+5, MOD = 1e9+7;
int bit[N];

void update(int pos, int val){
	while(pos < N){
		bit[pos] = (bit[pos]+val)%MOD;
		pos += pos&-pos;
	}
}

int query(int pos){
	int res = 0;
	while(pos){
		res = (res + bit[pos])%MOD;
		pos -= pos&-pos;
	}
	return res;
}

signed main(){
	fastio
	int n;
	cin >> n;
	vector<int> arr(n);
	for(auto &x : arr) cin >> x;
	vector<int> tmp = arr;
	sort(tmp.begin(), tmp.end());
	for(int i = 0;i < n;i++){
		m[tmp[i]] = i+1;
	}
	int cnt[n] = {};
	for(int i = 0; i < n;i++){
		cnt[i] = (cnt[i] + query(m[arr[i]])*(n-i)%MOD)%MOD;
		update(m[arr[i]],i+1);
	}
	memset(bit,0,sizeof bit);
	for(int i = n-1;~i;i--){
		cnt[i] = (cnt[i] + query(m[arr[i]])*(i+1)%MOD)%MOD;
		update(m[arr[i]],n-i);
		cnt[i] = (cnt[i]+(n-i)*(i+1)%MOD)%MOD;
	}
	int ans = 0;
	for(int i = 0;i < n;i++){
		ans = (ans + cnt[i] * arr[i]%MOD)%MOD;
	}
	cout << ans << "\n";
}