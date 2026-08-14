class MyHashSet {
    vector<list<int>> table;
    int size = 1000;
public:
    MyHashSet() {
      table.resize(size);  
    }
    
    void add(int key) {
      int index = key % size; 

      for(auto it : table[index])
       if(it == key)
       return;

       table[index].push_back(key); 
    }
    
    void remove(int key) {
       int index = key % size;

       for(auto it = table[index].begin(); it != table[index].end(); ++it){
        
        if(*it == key){
            table[index].erase(it);
            return;
        }
       } 
    }
    
    bool contains(int key) {
        int index = key % size;

        for (auto it : table[index]) {
            if (it == key)
                return true;
        }

        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */