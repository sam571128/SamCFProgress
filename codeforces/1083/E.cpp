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
	if(!t) return 0;
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
	Node *t = new Node({0,0});
	int ans = 0;
	vector<array<int,3>> v;
	for(int i = 0;i < n;i++){
		int x,y,z;
		cin >> x >> y >> z;
		v.push_back({x,y,z});
	}
	sort(v.begin(),v.end());
	int dp[n];
	for(int i = 0;i < n;i++){
		int a,b,c;
		a = v[i][0], b = v[i][1], c = v[i][2];
		dp[i] = a*b+query(t,b)-c;
		insert(t,{-a,dp[i]});
	}
	cout << *max_element(dp,dp+n) << "\n";
}