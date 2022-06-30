class Solution {
public:
    int evalRPN(vector<string>& tokens) {
		stack <int> st;
		int a, b;
		for (int i = 0; i < tokens.size(); i++) {
			if (!st.empty()) {
				if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "/" || tokens[i] == "*") {
					b = (int)st.top();
					st.pop();
					a = (int)st.top();
					st.pop();
					switch (tokens[i][0]) {
					case '+':
						st.push(a + b);
						break;
					case '-':
						st.push(a - b);
						break;
					case '*':
						st.push(a * b);
						break;
					case '/':
						st.push(a / b);
						break;
					}
				}
				else
					st.push(stoi(tokens[i]));
			}
			else
				st.push(stoi(tokens[i]));

		}
		return st.top();
	}
};