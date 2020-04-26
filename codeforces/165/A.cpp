#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define pf pop_front
#define cini(i) int i;cin>>i;
#define cinll(l) int l;cin >> l;
#define cins(s) string s;cin >> s;
#define intz(z) int z = 0;
using namespace std;
typedef vector<int> vi;
typedef vector<ll int> vll;
typedef vector<string> vs;
typedef vector< pair<int,int> > vpi;

int main(){
	fastio
	vpi v;
	int n;
	cin >> n;
	while(n--){
		int a,b;
		cin >> a >> b;
		v.pb(make_pair(a,b));
	}
	int count = 0;
	for(int i = 0;i < v.size();i++){
		bool right = false,left = false,up = false,down = false;
		for(int j = 0;j < v.size();j++){
			if(j!=i){
				if(v[i].first==v[j].first){
					if(v[j].second>v[i].second) up = true;
					else if(v[j].second<v[i].second) down = true;
				}else if(v[i].second==v[j].second){
					if(v[j].first>v[i].first) right = true;
					else if(v[j].first<v[i].first) left = true;
				}
			}
		}
		if(right&&left&&up&&down) count++;
	}
	cout << count << "\n";
}
