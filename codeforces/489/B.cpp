#include <bits/stdc++.h>

#define ll long long 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define push push_back
#define pop pop_front
#define cini(i) int i;cin>>i;
#define cinll(l) int l;cin >> l;
#define intz(z) int z = 0;
using namespace std;
typedef vector<int> vi; 

int main(){
	fastio
	int n;
	cin >> n;
	vi b;
	while(n--){
		cini(temp);
		b.push(temp);
	} 
	int m;
	cin >> m;
	vi g;
	while(m--){
		cini(temp);
		g.push(temp);
	}
	sort(b.begin(),b.end());
	sort(g.begin(),g.end());
	int result = 0;
	for(int i = 0;i < b.size();i++){
		for(int j = 0;j < g.size();j++){
			if(abs(b[i]-g[j])<=1){
				g[j] = 100000;
				result++;
				break;
			}
		}
	}
	cout << result;
}