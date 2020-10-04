#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 1e5+5;
int k;
struct query{
	int l, r, id;
	bool operator < (query b){
		return (l/k == b.l/k ? r < b.r : l/k < b.l/k); 
	}
};

int arr[N], pref[N], cnt[1<<20], tmp, num;

void add(int val){
	tmp += cnt[val ^ num];
	cnt[val]++;
}

void sub(int val){
	cnt[val]--;
	tmp -= cnt[val ^ num];
}

signed main(){
	fastio
	int n,m;
	cin >> n >> m >> num;
	k = sqrt(n);
	for(int i = 1;i <= n;i++){
		cin >> arr[i];
		pref[i] = pref[i-1]^arr[i];
	}
	vector<query> Q;
	int ans[m];
	for(int i = 0;i < m;i++){
		int l,r;
		cin >> l >> r;
		l--;
		Q.push_back({l,r,i});
	}
	sort(Q.begin(),Q.end());
	int l = 1, r = 0;
	for(auto q : Q){
		while(l < q.l) sub(pref[l++]);
		while(l > q.l) add(pref[--l]);
		while(r < q.r) add(pref[++r]);
		while(r > q.r) sub(pref[r--]);
		ans[q.id] = tmp;
	}
	for(auto x : ans) cout << x << "\n";
}
/*
6 1 3
1 2 1 1 0 3
1 2
*/