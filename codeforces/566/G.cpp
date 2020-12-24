#pragma optimize("unroll-loops")
#pragma optimize(3)
#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

pair<ll,ll> operator - (pair<ll,ll> a, pair<ll,ll> b){
	return make_pair(a.first-b.first,a.second-b.second);
}

ll cross(pair<ll,ll> a, pair<ll,ll> b){
	return a.first*b.second-a.second*b.first;
}

ll Pside(pair<ll,ll> a, pair<ll,ll> b, pair<ll,ll> c){
	// > 0 => c lies on the left side of (a,b)
	// < 0 => c lies on the right side of (a,b)
	// = 0 => c collinear with a,b
	return cross(b-a,c-a);
}

vector<pair<ll,ll>> getCH(vector<pair<ll,ll>> v){
	int n = v.size();
	sort(v.begin(),v.end());
	v.resize(unique(v.begin(),v.end())-v.begin());
	vector<pair<ll,ll>> hull;
	for(int i = 0;i < 2;i++){
		int t = (int)hull.size();
		for(auto x : v){
			while((int)hull.size()-t>=2&&cross(hull[(int)hull.size()-1]-hull[(int)hull.size()-2],x-hull[(int)hull.size()-2])<0)
				hull.pop_back();
			hull.push_back(x);
		}
		hull.pop_back();
		reverse(v.begin(), v.end());
	}
	return hull;
}

vector<pair<ll,ll>> p, tmp;
signed main(){
	fastio
	int n, m;
	cin >> n >> m;
	int x,y;
	cin >> x >> y;
	for(int i = 0;i < n;i++){
		int a,b;
		cin >> a >> b;
		p.push_back({a,b});
		tmp.push_back({a,b});
	}
	x = 0, y = 0;
	for(int i = 0;i < m;i++){
		int a,b;
		cin >> a >> b;
		p.push_back({a,b});
		x = max(a,x);
		y = max(b,x);
	}
	p.push_back({0,0});
	p.push_back({x,0});
	p.push_back({0,y});
	vector<pair<ll,ll>> CH = getCH(p);
	set<pair<int,int>> s(CH.begin(),CH.end());
	for(auto x : tmp){
		if(s.count(x)){
			cout << "Max\n";
			return 0;
		}
	}
	cout << "Min\n";
}