#include <iostream>
#include <stack>
using namespace std;
class BrowserHistory {
    stack<string> past, future;

   public:
    BrowserHistory(string homepage) {
        past.push(homepage);
        future = stack<string>();
    }

    void visit(string url) {
        past.push(url);
        future = stack<string>();
    }

    string back(int steps) {
        while (past.size() > 1 && steps) {
            future.push(past.top());
            past.pop();
            steps--;
        }
        if (past.empty())
            return "";
        return past.top();
    }

    string forward(int steps) {
        while (!future.empty() && steps) {
            past.push(future.top());
            future.pop();
            steps--;
        }
        return past.top();
    }
};

int main() {
    BrowserHistory browserHistory(string("leetcode.com"));
    browserHistory.visit("google.com");   // You are in "leetcode.com". Visit "google.com"
    browserHistory.visit("facebook.com"); // You are in "google.com". Visit "facebook.com"
    browserHistory.visit("youtube.com");  // You are in "facebook.com". Visit "youtube.com"
                                          // You are in "youtube.com", move back to "facebook.com" return "facebook.com"
    assert("facebook.com" == browserHistory.back(1));
    // You are in "facebook.com", move back to "google.com" return "google.com"
    assert("google.com" == browserHistory.back(1));
    // You are in "google.com", move forward to "facebook.com" return "facebook.com"
    assert("facebook.com" == browserHistory.forward(1));
    browserHistory.visit("linkedin.com"); // You are in "facebook.com". Visit "linkedin.com"
                                          // You are in "linkedin.com", you cannot move forward any steps.
    assert("linkedin.com" == browserHistory.forward(2));
    // You are in "linkedin.com", move back two steps to "facebook.com" then to "google.com". return "google.com"
    assert("google.com" == browserHistory.back(2));
    // You are in "google.com", you can move back only one step to "leetcode.com". return "leetcode.com"
    assert("leetcode.com" == browserHistory.back(7));
}
