#incldue<iostream>
using namespace std;
void deleteDdl(ddl * delnode){
    ddl * delprev = delnode->prev;
    ddl * delnext = delnode -> next;
    delprev -> next = delnext;
    delnext -> prev = delprev;
}