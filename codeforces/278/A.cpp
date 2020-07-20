#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 
int d[105];
int main(int argc, char** argv) {
	int n,s,t;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&d[i]);cin>>s>>t;
	int p1=0,p2=0;
	for(int i=s;i!=t;i=(i)%n+1)
	{
		p1+=d[i];
	}
	
	for(int i=s;i!=t;i=(i-2+n)%n+1)
	{
		p2+=d[(i-2+n)%n+1];
	}
	cout<<min(p1,p2);
	return 0;
}