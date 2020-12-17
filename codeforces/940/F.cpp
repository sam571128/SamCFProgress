#include <bits/stdc++.h>
#include <bits/extc++.h>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
using namespace __gnu_pbds;

const int N = 2e5+5e4;
const int S = 1e6+5;
int k;

struct query{
	int l, r, t, id;
	bool operator < (query b){
		return (l/k==b.l/k  ? (r/k == b.r/k ? t < b.t : r/k < b.r/k) : l/k < b.l/k);
	}
} Q[N];


struct upd{
	int pos,x;
} M[N];	

int arr[N], cnt[S], ans[N], cnt2[N];

gp_hash_table<int,int> h;

void add(int val){
	cnt[cnt2[val]]--;
	cnt[cnt2[val]+1]++;
	cnt2[val]++;
}

void sub(int val){
	cnt[cnt2[val]]--;
	cnt[cnt2[val]-1]++;
	cnt2[val]--;
}

void modify(query x, upd &y){
	if(x.l <= y.pos && y.pos <= x.r){
		sub(h[arr[y.pos]]);
		add(h[y.x]);
	}
	swap(arr[y.pos],y.x);
}

signed main(){
	fastio
	int n, m;
	cin >> n >> m;
	k = pow(n,(double)2/(double)3);
	vector<int> tmp;
	for(int i = 1;i <= n;i++){
		cin >> arr[i];
		tmp.push_back(arr[i]);
	}
	int tid = 0, qid = 0;
	for(int i = 0;i < m;i++){
		int q;
		cin >> q;
		if(q==1){
			int l, r;
			cin >> l >> r;
			Q[qid] = {l,r,tid,qid};
			qid++;
		}else{
			int x, val;
			cin >> x >> val;
			tmp.push_back(val);
			++tid;
			M[tid] = {x,val};
		}
	}
	sort(tmp.begin(),tmp.end());
	tmp.resize(unique(tmp.begin(),tmp.end())-tmp.begin());
	for(int i = 0;i < tmp.size();i++){
		h[tmp[i]] = i;
	}

	sort(Q,Q+qid);
	int l = 1, r = 0, t = 0;
	for(int i = 0;i < qid;i++){
		auto q = Q[i];
		while(l < q.l) sub(h[arr[l++]]);
		while(l > q.l) add(h[arr[--l]]);
		while(r < q.r) add(h[arr[++r]]);
		while(r > q.r) sub(h[arr[r--]]);
		while(t < q.t) modify(Q[i],M[++t]);
		while(t > q.t) modify(Q[i],M[t--]);
		for(int j = 1;;j++)
			if(cnt[j]==0){
				ans[q.id] = j;
				break;
			}
	}
	for(int i = 0;i < qid;i++) cout << ans[i] << "\n";
}