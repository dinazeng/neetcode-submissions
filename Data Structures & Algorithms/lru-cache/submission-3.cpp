class LRUCache {
private:
    struct Node {
        Node* next;
        Node* prev;
        int val;
        int key;

        Node (int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };
    
    Node* head;
    Node* tail;
    int cap;
    unordered_map<int, Node*> cache;

    void remove(Node* n) {
        Node* prev = n->prev;
        Node* next = n->next;

        prev->next = next;
        next->prev = prev;
    }

    void insert(Node* n) {
        Node* bef = head->prev;
        bef->next = n;
        n->prev = bef;
        n->next = head;
        head->prev = n;
    }

public: 
    LRUCache(int capacity) {
        cap = capacity;    
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->prev = tail;
        tail->next = head;    
    }
    
    int get(int key) {
        if (cache.contains(key)) {
            Node* node = cache[key];
            remove(node);
            insert(node);

            return node->val;
        }

        return -1;
    }
    
    void put(int key, int value) {
         if (cache.contains(key)) {
            remove (cache[key]);
        }

        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insert(newNode);

        if (cache.size() > cap) {
            Node* temp = tail->next;
            remove(temp);
            cache.erase(temp->key);

            delete temp;
        }
    }
};
