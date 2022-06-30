#ifndef _list_h
#define _list_h

class List
{
public:
    int root;
    int root_empty;
    int count;
    int data[1024];
    int ptr[1024];
    void creation();
    void insertion(int x);
    bool deletion(int x);
    void traversing();
    int searching(int target);
};

#endif
