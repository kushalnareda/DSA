
#include <iostream>
#include <stack>
#include <string>
#include <cctype> // for isdigit

using namespace std;

int evaluatePostfix(string S)
    {
        // Your code here
        stack<int> st;
        for (int i = 0 ; i<S.size() ; i++){
            if (S[i]>='0' && S[i]<='9'){
                st.push(S[i]-'0');
            }
            else {
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                
                switch (S[i]){
                    case '+':
                        st.push(op2+op1);
                        break;
                    case '-':
                        st.push(op2-op1);
                        break;
                    case '*':
                        st.push(op2*op1);
                        break;
                    case '/':
                        st.push(op2/op1);
                        break;
                }
            }
        } return st.top();
    }