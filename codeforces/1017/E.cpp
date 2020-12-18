#include <bits/stdc++.h>

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

template<typename T>
pair<T,T> operator - (pair<T,T> a, pair<T,T> b){
	return make_pair(a.first-b.first,a.second-b.second);
}

template<typename T>
T cross(pair<T,T> a, pair<T,T> b){
	return a.first*b.second-a.second*b.first;
}

template<typename T>
T dist(pair<T,T> a, pair<T,T> b){
	return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}

template<typename T>
vector<pair<T,T>> getCH(vector<pair<T,T>> v){
	int n = v.size();
	sort(v.begin(),v.end());
	vector<pair<T,T>> hull;
	for(int i = 0;i < 2;i++){
		int t = hull.size();
		for(auto x : v){
			while(hull.size()-t>=2&&cross(hull[hull.size()-1]-hull[hull.size()-2],x-hull[hull.size()-2])<=0)
				hull.pop_back();
			hull.push_back(x);
		}
		hull.pop_back();
		reverse(v.begin(), v.end());
	}
	return hull;
}

signed main(){
	fastio
	int n,m;
	cin >> n >> m;
	vector<pair<int,int>> p1, p2;
	for(int i = 0;i < n;i++){
		int x,y;
		cin >> x >> y;
		p1.push_back({x,y});
	}
	for(int i = 0;i < m;i++){
		int x,y;
		cin >> x >> y;
		p2.push_back({x,y});
	}
	vector<pair<int,int>> CH1 = getCH(p1), CH2 = getCH(p2);
	n = CH1.size(), m = CH2.size();
	if(n!=m){
		cout << "NO\n";
		return 0;
	}
	for(int k = 0;k < n;k++){
		bool ok = true;
		for(int i = 0;i < n;i++){
			pair<int,int> pA, pB, pC, pD, pE, pF;
			pA = CH1[i%n], pB = CH1[(i+1)%n], pC = CH1[(i+2)%n];
			pD = CH2[(i+k)%n], pE = CH2[(i+k+1)%n], pF = CH2[(i+k+2)%n];
			int dist1 = dist(pA,pB), dist2 = dist(pB,pC), dist3 = dist(pC,pA);
			int dist4 = dist(pD,pE), dist5 = dist(pE,pF), dist6 = dist(pF,pD);
			if(dist1!=dist4||dist2!=dist5||dist3!=dist6){
				ok = false;
				break;
			}
		}
		if(ok){
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
}