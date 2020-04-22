#include <bits/stdc++.h>

#define ll long long
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
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

/********SAM571128's SOLUTION**********/
int main(){
	fastio
	int a,b;
	cin >> a >> b;
	int grid[a][b];
	for(int i = 0;i < a;i++){
		for(int j = 0;j < b;j++){
			cin >> grid[i][j];
		}
	}
	int newgrid[a][b];
	for(int i = 0;i < a;i++){
		for(int j = 0;j < b;j++){
			newgrid[i][j] = 1;
		}
	}
	for(int i = 0;i < a;i++){
		for(int j = 0;j < b;j++){
			if(grid[i][j] == 0){
				for(int k = 0;k < a;k++){
					newgrid[k][j] = 0;
				}
				for(int k = 0;k < b;k++){
					newgrid[i][k] = 0;
				}
			}
		}
	}
	for(int i = 0;i < a;i++){
		for(int j = 0;j < b;j++){
			if(newgrid[i][j] == 1){
				for(int k = 0;k < a;k++){
					if(grid[k][j]!=1){
						cout << "NO";
						return 0;
					}
				}
				for(int k = 0;k < b;k++){
					if(grid[i][k]!=1){
						cout << "NO";
						return 0;
					}
				}
			}
			if(newgrid[i][j] == 0&&grid[i][j] == 1){
				bool noone = true;
				for(int k = 0;k < a;k++){
					if(newgrid[k][j]==1){
						noone = false;
						break;
					}
				}
				for(int k = 0;k < b;k++){
					if(newgrid[i][k]==1){
						noone = false;
						break;
					}
				}
				if(noone&&grid[i][j]){
					cout << "NO";
					return 0;
				}
			}
		}
	}
	cout << "YES\n";
	for(int i = 0;i < a;i++){
		for(int j = 0;j < b;j++){
			cout << newgrid[i][j] << " ";
		}
		cout << "\n";
	}
}
