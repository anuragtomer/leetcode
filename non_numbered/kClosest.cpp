#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
        struct elements{
            int distance;
            int x;
            int y;
            elements(int x1, int y1): distance((x1*x1) + (y1*y1)), x(x1), y(y1) {}
        };
        void swap(vector<elements *> &heap, int node1, int node2) {
            elements *one = heap[node1];
            heap[node1] = heap[node2];
            heap[node2] = one;
        }
        void heapify(vector<elements *>&heap, int current_node) {
            int parent = (current_node - 1) / 2;
            int left = (2 * parent) + 1;
            int right = (2 * parent) + 2;
            elements *left_e = heap[left];
            elements *right_e = NULL;
            if (right <= current_node) {
                right_e = heap[right];
            }
            elements *parent_e = heap[parent];
            if (left_e->distance <= right_e->distance) {
                if (left_e->distance < parent_e->distance) {
                    swap(heap, left, parent);
                    current_node = parent;
                    change = true;
                }
            } else {
                if (right_e->distance < parent_e->distance) {
                    swap(heap, right, parent);
                    current_node = parent;
                    change = true;
                }
            }                        

            while (current_node > 0 && change == true) {
                change = false;
                if (right <= current_node) {
                } else if (left_e->distance < parent_e->distance) {
                    swap(heap, left, parent);
                    current_node = parent;
                    change = true;                    
                }
            }

        }
        void make_heap(vector<elements *> &heap, vector<int> elem) {
            elements * e = new elements(elem[0], elem[1]);
            heap.push_back(e);
            if (heap.size() == 1) {
                return;
            } else {
                int current_node = heap.size() - 1;
                heapify(heap, current_node);
            }
        }
        
        void maintain_heap(vector<element *> &heap) {
            element * parent = heap[0];
            element * left = heap[];
            element * right;
            if (heap.size() 
        }

        elements * extract_min(vector<elements *> &heap) { 
            if (heap.size() > 0) {
                elements *e = heap[0];
                swap(heap, 0, heap.size() - 1);
                heap.resize(heap.size() - 1);
                maintain_heap(heap);
                print_heap(heap);
                return e;
            } 
            return NULL;
        }
        
        void print_heap(vector<elements *> heap) {
            for (int i = 0; i < heap.size(); i++) {
                elements * e = heap[i];
                cout << i << " element: " <<e->x << ":" << e->y << " ";
            }
            cout << endl;
        }
        vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
            vector<elements *> heap;
            heap.clear();
            vector< vector<int>> output;
            output.clear();
            for (int i = 0; i < points.size(); i++) {
                make_heap(heap, points[i]);
                print_heap(heap);
            }
            for (int i = 0; i < K; i++) {
                elements * e = extract_min(heap);
                output.push_back({e->x, e->y});
            }
            return output;
        }
};
int main() {
    Solution sol;
    int K = 5;
    vector<vector<int>> points = {{-2,-6}, {-7, -2}, {-9, 6}, {10, 3}, {-8, 1}, {2, 8}};
    vector<vector<int>> res = sol.kClosest(points, K);
    cout << "K closest points: ";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i][0] << " : " << res[i][1] << " ";
    }
    return 0;
}


