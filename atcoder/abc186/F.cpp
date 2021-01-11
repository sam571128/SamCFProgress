#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 2e5+5;
int bit[N], row[N], col[N];
vector<int> tt[N];

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

signed main(){
	fastio
	int h,w,m;
	cin >> h >> w >> m;
	fill(row,row+N,w);
	fill(col,col+N,h);
	while(m--){
		int x,y;
		cin >> x >> y;
		x--,y--;
		row[x] = min(row[x],y);
		col[y] = min(col[y],x);
		tt[y].push_back(x);
	}
	int ans = 0;
	int i;
	for(i = 0;i < h&&row[i];i++) ans += row[i];
	int ok[h];
	fill(ok,ok+h,1);
	for(;i < h;i++) ok[i] = 0, update(i,1);
	for(i = 0;i < w&&col[i];i++){
		for(int j : tt[i]){
			if(ok[j]) ok[j] = 0, update(j,1);
		}
		ans += query(col[i]-1);
	}
	cout << ans << "\n";
}

/*
	*	*	*	*
	*	*	X	*
	*	X	*	X
	*	*	*	*
*/