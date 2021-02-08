#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int M = 1e3+5;

bitset<M> inv;
struct node{
	int lc = 0, rc = 0, num = 0;
	bitset<M> bs;
} t[(int)1e6+(int)5e5];

vector<int> v;
int cnt = 1;

void update(int lst, int &idx, int l, int r, int pos){
	idx = cnt++;
	t[idx] = t[lst];
	if(l==r){
		t[idx].bs^=inv, t[idx].num = t[idx].bs.count();
	}
	else{
		int mid = l+r>>1;
		if(pos <= mid) update(t[lst].lc,t[idx].lc,l,mid,pos);
		else update(t[lst].rc,t[idx].rc,mid+1,r,pos);
		t[idx].num = t[t[idx].lc].num+t[t[idx].rc].num;
	}
}

void add(int lst, int &idx, int l, int r, int pos, int pos2, int val){
	idx = cnt++;
	t[idx] = t[lst];
	if(l==r){
		t[idx].bs[pos2] = val, t[idx].num = t[idx].bs.count();
	}
	else{
		int mid = l+r>>1;
		if(pos <= mid) add(t[lst].lc,t[idx].lc,l,mid,pos,pos2,val);
		else add(t[lst].rc,t[idx].rc,mid+1,r,pos,pos2,val);
		t[idx].num = t[t[idx].lc].num+t[t[idx].rc].num;
	}
}

signed main(){
	fastio
	//freopen("output.txt", "r" , stdin);
	int n,m,q;
	cin >> n >> m >> q;
	for(int i = 0;i < m;i++){
		inv[i] = 1;
	}
	v.reserve((int)1e5+5);
	v.push_back(0);
	for(int i = 0;i < q;i++){
		int op;
		cin >> op;
		if(op==1){
			int a,b;
			cin >> a >> b;
			a--,b--;
			int idx, idx2;
			add(v.back(),idx,0,n-1,a,b,1);
			v.push_back(idx);
		}else if(op==2){
			int a,b;
			cin >> a >> b;
			a--,b--;
			int idx;
			add(v.back(),idx,0,n-1,a,b,0);
			v.push_back(idx);
		}else if(op==3){
			int a;
			cin >> a;
			a--;
			int idx;
			update(v.back(),idx,0,n-1,a);
			v.push_back(idx);
		}else{
			int k;
			cin >> k;
			v.push_back(v[k]);
		}
		cout << t[v.back()].num << "\n";
	}
}