#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
	fastio
	string a;
	cin >> a;
	char next[] = {'h','e','l','l','o'};
	int count = 0;
	for(int i = 0;i < a.size();i++){
		if(a[i]==next[count]&&count==4){
			cout<<"YES";
			return 0;
		}
		if(a[i]==next[count]){
			count++;
		}
	}
	cout<<"NO";
}