#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<char,int> P;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	stack<P> op;
	int idx=0;
	char c;
	for (char &c : s) {
		if (c <= 'Z' && c >= 'A') {
			cout << c;
		} else if (c == '/' || c == '*') {
			while (!op.empty() && (op.top().first == '/' || op.top().first == '*') && op.top().second == idx) {
				cout << op.top().first;
				op.pop();
			}
			op.push(P(c, idx));
		} else if (c == '+' || c == '-') {
			while (!op.empty() && op.top().second == idx) {
				cout << op.top().first;
				op.pop();
			}
			op.push(P(c, idx));
		} else if (c == '(') {
			idx++;
		} else if (c == ')') {
			while (!op.empty() && op.top().second == idx) {
				cout << op.top().first;
				op.pop();
			}
			idx--;
		}
	}
	while (!op.empty()) {
		cout << op.top().first;
		op.pop();
	}
	cout << '\n';
	return 0;
}
