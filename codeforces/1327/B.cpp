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

int main(){
	fastio
	int t;
	cin >> t;
	while(t--){
		int a;
		cin >> a;
		vi adj[a+1];
		bool opti = true;
		for(int i = 1;i <= a;i++){
			int b;
			cin >> b;
			while(b--){
				int temp;
				cin >> temp;
				adj[i].pb(temp);
			}
		}
		vi marriedprc(a+1,0);
		vi marriedpr(a+1,0);
		for(int i = 1;i <= a;i++){
			for(int j = 0;j < adj[i].size();j++){
				if(!marriedpr[adj[i][j]]){
					marriedprc[i] = 1;
					marriedpr[adj[i][j]] = 1;
					break;
				}
			}
		}
		for(int i = 1;i <= a;i++){
			if(!marriedprc[i]){
				cout << "IMPROVE\n" << i << " ";
				for(int j = 1;j < marriedpr.size();j++){
					if(!marriedpr[j]){
						cout << j << "\n";
						break;
					}
				}
				opti = false;
				break;
			}
		}
		if(opti){
			cout << "OPTIMAL\n";
		}
	}
}
