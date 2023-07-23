#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pa;
#define endl "\n"
#define INF 123456789
int ans;
enum State {
	NOT_FOUND = 0,
	FOUND_X = 1,
	FOUND_O = 2,
	FOUND_BOTH = 3,
};

void check(int a, int b, int c) {
	if (a == b && b == c) {
		if (a == 'X')
			ans |= FOUND_X;
		else if (a == 'O')
			ans |= FOUND_O;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int x, o, dot, i, j;
	string s;
	while (1) {
		cin >> s;
		if (s == "end")
			break;
		x = o = dot = 0;
		for (char ch : s) {
			if (ch == 'X')
				x++;
			else if (ch == 'O')
				o++;
			else if (ch == '.')
				dot++;
		}
		if (x != o && x != o + 1) {
			cout << "invalid\n";
			continue;
		}
		ans = NOT_FOUND;
		for (i=0;i<3;i++) {
			j = i * 3;
			check(s[j], s[j+1], s[j+2]);
			check(s[i], s[i+3], s[i+6]);
		}
		check(s[0], s[4], s[8]);
		check(s[2], s[4], s[6]);
		if (ans != FOUND_BOTH && ((ans == FOUND_O && x == o) || (ans == NOT_FOUND && dot == 0) || (x == o + 1 && ans == FOUND_X)))
			cout << "valid\n";
		else
			cout << "invalid\n";
	}
	return 0;
}
