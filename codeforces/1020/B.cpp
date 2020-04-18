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
	int n;
	cin >> n;
	vi arr(n+1);
	for(int i = 1;i <= n;i++){
		cin >> arr[i];
	}
	for(int i = 1;i <= n;i++){
		map<int,int> a;
		int g = i;
		while(true){
			a[g]++;
			if(a[g]>2){
				cout << g << " ";
				break;
			}
			g = arr[g];
		}
	}
}
