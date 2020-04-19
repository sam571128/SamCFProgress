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
	int n,m;
	cin >> n >> m;
	vi v;
	for(int i = 0,temp;i < n;i++){
		cin >> temp;
		v.pb(temp);
	}
	vi w;
	for(int i = 0,temp;i < m;i++){
		cin >> temp;
		w.pb(temp);
	}
	int mi = *max_element(v.begin(),v.end());
	int ma = *min_element(w.begin(),w.end());
	sort(v.begin(),v.end());
	int temp;
	for(int i = mi;i < ma;i++){
		temp = i;
		if(v[0]*2<=i){
			break;
		}
	}
	if(v[0]*2>temp){
		cout << "-1";
	}else{
		cout << temp;
	}
}
