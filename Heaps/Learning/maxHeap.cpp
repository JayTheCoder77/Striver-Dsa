class maxHeap {
    public:
        vector<int> list;

        maxHeap() {
            // Optional constructor logic
        }

        void downheap(int i) {
            int maxI = i;
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            if (l < list.size() && list[l] > list[maxI]) maxI = l;
            if (r < list.size() && list[r] > list[maxI]) maxI = r;
            if (maxI != i) {
                swap(list[i], list[maxI]);
                downheap(maxI);
            }
        }

        void upheap(int i) {
            if (i == 0) return;
            int p = (i - 1) / 2;
            if (list[i] > list[p]) {
                swap(list[i], list[p]);
                upheap(p);
            }
        }

        int extractMaxElement() {
            if (list.empty()) return -1;
            int root = list[0];
            list[0] = list.back();
            list.pop_back();
            if (!list.empty()) downheap(0);
            return root;
        }

        void deleteElement(int ind) {
            if (ind < 0 || ind >= list.size()) return;
            list[ind] = list.back();
            list.pop_back();
            if (ind < list.size()) {
                upheap(ind);
                downheap(ind);
            }
        }

        void insert(int val) {
            list.push_back(val);
            upheap(list.size() - 1);
        }
    };
