#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll i;
	string s;
	cin>>s;
	for (i=0;i<s.size();i++) {
		if ((i % 2) == 0 && (s[i] < 'a' || s[i] > 'z'))
			break;
		else if ((i % 2) == 1 && (s[i] < 'A' || s[i] > 'Z'))
			break;

	}
	if (i==s.size())
		cout<<"Yes\n";
	else
		cout<<"No\n";
	return 0;
}
