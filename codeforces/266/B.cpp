#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
	fastio
	int a,b;
	cin >> a >> b;
	string c;
	cin >> c;
	while(b--){
		string temp = c;
		for(int i = 0;i < c.size()-1;i++){
			if(c[i]=='B'&&c[i+1]=='G'){
				temp[i] = 'G';
				temp[i+1] = 'B';
			}
		}
		c = temp;
	}
	cout << c;
}