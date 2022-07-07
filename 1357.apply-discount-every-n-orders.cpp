#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Cashier {
  int _n;
  int _discount;
  unordered_map<int, int> productPrices;
  int current = 0;

 public:
  Cashier(int n, int discount, vector<int> &products, vector<int> &prices) : _n(n), _discount(discount) {
    for (int i = 0; i < products.size(); ++i) {
      productPrices[products[i]] = prices[i];
    }
  }

  double getBill(vector<int> product, vector<int> amount) {
    ++current;
    double totalAmount = 0;
    for (int i = 0; i < product.size(); ++i) {
      totalAmount += (productPrices[product[i]] * amount[i]);
    }
    if (current % _n == 0)
      totalAmount = totalAmount * ((100.0 - _discount) / 100.0);
    return totalAmount;
  }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
int main() {
  int n = 3, discount = 50;
  vector<int> products = {1, 2, 3, 4, 5, 6, 7};
  vector<int> prices = {100, 200, 300, 400, 300, 200, 100};
  Cashier *obj = new Cashier(n, discount, products, prices);
  assert(obj->getBill({1, 2}, {1, 2}) == 500.0);
  assert(obj->getBill({3, 7}, {10, 10}) == 4000.0);
  vector<int> product = {1, 2, 3, 4, 5, 6, 7}, amount = {1, 1, 1, 1, 1, 1, 1};
  assert(obj->getBill(product, amount) == 800.0);
  product = {4}, amount = {10};
  assert(obj->getBill(product, amount) == 4000.0);
  product = {7, 3}, amount = {10, 10};
  assert(obj->getBill(product, amount) == 4000.0);
  product = {7, 5, 3, 1, 6, 4, 2}, amount = {10, 10, 10, 9, 9, 9, 7};
  assert(obj->getBill(product, amount) == 7350.0);
  product = {2, 3, 5}, amount = {5, 3, 2};
  assert(obj->getBill(product, amount) == 2500.0);
  return 0;
}

