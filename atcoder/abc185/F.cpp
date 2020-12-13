#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 3e5+5;
int bit[N];

void update(int pos, int val){
	while(pos < N){
		bit[pos] ^= val;
		pos += pos&-pos;
	}
}

int query(int pos){
	if(pos==0) return 0;
	int res = 0;
	while(pos){
		res ^= bit[pos];
		pos -= pos&-pos;
	}
	return res;
}

signed main(){
	//fastio
	int n,q;
	cin >> n >> q;
	for(int i = 1;i <= n;i++){
		int tmp;
		cin >> tmp;
		update(i,tmp);
	}
	while(q--){
		int op;
		cin >> op;
		if(op==1){
			int x,y;
			cin >> x >> y;
			update(x,y);
		}else{
			int l,r;
			cin >> l >> r;
			//cout << query(r) << "\n";
			//cout << query(l-1) << "\n";
			cout << (query(r)^query(l-1)) << "\n";
		}
	}
}