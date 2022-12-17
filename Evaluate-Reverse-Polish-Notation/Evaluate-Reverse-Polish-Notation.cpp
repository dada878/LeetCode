class Solution {
public:
    int evalRPN(vector&lt;string&gt;&amp; tokens) {
        stack&lt;string&gt; com;
        for (int i = 0; i &lt; tokens.size(); i++) {
            cout &lt;&lt; "(" &lt;&lt; com.size() &lt;&lt; ") ";
            if (isdigit(tokens[i][0]) || isdigit(tokens[i][1])) {
                com.push(tokens[i]);
            } else if (tokens[i] == "+") {
                long long num1 = stoi(com.top()); com.pop();
                long long  num2 = stoll(com.top()); com.pop();
                com.push(to_string(num2 + num1));
            } else if (tokens[i] == "-") {
                long long  num1 = stoll(com.top()); com.pop();
                long long  num2 = stoll(com.top()); com.pop();
                com.push(to_string(num2 - num1));
            } else if (tokens[i] == "*") {
                long long  num1 = stoll(com.top()); com.pop();
                long long  num2 = stoll(com.top()); com.pop();
                com.push(to_string(num2 * num1));
            } else if (tokens[i] == "/") {
                long long  num1 = stoll(com.top()); com.pop();
                long long  num2 = stoll(com.top()); com.pop();
                com.push(to_string(num2 / num1));
            }
        }
        return stoi(com.top());
    }
};