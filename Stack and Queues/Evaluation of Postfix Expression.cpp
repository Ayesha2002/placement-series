stack<int> st;
        int n = S.length();

        for (int i = 0; i < n; i++) {
            if (isdigit(S[i])) {
                st.push(S[i] - '0'); // Convert char to int
            } else { // S[i] is an operator
                int operand2 = st.top();
                st.pop();
                int operand1 = st.top();
                st.pop();
                
                int result;
                switch (S[i]) {
                    case '+':
                        result = operand1 + operand2;
                        break;
                    case '-':
                        result = operand1 - operand2;
                        break;
                    case '*':
                        result = operand1 * operand2;
                        break;
                    case '/':
                        result = operand1 / operand2; // Note: Integer division
                        break;
                }
                
                st.push(result);
            }
        }

        return st.top();
