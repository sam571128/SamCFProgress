#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
	fastio
	int n;
	cin >> n;
	int xsum=0,ysum=0,zsum=0;
	while(n--){
		int x,y,z;
		cin >> x >> y >> z;
		xsum+=x;
		ysum+=y;
		zsum+=z;
	}
	if(xsum==0&&ysum==0&&zsum==0){
		cout << "YES";
	}else{
		cout << "NO";
	}
}