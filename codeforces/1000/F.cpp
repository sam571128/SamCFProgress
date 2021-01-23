#pragma optimize("Ofast")
#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 5e5+5;
int k;

int a[N], cnt[N], bid[N], bcnt[N], l = 1, r = 0, ok;
	
struct query{
	int l,r, id;
	bool operator < (const query b){
		if(l/k!=b.l/k) return l < b.l;
		if((l/k) &1) return r < b.r;
		return r > b.r;
	}
};

void add(int pos){
	if(cnt[a[pos]]==1) bcnt[bid[a[pos]]]--, ok--;
	cnt[a[pos]]++;
	if(cnt[a[pos]]==1) bcnt[bid[a[pos]]]++, ok++;
}

void sub(int pos){
	if(cnt[a[pos]]==1) bcnt[bid[a[pos]]]--, ok--;
	cnt[a[pos]]--;
	if(cnt[a[pos]]==1) bcnt[bid[a[pos]]]++, ok++;
}

int findnum(){
	if(!ok) return 0;
	for(int i = 0;i <= k;i++){
		if(!bcnt[i]) continue;
		for(int j = i*k;j < min((i+1)*k,N);j++){
			if(cnt[j]==1){
				return j;
			}
		}
	}
}
signed main(){
	fastio
	int n;
	cin >> n;
	k = sqrt(n);
	for(int i = 0;i < N;i++){
		bid[i] = i/k;
	}
	for(int i = 1;i <= n;i++) cin >> a[i];
	int m;
	cin >> m;
	vector<query> Q;
	int ans[m];
	for(int i = 0;i < m;i++){
		int ql, qr;
		cin >> ql >> qr;
		Q.push_back({ql,qr,i});
	}
	sort(Q.begin(),Q.end());
	for(auto q : Q){
		while(l < q.l) sub(l++);
		while(l > q.l) add(--l);
		while(r < q.r) add(++r);
		while(r > q.r) sub(r--);
		ans[q.id] = findnum();
	}
	for(auto x : ans) cout << x << "\n";
}