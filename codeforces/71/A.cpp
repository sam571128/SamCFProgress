#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
	while(t--){
		string str;
		cin >> str;
		if(str.size()<=10){
			cout << str << "\n";
		}else{
			cout << str[0] << str.size()-2 << str[str.size()-1]<<"\n"; 
		}
	} 
    return 0;
} 