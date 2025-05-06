class minHeap {
    public:
        vector<int> list;
        // Constructor for the class.
        minHeap() {
            // Write your code here.
        }
        minHeap(int capacity) {
        list.reserve(capacity); // optionally reserve space to optimize
    }
        void downheap(int i){
            int minI = i;
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            if(l < list.size() && list[l] < list[minI]) minI = l;
            if(r < list.size() && list[r] < list[minI]) minI = r;
            if(minI != i){
                std::swap(list[i], list[minI]);
                downheap(minI);
            }
        }
        void upheap(int i){
            if(i == 0) return;
            int p = (i - 1)/2;
            if(list[i] < list[p]){
                std::swap(list[i], list[p]);
                upheap(p);
            }
        }
        // Implement the function to remove minimum element.
        int extractMinElement() {
            // Write you code here.
            if(list.empty()) return -1;
            int root = list[0];
            list[0] = list.back();
            list.pop_back();
            if(!list.empty()) downheap(0);
            return root;
        }

        // Implement the function to delete an element.
        void deleteElement(int ind) {
            // Write you code here.
            int index = -1;
            for(int i = 0 ; i < list.size() ; i++){
                if(i == ind){   
                    index = i;
                    break;
                }
            }
            if(index == -1) return;
            list[index] = list.back();
            list.pop_back();
            if (index < list.size()) {
                upheap(index);
                downheap(index);
            }
        }

        // Implement the function to insert 'val' in the heap.
        void insert(int val) {
            // Write you code here.
            list.push_back(val);
            upheap(list.size() - 1);
        }
    };
