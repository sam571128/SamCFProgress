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
	int n;
	cin >> n;
	int id1 = 1,id2 = 1;
	vi v;
	while(n--){
		int a;
		cin >> a;
		v.pb(a);
	}
	int sorted = 1;
	for(int i = 0;i < v.size()-1;i++){
		if(v[i]>v[i+1]){
			sorted = 0;
		}
	}
	if(sorted){
		cout << "yes\n1 1";
		return 0;
	}
	for(int i = 0;i < v.size()-1;i++){
		if(v[i]>v[i+1]){
			id1 = i+1;
			break;
		}
	}
	for(int i = id1;i < v.size()-1;i++){
		if(v[i]<v[i+1]){
			id2 = i+1;
			break;
		}
	}
	if(id1>=id2){
		id2 = v.size();
	}
	sort(v.begin()+id1-1,v.begin()+id2);
	for(int i = 0;i < v.size()-1;i++){
		if(v[i]>v[i+1]){
			cout << "no";
			return 0;
		}
	}
	cout << "yes\n";
	cout << id1 << " " << id2 << "\n";
}
