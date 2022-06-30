#include "A2_Q2_list.h"
#include <iostream>

using namespace std;

void List::creation()
{

    for (int i = 0; i < 1023; i++)
        ptr[i] = i + 1;
    ptr[1023] = -1;
    root = -1;
    root_empty = 0;
    count = 0;
}

void List::insertion(int x)
{
    
    if(count == 1024) {
        cout << "List is full\n";
        return;
    }

    if (root == -1)
    {
        int pos = root_empty;
        root_empty = ptr[root_empty];
        data[pos] = x;
        ptr[pos] = pos;
        root = pos;
        count++;
    } else {
        int pos = root_empty;
        root_empty = ptr[root_empty];
        data[pos] = x;
        ptr[pos] = ptr[root];
        ptr[root] = pos;
        root = pos;
        count++;
    }
}

bool List::deletion(int x) {

    if(root == -1) {
        cout << "List is empty";
        return false;
    }
    
    if(data[root] == x && count ==1) {
        ptr[root] = root_empty;
        root_empty = root;
        root = -1;
        count--;
        return true;
    } 
    
    if(data[root] == x && count > 1) {
        int x = root;
        while(ptr[x] != root) {
            x = ptr[x];
        }
        root = x;
    }

    int pos = ptr[root];
    do {
        if(data[ptr[pos]] == x) {
            int y = ptr[pos];
            ptr[pos] = ptr[ptr[pos]];
            ptr[y] = root_empty;
            root_empty = y;
            count--;
            return true;
        }
        pos = ptr[pos];
    } while(pos != ptr[root]);
    return false;
}

void List::traversing() {
    
    if(root == -1) {
        cout << "List is empty";
        return;
    }

    int pos = ptr[root];
    do {
        cout << data[pos];
        cout<< "\n";
        pos = ptr[pos];
    } while(pos != ptr[root]);

}

int List::searching(int x) {

    if(root == -1) {
        cout << "List is empty";
        return -1;
    }

    int pos = ptr[root];
    do {
        if(data[pos] == x) {
            return pos;
        }
        pos = ptr[pos];
    } while(pos != ptr[root]);
    return -1;
}
