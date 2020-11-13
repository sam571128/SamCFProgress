#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

struct Line{
	int m,b;
	int operator()(int x) {
		return m*x+b;
	}
};

const int N = 1e9+5, INF = 1e18;

struct Node{
	Line seg;
	Node *ls, *rs;
	Node(Line l): seg(l), ls(nullptr), rs(nullptr){}
};

void insert(Node *t, Line seg, int l = 0, int r = N){
	if(l==r){
		if(seg(l) > t->seg(l)) t->seg = seg;
		return;
	}	
	int mid = l+r>>1;
	if(t->seg.m > seg.m) swap(t->seg,seg);
	if(t->seg(mid) < seg(mid)){
		swap(t->seg,seg);
		if(!t->ls) t->ls = new Node(seg);
		else insert(t->ls, seg, l,mid);
	}else{
		if(!t->rs) t->rs = new Node(seg);
		else insert(t->rs, seg, mid+1,r);
	}
}
int query(Node *t, int x, int l = 0, int r = N){
	if(!t) return -INF;
	if(l==r) return t->seg(x);
	int mid = l+r>>1;
	if(x < mid){
		return max(t->seg(x), query(t->ls, x, l, mid));
	}
	else{
		return max(t->seg(x),query(t->rs, x, mid+1,r));
	}
}

signed main(){
	fastio
	int n;
	cin >> n;
	int a[n], b[n];
	for(auto &x : a) cin >> x;
	for(auto &x : b) cin >> x;
	Node *t = new Node({-b[0],0});
	int dp[n]; 
	for(int i = 1;i < n;i++){
		dp[i] = -query(t,a[i]);
		insert(t,{-b[i],-dp[i]});
	}
	cout << dp[n-1] << "\n";
}