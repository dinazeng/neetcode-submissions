class ListNode {
public:
    ListNode* prev;
    ListNode* next;

    int key;
    int val;

    ListNode (int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:

    int max_size = 0;
    unordered_map <int, ListNode*> cache;

    ListNode* head;
    ListNode* tail;

    LRUCache(int capacity) {
        max_size = capacity;
        cache.clear();
        head = new ListNode(0, 0);
        tail = new ListNode(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.contains(key)) {
            ListNode* node = cache[key];
            remove (node);
            insert (node);

            return node->val;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if (cache.contains(key)) {
            remove (cache[key]);
        }

        ListNode* newNode = new ListNode(key, value);
        cache[key] = newNode;
        insert(newNode);
        
        if (cache.size() > max_size) {
            ListNode* lru = head->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }

    void insert (ListNode* index) {
        ListNode* prev_node = tail->prev;
        prev_node->next = index;
        index->prev = prev_node;
        index->next = tail;
        tail->prev = index;
    }


     void remove (ListNode* index) {
        ListNode* prev = index->prev;
        ListNode* nxt = index->next;
        prev->next = index->next;
        nxt->prev = index->prev;
    }
};
