class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> numbers;

        for (const auto& token:tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int a = numbers.top();
                numbers.pop();
                int b = numbers.top();
                numbers.pop();

                if (token == "+")
                    numbers.push(a + b);
                else if (token == "-")
                    numbers.push(b - a);
                else if (token == "*")
                    numbers.push(a * b);
                else if (token == "/")
                    numbers.push(b / a);

                continue;
            }

            int num = stoi(token);
            numbers.push(num);
        }

        return numbers.top();
    }
};
