#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define s_itr set<Node>::iterator

using namespace std;

const int MOD = 1e9+7;

int fastpow(int n,int p, int y){
	n%=y;
	int res = 1;
	while(p){
		if(p&1) res = res * n %y;
		n = n*n %y;
		p>>=1;
	}
	return res;
}

int seed;
int rnd(){
	int ret = seed;
	seed = (seed*7+13)%MOD;
	return ret;
}

struct Node{
	int l,r; mutable int v;
	Node(int a, int b = 0, int c = 0){
		l = a, r = b , v = c;
	}
	bool operator < (const Node b) const{
		return l < b.l;
	}
};

set<Node> s;

s_itr split(int pos){
	s_itr itr = s.lower_bound(Node(pos));
	if(itr!=s.end()&&itr->l==pos) return itr;
	itr--;
	int l = itr->l, r = itr->r;
	int v = itr->v;
	s.erase(itr);
	s.insert(Node(l,pos-1,v));
	return s.insert(Node(pos,r,v)).first;
}

void assign(int l, int r, int val){
	s_itr itr1 = split(l), itr2 = split(r+1);
	s.erase(itr1,itr2);
	s.insert(Node(l,r,val));
}

void add(int l, int r, int val){
	s_itr itr1 = split(l), itr2 = split(r+1);
	for(auto itr = itr1; itr!=itr2;itr++)
		itr->v+=val;
}

int rk(int l, int r, int k){
	s_itr itr1 = split(l), itr2 = split(r+1);
	vector<pair<int,int>> v;
	for(auto itr = itr1;itr!=itr2;itr++){
		v.push_back({itr->v,itr->r-itr->l+1});
	}
	sort(v.begin(),v.end());
	for(int i = 0;i < v.size();i++){
		k -= v[i].second;
		if(k <= 0) return v[i].first;
	}
	return 0;
}

int query(int l, int r, int x, int y){
	s_itr itr1 = split(l), itr2 = split(r+1);
	int sum = 0;
	for(auto itr = itr1; itr != itr2;itr++){
		sum = (sum+(itr->r-itr->l+1)*fastpow(itr->v,x,y))%y;
	}
	return sum;
}

signed main(){
	fastio
	int n,m,vmax;
	cin >> n >> m >> seed >> vmax;
	for(int i = 1;i <= n;i++){
		int tmp = rnd()%vmax+1;
		s.insert(Node(i,i,tmp));
		//cout << tmp << " ";
	}
	s.insert(Node(n+1,n+1,0));
	//cout << "\n";
	while(m--){
		int op = rnd()%4+1, l = rnd()%n+1, r = rnd()%n+1;
		if(l > r) swap(l,r);
		if(op==1){
			int x = rnd()%vmax+1;
			add(l,r,x);
		}else if(op==2){
			int x = rnd()%vmax+1;
			assign(l,r,x);
		}else if(op==3){
			int x = rnd()%(r-l+1)+1;
			cout << rk(l,r,x) << "\n";
		}else if(op==4){
			int x = rnd()%vmax+1, y = rnd()%vmax+1;
			//cout << op << " " << l << " " << r << " " << x << " " << y << "\n";
			cout << query(l,r,x,y) << "\n";
		}
	}
}