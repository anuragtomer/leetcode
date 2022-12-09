class Solution {
  string getNext(string &command, int &index) {
    if (index >= command.size())
      return "";
    if (command[index] == 'G') {
      ++index;
      return "G";
    }
    if (command[index] == '(' && command[index + 1] == ')') {
      index += 2;
      return "o";
    }
    index += 4;
    return "al";
  }

 public:
  string interpret(string command) {
    string result;
    int index = 0, n = command.size();
    while (index < n) {
      result.append(getNext(command, index));
    }
    return result;
  }
};
