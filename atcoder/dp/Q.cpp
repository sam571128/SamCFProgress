#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;


const int N = 2e5+5;

int h[N], a[N], BIT[N];
int n;

void update(int i, int v){
	while(i < N){
		BIT[i] = max(BIT[i],v);
		i += i&-i;
	}
}

int query(int i){
	int ans = 0;
	while(i){
		ans = max(ans,BIT[i]);
		i -= i&-i;
	}
	return ans;
}

signed main(){
	fastio
	cin >> n;
	for(int i = 0;i < n;i++) cin >> h[i];
	for(int i = 0;i < n;i++) cin >> a[i];
	for(int i = 0;i < n;i++){
		update(h[i],query(h[i])+a[i]);
	}
	cout << query(n) << "\n";
}