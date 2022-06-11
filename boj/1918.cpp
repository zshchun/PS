#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<char,int> P;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	stack<char> op;
	char c;
	for (char &c : s) {
		if (c <= 'Z' && c >= 'A') {
			cout << c;
		} else if (c == '/' || c == '*') {
			while (!op.empty() && (op.top() == '/' || op.top() == '*')) {
				cout << op.top();
				op.pop();
			}
			op.push(c);
		} else if (c == '+' || c == '-') {
			while (!op.empty() && op.top() != '(') {
				cout << op.top();
				op.pop();
			}
			op.push(c);
		} else if (c == '(') {
			op.push(c);
		} else if (c == ')') {
			while (!op.empty() && op.top() != '(') {
				cout << op.top();
				op.pop();
			}
			op.pop();
		}
	}
	while (!op.empty()) {
		cout << op.top();
		op.pop();
	}
	cout << '\n';
	return 0;
}
