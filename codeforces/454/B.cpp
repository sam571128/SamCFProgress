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
	vi v;
	while(n--){
		int a;
		cin >> a;
		v.pb(a);
	}
	int count = 0;
	bool sorted = true;
	for(int i = 0;i < v.size()-1;i++){
		if(v[i]>v[i+1]){
			sorted = false;
			break;
		}
	}
	if(sorted){
		cout << 0;
		return 0;
	}
	for(int i = 0;i < v.size();i++){
		if(i==v.size()-1){
			if(v[i]>v[0])
				count++;
		}else{
			if(v[i] > v[i+1])
				count++;
		}
	}
	if(count>1){
		cout << -1;
		return 0;
	}else{
		int index = -1;
		for(int i = 1;i < v.size();i++){
			if(v[i]<v[i-1]){
				index = i;
				break;
			}
		}
		cout << v.size()-index;
	}
}
