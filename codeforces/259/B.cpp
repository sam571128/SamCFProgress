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
	int arr[3][3];
	for(int i = 0;i < 3;i++){
		for(int j = 0;j < 3;j++){
			cin >> arr[i][j];
		}
	}
	arr[1][1] = (arr[1][0]+arr[1][2])/2;
	arr[0][0] = (arr[1][0] + arr[1][1] + arr[1][2])-arr[0][1]-arr[0][2];
	arr[2][2] = (arr[1][0] + arr[1][1] + arr[1][2])-arr[2][0]-arr[2][1];
	for(int i = 0;i < 3;i++){
		for(int j = 0;j < 3;j++){
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}
