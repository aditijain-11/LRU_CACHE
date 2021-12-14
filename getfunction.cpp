#include<iostream>
using namespace std;
string get(int key_){
    if(cache.find(key_) != cache.end()) //usually is the key isnt present then it points to end of the map
    { 
        ddl * resnode = cache[key_]; //this is equal to the node stored in map at that key
        string res = resnode -> val; // taken out the value
        cache.erase(key_); //erasing from the map because address of the node will change
        deleteDdl(resnode); // node deleted from doubly linked list
        addDdl(resnode); //adding the node to the top of doubly linked list
        cache[key_] = head -> next; //adding the key value pair with a new given key
        return res; 

    }
    return -1;
}