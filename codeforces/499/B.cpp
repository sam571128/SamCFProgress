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
	int x,y;
	cin >> x >> y;
	map<string,string> m;
	while(y--){
		string a,b;
		cin >> a >> b;
		string temp;
		if(a.size()>b.size()){
			temp = b;
		}else{
			temp = a;
		}
		m[a] = temp;
		m[b] = temp;
	}
	for(int i = 0;i < x;i++){
		if(i!=0){
			cout << " ";
		}
		string a;
		cin >> a;
		cout << m[a];
	}
}
