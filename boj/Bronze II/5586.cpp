#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int joi, ioi;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i;
	string s;
	cin >> s;

	for (i=1;i<s.size()-1;i++) {
		if (s[i-1] == 'J' && s[i] == 'O' && s[i+1] == 'I')
			joi++;
		else if (s[i-1] == 'I' && s[i] == 'O' && s[i+1] == 'I')
			ioi++;
	}
	cout << joi << endl;
	cout << ioi << endl;
	return 0;
}
