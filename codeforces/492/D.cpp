#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main(){
	fastio
	int n,x,y;
	cin >> n >> x >> y;
	vector<string> res;
	int cntx = 0;
	int cnty = 0;
	while(res.size()!=x+y){
		if((cntx+1)*1.0/x>(cnty+1)*1.0/y) cnty++, res.push_back("Vova");
		else if((cntx+1)*1.0/x<(cnty+1)*1.0/y) cntx++, res.push_back("Vanya");
		else cntx++,cnty++,res.push_back("Both"),res.push_back("Both");
	}
	while(n--){
		int q;
		cin >> q;
		cout << res[(q-1)%(x+y)] << "\n";
	}
}	