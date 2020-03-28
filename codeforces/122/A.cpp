#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
	fastio
	int n[] = {4,7,47,74,444,447,474,477,744,747,774,777};
	int a;
	cin >> a;
	for(int i = 0;i < 12;i++){
		if(a<n[i]){
			cout<<"NO";
			return 0;
		}else if(a%n[i]==0){
			cout << "YES";
			return 0;
		}
	}
	cout<< "NO";
}