class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for (char c : expression) {
            if (c == ',') continue;

            if (c != ')') {
                st.push(c);
            } else {
                // evaluate till '('
                int t = 0, f = 0;

                while (st.top() != '(') {
                    if (st.top() == 't') t++;
                    else if (st.top() == 'f') f++;
                    st.pop();
                }

                st.pop(); // remove '('
                char op = st.top(); 
                st.pop(); // operator

                // evaluate
                if (op == '!') {
                    st.push(f == 1 ? 't' : 'f');
                } 
                else if (op == '&') {
                    st.push(f == 0 ? 't' : 'f');
                } 
                else if (op == '|') {
                    st.push(t > 0 ? 't' : 'f');
                }
            }
        }

        return st.top() == 't';
    }
};