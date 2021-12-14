#include <bits/stdc++.h>
using namespace std;
class LRUCache
{
public:
    class ddl
    {
    public:
        int key;
        string val;
        ddl *next;
        ddl *prev;
        ddl(int _key, string _val)
        {
            key = _key;
            val = _val;
        }
    };
    ddl *head = new ddl(-1, " ");
    ddl *tail = new ddl(-1, " ");

    int capacity;
    unordered_map<int, ddl *> cache;

    LRUCache(int cap)
    {
        capacity = cap;
        head->next = tail;
        tail->prev = head;
    }

    void addDdl(ddl *newval)
    {
        ddl *temp = head->next;
        newval->next = temp;
        newval->prev = head;
        head->next = newval;
        temp->prev = newval;
    }

    void deleteDdl(ddl *delnode)
    {
        ddl *delprev = delnode->prev; // points towards previous of node to be deleted
        ddl *delnext = delnode->next; // points towards next of node to be deleted
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    void get(int key_)
    {
        if (cache.find(key_) != cache.end()) //usually is the key isnt present then it points to end of the map
        {
            ddl *resnode = cache[key_]; //this is equal to the node stored in map at that key
            string res = resnode->val;  // taken out the value
            cache.erase(key_);          //erasing from the map because address of the node will change
            deleteDdl(resnode);         // node deleted from doubly linked list
            addDdl(resnode);            //adding the node to the top of doubly linked list
            cache[key_] = head->next;   //adding the key value pair with a new given key
            cout << "\n"
                 << res << "\n";
        }
        else
        {
            cout << "\nid product doesnt exists\n";
        }
    }
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
        addDdl(new ddl(key_, val_));
        cache[key_] = head->next;
    }

    void PrintList()
    {
        cout << "\t\t\t\t\t\tHERE ARE THE CACHE ELEMENTS: \n\n\n";
        for (auto i : cache)
        {
            cout << i.first << " : " << i.second->val << "\n\n\n\n";
        }
    }
};

int main()
{
    cout << "\t\t*************************************************************************************************************************************************\n\n\n\n";
    cout << "                                                                  WELCOME TO CACHE SYSTEM                                                        \n\n\n\n";
    cout << "*************************************************************************************************************************************************\n\n\n\n";

    LRUCache *computer_accessories = new LRUCache(5);
    computer_accessories->put(162, "sandisk pedrive");
    computer_accessories->put(323, "logitech mouse");
    computer_accessories->put(433, "OFFIXO multipurpose laptop table");
    computer_accessories->put(662, "Apple 20W USB-C Power Adapter (for iPhone, iPad & AirPods)");
    computer_accessories->put(112, "HP 680 Original Ink Advantage Cartridge (Black)");

    LRUCache *everyday_essentials = new LRUCache(5);
    everyday_essentials->put(765, "WISHKEY Telescopic Adjustable Anti Slip Plastic Hanger ");
    everyday_essentials->put(232, "TrustBasket Enriched Premium Organic Earth Magic Potting Soil Mix with Required Fertilizers for Plants");
    everyday_essentials->put(876, "ORCHID ENGINEERS 29INCH(2.5FEET) Iron Indoor/Outdoor Flower Pot/Plant Stand");
    everyday_essentials->put(545, "MANGALAM CamPure Camphor Cone (Original) - Room, Car and Air Freshener & Mosquito Repellent - Pack of 2");
    everyday_essentials->put(333, "Oddy Uniwraps Food Wrapping Paper 11 x 20 Mtrs");

    LRUCache *grocery = new LRUCache(4);
    grocery->put(111, "Tata Sampann Unpolished Toor Dal/ Arhar Dal, 1kg");
    grocery->put(455, "Quaker Oats Pouch, 2 kg");
    grocery->put(422, "Quaker Oats Pouch, 2 kg");
    grocery->put(990, "Tata Salt Lite, Low Sodium Iodised Salt, 1kg");

    int choice_1;
    cout << "Please choose your activity:\nEnter 1: access existing caches\nEnter 2: update new item in cache";
    cin >> choice_1;

    switch (choice_1)
    {
    case 1:
    {
        int choice_2a;
        cout << "Chose from the directory:\nEnter 1: computer_accessories\nEnter 2: everyday_essentials\nEnter 3:Grocery\n";
        cin >> choice_2a;
        switch (choice_2a)
        {
        case 1:
            computer_accessories->PrintList();
            break;
        case 2:
            everyday_essentials->PrintList();
            break;
        case 3:
            grocery->PrintList();
            break;
        default:
            cout << "invalid choice!";
            break;
        }
    }
    break;
    case 2:
    {
        int choice_2b;
        cout << "Chose the cache from the directory to make updates in:\nEnter 1: computer_accessories\nEnter 2: everyday_essentials\nEnter 3:Grocery\n";
        cin >> choice_2b;
        switch (choice_2b)
        {
        case 1:
        {
            cout << "\n\n COMPUTER_ACCESSORIES\n";

            cout <<"select operation: \n Enter 1:get\n Enter 2: put\nEnter 3: exit";
            int choice_3;
            cin >> choice_3;
            switch (choice_3)
            {
            case 1:
                cout <<"enter userid of product \n";
                int ida;
                cin >> ida;
                computer_accessories->get(ida);
                break;
            case 2:
            {
                cout << "\n\nenter userid of product\n\n";
                int idb;
                cin >> idb;
                cout << "\nenter product name\n";
                string name;
                cin >> name;
                computer_accessories->put(idb, name);
                break;
            }
            default:
                break;
            }
            break;
        }
        default:
            break;
        }
    }
    case 3:
        break;
    default:
        break;
    }
}
