#include <bits/stdc++.h>
#include <bits/extc++.h>

//#define int long long
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

const int N = 1e6+5;
gp_hash_table<int,int,chash> bit[N];
void update(int idx, int pos, int val){
	if(pos==0) return;
	while(pos < N){
		bit[idx][pos] = max(bit[idx][pos],val);
		pos+=pos&-pos;
	}
}

int query(int idx, int pos){
	int res = 0;
	while(pos){
		res = max(bit[idx][pos],res);
		pos-=pos&-pos;
	}
	return res;
}

signed main(){
	fastio
	int n,m;
	cin >> n >> m;
	
	int ans = 0;
	while(m--){
		int u,v,w;
		cin >> u >> v >> w;
		int val = query(u,w);
		ans = max(ans,val+1);
		update(v,w+1,val+1);
	}
	cout << ans << "\n";
}