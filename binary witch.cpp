#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	string function(string& code, int len) {
		// 翻转字符串
		for (int i = 0; i < code.length() / 2; i++) {
			char temp = code[i];
			code[i] = code[code.length() - 1 - i];
			code[code.length() - 1 - i] = temp;
		}
		for (int i = 0; i < len; i++) {
			string str = code.length() > 13 ? code.substr(0, 13) : code;
			vector<int> next = getNext(str);
			int j = 1, k = 0, maxLen = 0;
			char nextWeather = '0';
			// 注意：由于str.length()的返回值为无符号数，当k为-1时会自动转换为无符号数，导致k > str.length()
			while (j < code.length() && k < (int)str.length()) {
				if (k == -1 || code[j] == str[k]) {
					k++;
					j++;
				} else {
					if (k > maxLen) {
						maxLen = k;
						nextWeather = code[j - k - 1];
					}
					k = next[k];
				}
			}
			if (k > maxLen) nextWeather = code[j - k - 1];
			code.insert(code.begin(), nextWeather);
		}
		string result = code.substr(0, len);
		for (int i = 0; i < result.length() / 2; i++) {
			char temp = result[i];
			result[i] = result[result.length() - 1 - i];
			result[result.length() - 1 - i] = temp;
		}
		return result;
	}
	vector<int> getNext(string& s) {
		vector<int> next(s.length(), -1);
		int k = -1, j = 0;
		while (j < s.length() - 1) {
			if (k == -1 || s[j] == s[k]) {
				k++;
				j++;
				if (s[j] == s[k]) next[j] = next[k];
				else next[j] = k;
			} else {
				k = next[k];
			}
		}
		return next;
	}
};

int main() {
	Solution* s = new Solution();
	int N, len;
	string code;
	cin >> N >> len >> code;
	cout << s->function(code, len) << endl;
	system("pause");
	return 0;
}