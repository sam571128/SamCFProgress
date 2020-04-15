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
typedef vector<ll int> vll;
typedef vector<string> vs;

/********SAM571128's SOLUTION**********/
int x[100000];
int y[100000];
int visited[100000];
int n;
void dfs(int i){
	visited[i] = 1;
	for(int j = 0;j < n;j++){
		if(!visited[j]&&(x[i]==x[j]||y[i]==y[j]))
			dfs(j);
	}
}

int main(){
	fastio
	cin >> n;
	for(int i = 0;i < n; i++){
		cin >> x[i] >> y[i];
	}
	int count = 0;
	for(int i = 0;i < n;i++){
		if(!visited[i]){
			dfs(i);
			count++;
		}
	}
	cout << count -1;
}
