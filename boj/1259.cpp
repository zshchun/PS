#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i;
	string s;
	while(1) {
		cin>>s;
		if (s == "0") break;
		for (i=0;i<=(s.size()>>1);i++) {
			if (s[i-1] != s[s.size()-i])
				break;
		}
		if (i > s.size()/2)
			cout << "yes\n";
		else
			cout << "no\n";
	}
	return 0;
}
