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
#define pushcin(v) int temp;cin >> temp;v.push(temp);
using namespace std;
typedef vector<int> vi;
typedef vector<string> vs;

int main(){
	fastio
	int n,m,k;
	cin >> n >> m >> k;
	vi v;
	for(int i = 0;i < m+1;i++){
		pushcin(v);
	}
	int result = 0;
	for(int i = 0;i < m;i++){
		int x = v[i]^v[m];
		int count = 0;
		while(x){
			count += x&1;
			x>>=1;
		}
		if(count<=k)result++;
	}
	cout << result;
}
