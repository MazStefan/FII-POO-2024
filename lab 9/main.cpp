#include <iostream>
#include <tuple>

template<typename K, typename V>
class Map 
{
private:
    struct Node 
    {
        K key;
        V value;
        Node* left;
        Node* right;
        Node(const K& key, const V& value) : key(key), value(value), left(nullptr), right(nullptr) {}
    };

    Node* head;
    int size;

    class Iterator 
    {
    private:
        Node* current = nullptr;

    public:
        Iterator(Node* node) : current(node) {}

        Iterator& operator++() {
            if (current->right) {
                current = current->right;
                while (current->left) {
                    current = current->left;
                }
            }
            else {
                while (current->parent && current == current->parent->right) {
                    current = current->parent;
                }
                current = current->parent;
            }
            return *this;
        }

        bool operator!=(const Iterator& other) const 
        {
            return current != other.current;
        }

        std::tuple<K, V, int> operator*() const
        {
            return std::make_tuple(current->key, current->value, current->index);
        }
    };

public:
    Map() : head(nullptr), size(0) {}

    ~Map() 
    {
        Node* cur = head;
        while (cur) {
            Node* next = cur->right;
            delete cur;
            cur = next;
        }
    }

    void Set(const K& key, const V& value) 
    {
        Node** ptr = &head;
        while (*ptr) {
            if ((*ptr)->key == key) {
                (*ptr)->value = value;
                return;
            }
            ptr = &((*ptr)->right);
        }
        *ptr = new Node(key, value);
        ++size;
    }

    bool Get(const K& key, V& value) const 
    {
        Node* cur = head;
        while (cur) {
            if (cur->key == key) {
                value = cur->value;
                return true;
            }
            cur = cur->right;
        }
        return false;
    }

    int Count() const 
    {
        return size;
    }

    bool Delete(const K& key) 
    {
        Node** ptr = &head;
        while (*ptr) {
            if ((*ptr)->key == key) {
                Node* toDelete = *ptr;
                *ptr = toDelete->right;
                delete toDelete;
                --size;
                return true;
            }
            ptr = &((*ptr)->right);
        }
        return false;
    }

    bool Includes(const Map<K, V>& other) const 
    {
        Node* cur = other.head;
        while (cur) {
            V value;
            if (!Get(cur->key, value) || value != cur->value) {
                return false;
            }
            cur = cur->right;
        }
        return true;
    }

    void Clear() 
    {
        Node* cur = head;
        while (cur) {
            Node* next = cur->right;
            delete cur;
            cur = next;
        }
        head = nullptr;
        size = 0;
    }

    const V& operator[](const K& key) const 
    {
        Node* cur = head;
        while (cur) {
            if (cur->key == key) {
                return cur->value;
            }
            cur = cur->right;
        }
    }

    V& operator[](const K& key)
    {
        Node** ptr = &head;
        while (*ptr) {
            if ((*ptr)->key == key) {
                return (*ptr)->value;
            }
            ptr = &((*ptr)->right);
        }
        *ptr = new Node(key, V());
        ++size;
        return (*ptr)->value;
    }

    Node* operator[](const K& key, const V& value, const int index) {
        int count = 0;
        Node** ptr = &head;
        while (*ptr) 
        {
            if ((*ptr)->key == key && (*ptr)->value == value && count + 1 == index)
            {
                return (*ptr);
            }
            ptr = &((*ptr)->right);
            count++;
        }
        return nullptr;
    }

    Iterator begin() const {
        Node* node = head;
        if (node) {
            while (node->left) {
                node = node->left;
            }
        }
        return Iterator(node);
    }

    Iterator end() const {
        return Iterator(nullptr);
    }
};

int main()
{
    Map<int, const char*> m;

    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";

    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    m[20] = "result";

    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    return 0;
}
