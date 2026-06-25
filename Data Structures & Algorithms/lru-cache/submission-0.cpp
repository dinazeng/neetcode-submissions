class Node {
    public:
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr){}
};

class LRUCache {
public:
    unordered_map<int, Node*> cache;
    int size;
    int capacity;
    Node *head;
    Node *tail;

    LRUCache(int capacity) {
        size = 0;
        cache.clear();
        this->capacity = capacity;

        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.contains(key)) {
            Node* node = cache[key];
            deleteNode(node);
            insertNode(node);

            return node->val;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if (cache.contains(key)) {
            deleteNode(cache[key]);
            insertNode(cache[key]);

            cache[key]->val = value;
        } else {
            Node* newNode = new Node(key, value);
    
            cache[key] = newNode;
            insertNode(cache[key]);
            size++;
            
            if (size > capacity) {
                Node* deleteMe = head->next;
                cache.erase(deleteMe->key);
                deleteNode(deleteMe);

                delete deleteMe;
                size--;
            } 
        }
        
    }

    void deleteNode(Node* node) {
        Node* prev = node->prev;
        Node* nxt = node->next;

        node->next->prev = prev;
        node->prev->next = nxt;

    }

    void insertNode(Node* node) {
        Node* temp = tail->prev;
        temp->next = node;
        node->prev = temp;
        node->next = tail;
        tail->prev = node;
    }
};
