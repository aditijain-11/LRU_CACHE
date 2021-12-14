#include<iostream>
using namespace std;
void put(int key_, string val_)
{
    if (cache.find(key_) != cache.end()) //if key exist in the cache
    {
        ddl *existingnode = cache[key_]; //equal to node stored with the key
        cache.erase(key_);               //erasing the key from hash table
        deleteDdl(existingnode);         //deleting node from the
    }
    if (cache.size() == capacity)
    {                                 //least recently used is removed
        cache.erase(tail->prev->key); //REMOVING LEAST RECENTLY USED
        deleteDdl(tail->prev);
    }
    addDdl(new ddl(key_, value));
    cache[key_] = head->next;
}
