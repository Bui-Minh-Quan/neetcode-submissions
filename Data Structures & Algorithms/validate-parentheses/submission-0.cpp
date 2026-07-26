class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (const auto& c:s) {
            if (c == '[' || c == '(' || c == '{') {
                st.push(c);
                continue;
            }

            if (c == ']') {
                if (st.empty())
                    return false;
                
                if (st.top() != '[')
                    return false;
                
                st.pop();
                continue;
            }

            if (c == ')') {
                if (st.empty())
                    return false;
                
                if (st.top() != '(')
                    return false;
                
                st.pop();
                continue;
            }

            if (c == '}') {
                if (st.empty())
                    return false;
                
                if (st.top() != '{')
                    return false;
                
                st.pop();
            }
        }

        return st.empty();
    }
};
