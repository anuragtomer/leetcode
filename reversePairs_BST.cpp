#include <iostream>
#include <vector>
using namespace std;
struct Node{
    int val;
    int count;
    struct Node * left;
    struct Node * right;
};

class Solution{
    public:
        Node * head = NULL;
        int count_ge = 0;
        /*
         * Delete the memory allocated for the BST
         */
        void deleteBST(Node * head) {
            if (head != NULL) {
                deleteBST(head->left);
                deleteBST(head->right);
                delete head;
            }
        }
        /*
         * Add valToAdd to the BST. If the valToAdd is already in the BST,
         * increment the count value to denote it was already there in the BST.
         */
        Node * addToBST(Node * temp_head, int valToAdd) {
            if (temp_head == NULL) {
                temp_head = new Node;
                temp_head->val = valToAdd;
                temp_head->count = 1;
                temp_head->left = NULL;
                temp_head->right = NULL;
                return temp_head;
            } else {
                Node * temp = NULL;
                if (temp_head->val < valToAdd) {
                    temp = addToBST(temp_head->right, valToAdd);
                        temp_head->right = temp;
                        temp_head->count++;
                    return temp_head;
                } else if (temp_head->val > valToAdd) {
                    temp = addToBST(temp_head->left, valToAdd);
                        temp_head->left = temp;
                    return temp_head;
                } else {
                    temp_head->count++;
                }
            }           
        }
        /*
         * Find the given value in BST. If not found, return -1. If found, return count.
         */
        int searchNode(Node * temp, long long x) {
            if (temp == NULL)
                return 0;
            if (temp->val == x) {
                return temp->count;
            } else if (x < temp->val) {
                return temp->count + searchNode(temp->left, x);
            } else if (x > temp->val) {
                return searchNode(temp->right, x);
            }
        }
        /*
         * Function to find 2*num + 1 in the BST. If found, then return that count to the caller.
         * Add this num in the BST.
         */
        int searchAndCount(Node * t, int num) {
            if (t == NULL) {
                head = addToBST(head, num);
                return 0;
            } else {
                int found = searchNode(head, num*2LL + 1);
                head = addToBST(head, num);
                return found;
            }
        }
        /*
         * Main driver function to find reverse pairs using BST.
         */
        int reversePairs(vector<int> & nums) {
            for (int i = 0; i < nums.size(); i++) {
                count_ge = count_ge + searchAndCount(head, nums[i]);
            }
            deleteBST(head);
            return count_ge;
        }
};
int main() {
    Solution sol;
    vector <int> nums = {2,4,3,5,1};
    cout << sol.reversePairs(nums);
    return 0;
}
