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

void insert(Node *t, Line seg, int l = -N, int r = N){
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
int query(Node *t, int x, int l = -N, int r = N){
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
	int arr[n], pref[n+1] = {};
	int ans = 0;
	for(int i = 0;i < n;i++){
		cin >> arr[i];
		ans += (i+1)*arr[i];
		pref[i+1] = pref[i] + arr[i];
	} 
	int dp[n] = {};
	Node *t = new Node({0,0});
	for(int i = 0;i < n;i++){
		dp[i] = max((int)0,query(t,arr[i])+pref[i+1]-(i+1)*arr[i]);
		insert(t,{i+1,-pref[i+1]});
	}
	int tmp = ans+*max_element(dp,dp+n);
	memset(dp,0,sizeof dp);
	delete t;
	t = new Node({0,0});
	for(int i = n-1;~i;i--){
		dp[i] = max((int)0,query(t,arr[i])+pref[i+1]-(i+1)*arr[i]);
		insert(t,{i+1,-pref[i+1]});
	}
	tmp = max(tmp,ans+*max_element(dp,dp+n));
	cout << tmp << "\n";
}