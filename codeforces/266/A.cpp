#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
	fastio
	int a;
	string b;
	cin >> a >> b;
	for(int i = 1;i < b.size();i++){
		while(b[i]==b[i-1]){
			b.erase(i,1);
		}
	}	
	int count = a-b.size();
	cout << count;
}