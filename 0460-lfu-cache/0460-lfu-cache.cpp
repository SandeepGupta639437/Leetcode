class LFUCache {
public:
    int cap;
    int size;

    unordered_map<int,list<vector<int>>::iterator>mp; //  key - > address
    map<int,list<vector<int>>>freq;  //{counter , {key,val,counter}}

    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
    }

    void makeMostFrequentlyUsed(int key){
        auto &vec = *(mp[key]);  //taken & to change in mp[key]  ..if & not written then it chanbge in its copy
        int val = vec[1];
        int counter = vec[2];

        freq[counter].erase(mp[key]);

        if(freq[counter].empty()){
            freq.erase(counter);
        }

        counter++;

        freq[counter].push_front({key,val,counter});

        mp[key] = freq[counter].begin();
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())return -1;

        auto address = mp[key]; // address not required
        auto vec = (*(mp[key])); // we use value at that address
        int val = vec[1];

        makeMostFrequentlyUsed(key);


        return val;
    }
    
    void put(int key, int value) {
        if(cap == 0)return ;

        if(mp.find(key)!=mp.end()){
            auto &vec = *(mp[key]);

            vec[1] = value;
            makeMostFrequentlyUsed(key);
        }else if(size < cap){
            size++;
            freq[1].push_front({key,value,1});
            mp[key] = freq[1].begin();
        }else{ // Time to remove LFU or LRU when there is the tie
            auto &kaun_sa_list = freq.begin()->second;
            int key_to_delete = (kaun_sa_list.back())[0];
            kaun_sa_list.pop_back();

            if(kaun_sa_list.empty()){
                freq.erase(freq.begin()->first);
            }

            freq[1].push_front({key,value,1});
            mp.erase(key_to_delete);
            mp[key] = freq[1].begin();

        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */