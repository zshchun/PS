#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long a[101][101];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll h,w,x,y,i, j,c=0;
	cin>>h>>w>>x>>y;
	string s;
	for(i=1;i<=h;i++) {
		cin>>s;
		for (j=1;j<=w;j++) {
			if (s[j-1] == '#')
				a[i][j] = 1;
		}
	}
	for(i=y-1;i>0;i--){
		if (a[x][i]) break;
		c++;
	}
	for(i=y+1;i<=w;i++) {
		if (a[x][i]) break;
		c++;
	}
	for(i=x-1;i>0;i--) {
		if (a[i][y]) break;
		c++;
	}
	for(i=x+1;i<=h;i++) {
		if (a[i][y]) break;
		c++;
	}
	if (!a[x][y]) c++;
	cout << c << '\n';
	return 0;
}
