#include<bits/stdc++.h>

using namespace std;

//Function to return precedence of operators
int priority(char c) {
  if (c == '^')
    return 3;
  else if (c == '/' || c == '*')
    return 2;
  else if (c == '+' || c == '-')
    return 1;
  else
    return -1;
}

// The main function to convert infix expression
//to postfix expression
void infixToPostfix(string s) {

  stack < char > st; //For stack operations, we are using c++ built in stack
  string ans;

  for (int i = 0; i < s.length(); i++) {

    // If the scanned character is
    // an operand, add it to output string.
    if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
      ans += s[i];

    // If the scanned character is an
    // ‘(‘, push it to the stack.
    else if (s[i] == '(')
      st.push('(');

    // If the scanned character is an ‘)’,
    // pop and to output string from the stack
    // until an ‘(‘ is encountered.
    else if (s[i] == ')') {
      while (st.top() != '(') {
        ans += st.top();
        st.pop();
      }
      st.pop();
    }

    //If an operator is scanned
    else {
      while (!st.empty() && priority(s[i]) <= priority(st.top())) {
        ans += st.top();
        st.pop();
      }
      st.push(s[i]);
    }
  }

  // Pop all the remaining elements from the stack
  while (!st.empty()) {
    ans += st.top();
    st.pop();
  }
  
  cout << "Postfix expression: " << ans << endl;

}

// void infixToPrefix(string s){
//   reverse(s.begin(), s.end());
//   infixToPostfix(s);
//   reverse(s.begin(), s.end());
//   cout<<s<<endl;
// }

int main() {
  string exp = "(p+q)*(m-n)";
  cout << "Infix expression: " << exp << endl;
  infixToPostfix(exp);
  return 0;
}