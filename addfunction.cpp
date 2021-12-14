#include<iostream>
using namespace std;
void addDdl(ddl * newval){
    ddl * temp = head -> next;
    newval -> next = temp;
    newval -> prev = head;
    head -> next = newval;
    temp -> prev = newval;
}