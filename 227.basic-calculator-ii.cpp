class Solution {
  bool isOP(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
  }
  bool isNum(char ch) { return ch >= '0' && ch <= '9'; }
  int getNum(string &s, int &i) {
    int num = 0;
    while (i < s.size() && isNum(s[i])) {
      num = num * 10 + (s[i] - '0');
      ++i;
    }
    --i;
    return num;
  }
  bool is_higher(char op1, char op2) {
    if (((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-')))
      return true;
    else
      return false;
  }

 public:
  int calculate(string s) {
    stack<int> numbers;
    stack<char> op;
    auto apply_op = [](char ch, int a, int b) -> int {
      if (ch == '+')
        return b + a;
      if (ch == '-')
        return b - a;
      if (ch == '*')
        return b * a;
      if (ch == '/')
        return b / a;
      return 0;
    };
    for (int i = 0; i < s.size(); ++i) {
      if (isOP(s[i])) {
        while (not op.empty() && is_higher(s[i], op.top()) == false) {
          int num1 = numbers.top();
          numbers.pop();
          int num2 = numbers.top();
          numbers.pop();
          numbers.push(apply_op(op.top(), num1, num2));
          op.pop();
        }
        op.push(s[i]);
      } else if (isNum(s[i]))
        numbers.push(getNum(s, i));
    }
    // Empty the stack
    while (numbers.size() > 1) {
      int num1 = numbers.top();
      numbers.pop();
      int num2 = numbers.top();
      numbers.pop();
      numbers.push(apply_op(op.top(), num1, num2));
      op.pop();
    }
    return numbers.top();
  }
};
