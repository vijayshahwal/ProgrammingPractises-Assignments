#include <iostream>
#include "A2_Q2_list.h"

using namespace std;

int main()
{

    int n;
    cout << "Enter the number of elements in the list\n";
    cin >> n;
    List a;
    a.creation();

    int inp;
    for (int i = 0; i < n; i++)
    {
        cin >> inp;
        a.insertion(inp);
    }

    // below are examples how we can call other functions
    int k;
    cout<<"Enter the element to be deleted"<<endl;
    cin>>k;
    a.deletion(k);
    cout<<" list after deletion of inp"<<endl;
    a.traversing();
    cout<<"enter the element to be searched"<<endl;
    cin>>k;
    cout << "index found at index(1-based indexing):" << a.searching(k) << "\n";

    // to know the size of list, we can use count
    cout << "size of list:" << a.count << "\n";

    return 0;
}
