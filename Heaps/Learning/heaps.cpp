#include <bits/stdc++.h>
using namespace std;
// same as priority queue -> we just use a linked list
template<typename T>
class Heap{
    private:
        vector<T> list;
    public:
        Heap(){
        }
    void swap(int i , int j){
        T temp = list[i];
        list[i] = list[j];
        list[j] = temp;
    }
    int parent(int i){
        return (i-1)/2;
    }
    int left(int i){
        return (2 * i) + 1;
    }
    int right(int i){
        return (2 * i) + 2;
    }
    void upheap (int i){
        if(i == 0) return;
        int p = parent(i);
        if(list[i] < list[p]){
            swap(i,p);
            upheap(p);
        }
    }
    void insert(T val){
        list.push_back(val);
        upheap(list.size() - 1);
    }
    void downheap(int i){
        int min = i;
        int l = left(i);
        int r = right(i);

        if(l < list.size() && list[l] < list[min]){
            min = l;
        }
        if(r < list.size() && list[r] < list[min]){
            min = r;
        }
        if(min != i){
            swap(i,min);
            downheap(min);
        }
    }
    void remove(T val){
        int index = -1;
        for(int i = 0 ; i < list.size() ; i++){
            if(list[i] == val){
                index = i;
                break;
            }
        }
        if(index == -1) return;
        list[index] = list.back();
        list.pop_back();
        if (index < list.size()) {
            // Try both upheap and downheap as we don't know if the new value is
            // larger or smaller than the original
            upheap(index);
            downheap(index);
        }
    }
    T extractMin(){
        if(list.empty()) return -1;
        T root = list[0];
        list[0] = list.back();
        list.pop_back();

        if(!list.empty()){
            downheap(0);
        }
        return root;
        }
    T getMin(){
        if(list.empty()) return -1;
        return list[0];
    }
    bool empty(){
        return list.empty();
    }
    int size() {
        return list.size();
    }
    vector<T> heapSort(){
        vector <T> data;
        while(!list.empty()){
            data.push_back(extractMin());
        }
        return data;
    }
};

int main(){
    Heap<int> h;
    h.insert(34);
    h.insert(45);
    h.insert(22);
    h.insert(89);
    h.insert(76);
    vector<int> data = h.heapSort();
    for(auto i : data) cout << i << " ";
}
