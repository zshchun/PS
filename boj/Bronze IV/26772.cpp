#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
string a[9] = { " @@@   @@@  ",
	       "@   @ @   @ ",
	       "@    @    @ ",
	       "@         @ ",
	       " @       @  ",
	       "  @     @   ",
	       "   @   @    ",
	       "    @ @     ",
	       "     @      ",};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j, n;
	cin >> n;
	for (i=0;i<9;i++) {
		for (j=0;j<n;j++) {
			cout << a[i];
		}
		cout << endl;
	}
	return 0;
}
