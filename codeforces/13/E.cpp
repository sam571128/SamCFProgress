#pragma GCC optimize ("O3,unrolled-loops")
#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e5+10;
int p[N], cnt[N], nxt[N], lst[N];
int k;
int n;

void update(int a, int b){
	if(b>n) cnt[a] = 1, nxt[a] = 0, lst[a] = a;
	else if((b)/k==a/k) cnt[a] = cnt[a+p[a]]+1, nxt[a] = nxt[a+p[a]], lst[a] = lst[a+p[a]];
	else cnt[a] = 1, nxt[a] = a+p[a];
}

void query(int a){
	int ans = 0, idx;
	while(a){ 
		ans += cnt[a];
		idx = lst[a];
		a = nxt[a];
	}
	cout << idx << " " << ans << "\n";
}

signed main(){
	fastio
	int m;
	cin >> n >> m;
	k = sqrt(n);
	for(int i = 1;i <= n;i++) cin >> p[i];
	for(int i = n;i;i--){
		update(i,i+p[i]);
	}
	while(m--){
		int v;
		cin >> v;
		if(v==0){
			int a,b;
			cin >> a >> b;
			p[a] = b;
			for(int i = a;i >= (a/k)*k;i--){
				update(i,i+p[i]);
			}
		}else{
			int a;
			cin >> a;
			query(a);
		}
	}
}