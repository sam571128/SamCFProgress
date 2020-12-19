#include <bits/stdc++.h>
#include <bits/extc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
using namespace __gnu_pbds;

struct chash {
    const int RANDOM = (long long)(make_unique<char>().get()) ^ chrono::high_resolution_clock::now().time_since_epoch().count();
    static unsigned long long hash_f(unsigned long long x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    static unsigned hash_combine(unsigned a, unsigned b) { return a * 31 + b; }
    int operator()(int x) const { return hash_f(x)^RANDOM; }
};

const int N = 1e10+5;
gp_hash_table<int,int,chash> bit[2];

void update(int idx, int pos, int val){
	pos+=(int)1e9;
	while(pos < N){
		bit[idx][pos] += val;
		pos += pos&-pos;
	}
}

int query(int idx, int pos){
	pos+=(int)1e9;
	int res = 0;
	while(pos){
		res += bit[idx][pos];
		pos -= pos&-pos;
	}
	return res;
}

void solve(){
	int n;
	cin >> n;
	int ans = 0;
	for(int i = 0;i < n;i++){
		int tmp;
		cin >> tmp;
		ans += (query(0,N-1)-query(0,tmp))-(query(1,N-1)-query(1,tmp))*tmp-query(0,tmp-1)+query(1,tmp-1)*tmp;
		update(0,tmp,tmp);
		update(1,tmp,1);
	}
	cout << ans << "\n";
}

signed main(){
	fastio
	int t = 1;
	//cin >> t;
	while(t--) solve();
}