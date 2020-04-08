#include <bits/stdc++.h>

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

/********SAM571128's SOLUTION**********/
bool check[100005];
int d[100005];
int a[100005];
int main(){
	fastio
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = n;i > 0;i--){
		if(!check[a[i]])d[i]++;
		check[a[i]] = true;
	}
	for(int i = n;i>=1;i--){
		d[i]+=d[i+1];
	}
	while(m--){
		cini(temp);
		cout << d[temp] << "\n";
	}
	
}
