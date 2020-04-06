#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
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
int op[3][3];
int main(){
	fastio
	for(int i = 0;i < 3;i++){
		for(int j = 0;j < 3;j++){
			int temp;
			cin >> temp;
			op[i][j]+=temp;
			if(i!=0){
				op[i-1][j]+=temp;
			}
			if(i!=2){
				op[i+1][j]+=temp;
			}
			if(j!=0){
				op[i][j-1]+=temp;
			}
			if(j!=2){
				op[i][j+1]+=temp;
			}
		}
	}
	for(int i = 0;i < 3;i++){
		for(int j = 0;j < 3;j++){
			cout << (op[i][j]%2 ? "0" : "1");
		}
		cout << "\n";
	}
}
