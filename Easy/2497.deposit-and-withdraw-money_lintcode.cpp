#include <algorithm>
#include <iostream>
#include <thread>
#include <vector>
using namespace std;
class Bank {
 private:
  int account;
  mutex m;

 public:
  Bank(int account = 0) { this->account = account; }
  void saveMoney(int amount, int saveOperation(int account, int amount)) {
    // write your code
    m.lock();
    account = saveOperation(account, amount);
    m.unlock();
  }
  void withdrawMoney(int amount, int withdrawOperation(int account, int amount)) {
    // write your code
    m.lock();
    account = withdrawOperation(account, amount);
    m.unlock();
  }
  int checkAccount() { return account; }
};
const static thread::id mainThreadId = this_thread::get_id();
static int bankMoney = 0;
vector<int> saveMoneyList;
vector<int> withdrawMoneyList;
int static saveOperation(int account, int amount) {
  if (bankMoney != account) {
    cout << "Don't cheat!\nYour money is " << account << ". The real money is " << bankMoney << "." << endl;
    return bankMoney;
  }
  bankMoney += amount;
  return bankMoney;
}
int static withdrawOperation(int account, int amount) {
  if (bankMoney != account) {
    cout << "Don't cheat!\nYour money is " << account << ". The real money is " << bankMoney << "." << endl;
    return bankMoney;
  }
  if (bankMoney < account) {
    cout << "Money" << bankMoney << " in bank is lowwer than what you want to withdraw(" << account << ")." << endl;
    return bankMoney;
  }
  bankMoney -= amount;
  return bankMoney;
}
void static threadSave(Bank &bank) {
  for (int j = 0; j < saveMoneyList.size(); j++) {
    bank.saveMoney(saveMoneyList[j], saveOperation);
  }
}
void static threadWithdraw(Bank &bank) {
  for (int j = 0; j < withdrawMoneyList.size(); j++) {
    bank.withdrawMoney(withdrawMoneyList[j], withdrawOperation);
  }
}
int main(int argc, char *argv[]) {
  string s;
  string list[2] = {};
  char c[30];
  int incrCount = 0;
  int decrCount = 0;
  vector<string> infile = {"Bank(0)", "save(50)", "withdraw(60)", "save(20)", "withdraw(10)"};
  for (auto c : infile) {
    s = string(c);
    s = s.substr(0, s.length() - 1);
    string operation;
    int number = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s.at(i) == '(') {
        operation = s.substr(0, i);
        if (i == s.length() - 1) {
          number = 0;
        } else {
          number = stoi(s.substr(i + 1));
        }
      }
    }
    if (operation == "save") {
      saveMoneyList.push_back(number);
    } else if (operation == "withdraw") {
      withdrawMoneyList.push_back(number);
    } else if (operation == "Bank") {
      bankMoney = number;
    }
    s = "";
  }
  Bank bank(bankMoney);
  vector<thread *> threads;
  threads.push_back(new thread(threadSave, ref(bank)));
  threads.push_back(new thread(threadWithdraw, ref(bank)));
  int n = 2;
  for (int j = 0; j < n; j++) {
    threads[j]->join();
    delete threads[j];
  }
  if (bankMoney != bank.checkAccount()) {
    assert(false);
  } else {
    cout << "passed";
  }
  return 0;
}
