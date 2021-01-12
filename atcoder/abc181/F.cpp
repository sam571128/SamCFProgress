#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int N = 200;
int dsu[N];

int find(int u){
	return dsu[u]==u ? u : dsu[u] = find(dsu[u]);
}

void unite(int u, int v){
	u = find(u), v = find(v);
	if(u==v) return;
	dsu[u] = v;
}

double dist(pair<int,int> a, pair<int,int> b){
	return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}

signed main(){
	fastio
	iota(dsu,dsu+N,0);
	int n;
	cin >> n;
	pair<int,int> arr[n];
	for(auto &[a,b] : arr) cin >> a >> b;
	vector<pair<double,pair<int,int>>> v;
	int top = n, bottom = n+1;
	for(int i = 0;i < n;i++){
		//build edges for points and y = 100, y = -100
		v.push_back({abs(arr[i].second-(-100)),{i,bottom}}); 
		v.push_back({abs(arr[i].second-(100)),{i,top}});
	}
	for(int i = 0;i < n;i++){
		for(int j = i+1;j < n;j++){
			v.push_back({dist(arr[i],arr[j]),{i,j}});
		}
	}
	sort(v.begin(),v.end());
	for(auto [a,x] : v){
		auto [b,c] = x;
		unite(b,c);
		if(find(top)==find(bottom)){
			cout << fixed << setprecision(10) << a/2 << "\n";
			return 0;
		}
	}
}