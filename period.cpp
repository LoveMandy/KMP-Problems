#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	void function(string s) {
		int k = -1, j = 0, len = s.length();
		vector<int> next(len + 1, -1);
		while (j < len) {
			while (k != -1 && s[k] != s[j]) k = next[k];
			k++;
			j++;
			next[j] = k;
		}
		for (int i = 2; i <= len; i++) {
			if (next[i] > 0 && i % (i - next[i]) == 0) {
				cout << i << ' ' << i / (i - next[i]) << endl;
			}
		}
	}
};


int main() {
	Solution* s = new Solution();
	int N;
	cin >> N;
	string str;
	for (int i = 1; N > 0; i++) {
		cin >> str;
		cout << "Test case #" << i << endl;
		s->function(str);
		cout << endl;
		cin >> N;
	}
	system("pause");
	return 0;
}
