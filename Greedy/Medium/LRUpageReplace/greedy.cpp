int lruPageFaults(int pages[], int n, int capacity)
{

    unordered_map<int, list<int>::iterator> pageMap;

    list<int> lru;
    int faults = 0;

    for (int i = 0; i < n; i++)
    {
        if (pageMap.find(pages[i]) == pageMap.end())
        {
            faults++;
            // If capacity is full, remove LRU page
            if (lru.size() == capacity)
            {
                int lrupage = lru.back();
                lru.pop_back();
                pageMap.erase(lrupage);
            }
        }
        else
        {
            // Page is already in memory: remove it from current position
            lru.erase(pageMap[pages[i]]);
        }
        lru.push_front(pages[i]);
        pageMap[pages[i]] = lru.begin();
    }
    return faults;
}