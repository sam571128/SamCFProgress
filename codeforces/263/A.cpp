#include <bits/stdc++.h>
#include <cmath>

#define ll long long
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a[5][5];
	for(int i = 0;i < 5;i++){
		for(int j = 0;j < 5;j++){
			cin >> a[i][j];
			if(a[i][j]==1){
				cout << abs(i-2)+abs(j-2) << "\n";
			}
		}
	}
}