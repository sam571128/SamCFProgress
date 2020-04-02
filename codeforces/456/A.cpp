#include <bits/stdc++.h>
#include <cmath>

#define ll long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
#define pop pop_front
#define cini(i) int i;cin>>i;
#define cinll(l) int l;cin >> l;
#define cins(s) string s;cin >> s;
#define intz(z) int z = 0;
using namespace std;
typedef vector<int> vi;
typedef vector<string> vs;

bool comp(pair<int,double> i,pair<int,double> j){
	return i.first < j.first;
}
int main(){
	fastio
	int t;
	cin >> t;
	vector< pair<int,double> > v;
	while(t--){
		int a;
		double b;
		cin >> a >> b;
		v.push(make_pair(a,b/a));
	}
	sort(v.begin(),v.end(),comp);
	for(int i = 1;i < v.size();i++){
		if(v[i].second<v[i-1].second){
			cout << "Happy Alex";
			return 0;
		}
	}
	cout << "Poor Alex";
}
