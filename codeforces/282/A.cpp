#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,x=0;
	cin >> n; 
	while(n--){
		string a;
		cin >> a;
		if(a.find("++")!=string::npos){
			x++;
		}else{
			x--;
		}
	}
	cout << x;
	return 0;
}