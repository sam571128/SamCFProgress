#pragma GCC optimize(2)
#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 3e5+5;
int k;
struct query{
	int l,r,id;
	bool operator < (query b){
		return (l/k == b.l/k ? r < b.r : l/k < b.l/k); 
	}
};

int arr[N], pref[N], tmp, num, up[N], down[N];
int cnt[N];

void addl(int i){
	tmp += cnt[up[i]];
	cnt[arr[i]]++;
}

void addr(int i){
	tmp += cnt[down[i]];
	cnt[arr[i]]++;
}

void subl(int i){
	cnt[arr[i]]--;
	tmp -= cnt[up[i]];
}

void subr(int i){
	cnt[arr[i]]--;
	tmp -= cnt[down[i]];
}

signed main(){
	fastio
	int n;
	cin >> n >> num;
	k = sqrt(n);
	for(int i = 1;i <= n;i++){
		cin >> arr[i];
		if(arr[i]==2) arr[i] = -1;
	}
	for(int i = 1, a; i <= n;i++){
		cin >> a;
		arr[i]*=a;
	}
	for(int i = 1;i <= n;i++){
		pref[i] = pref[i-1] + arr[i];
	}
	vector<int> v;
	for(int i = 0;i <= n;i++){
		v.push_back(pref[i]);
		v.push_back(pref[i]+num);
		v.push_back(pref[i]-num);
	}
	sort(v.begin(),v.end());
	v.resize(unique(v.begin(),v.end())-v.begin());
	for(int i = 0;i <= n;i++){
		arr[i] = lower_bound(v.begin(),v.end(),pref[i]) - v.begin() + 1;
		up[i] = lower_bound(v.begin(),v.end(),pref[i]+num) - v.begin() + 1;
		down[i] = lower_bound(v.begin(),v.end(),pref[i]-num) - v.begin() + 1;
	}
	int m;
	cin >> m;
	int ans[m];
	vector<query> Q;
	for(int i = 0;i < m;i++){
		int l,r;
		cin >> l >> r;
		l--;
		Q.push_back({l,r,i});
	}
	sort(Q.begin(),Q.end());
	int l = 0, r = -1;
	for(auto q : Q){
		while(l < q.l) subl(l++);
		while(l > q.l) addl(--l);
		while(r < q.r) addr(++r);
		while(r > q.r) subr(r--);
		ans[q.id] = tmp;
	}
	for(auto x : ans) cout << x << "\n";
}