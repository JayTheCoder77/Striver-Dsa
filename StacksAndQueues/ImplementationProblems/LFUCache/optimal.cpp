class Node{
    public:
    Node* next;
    Node* prev;
    int key , cnt , value;
    Node(int k , int val){
        next = NULL;
        prev = NULL;
        value = val;
        key = k;
        cnt = 1;
    }
};
class List{
    public:
    int size;
    Node* head;
    Node* tail;
    List(){
        head = new Node(0,0);
        tail = new Node(0,0);
        head -> next = tail;
        tail -> prev = head;
        size = 0;
    }
    void addFront(Node* node){
        Node* temp = head -> next;
        node -> next = temp;
        node -> prev = head;
        head -> next = node;
        temp -> prev = node;
        size++;
    }
    void removeNode(Node* node){
        Node* delPrev = node -> prev;
        Node* delNext = node -> next;
        delPrev -> next = delNext;
        delNext -> prev = delPrev;
        size--;
    }
};
class LFUCache {
  public:
    map<int ,Node*> keyNode;
    map<int ,List*> freqListMap;
    int maxSizeCache , minFreq , curSize;
    LFUCache(int cap) {
        // code here
        maxSizeCache = cap;
        minFreq = 0;
        curSize = 0;
    }
    void updateFreqListMap(Node* node){
        keyNode.erase(node -> key);
        freqListMap[node -> cnt] -> removeNode(node);
        // update Min freq
        if(node -> cnt == minFreq && freqListMap[node -> cnt] -> size == 0) minFreq++;
        List* nextHigherFreqList = new List();
        if(freqListMap.find(node -> cnt + 1) != freqListMap.end()) nextHigherFreqList = freqListMap[node -> cnt + 1];
        node -> cnt += 1;
        nextHigherFreqList -> addFront(node);
        freqListMap[node -> cnt] = nextHigherFreqList;
        keyNode[node -> key] = node;
    }
    int get(int key) {
        // code here
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            int val = node -> value;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }

        
    void put(int key, int value) {
        // code here
        if(maxSizeCache == 0) return;
        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            node -> value = value;
            updateFreqListMap(node);
        }
        else{
            if(curSize == maxSizeCache){
                List* list = freqListMap[minFreq];
                keyNode.erase(list -> tail -> prev -> key);
                freqListMap[minFreq] -> removeNode(list -> tail -> prev);
                curSize--;
            }
            curSize++;
            // new value to be added
            minFreq = 1;
            List* listFreq = new List();
            if(freqListMap.find(minFreq) != freqListMap.end()) listFreq = freqListMap[minFreq];
            Node* node = new Node(key,value);
            listFreq -> addFront(node);
            freqListMap[minFreq] = listFreq;
            keyNode[key] = node;
        }
    }
};

