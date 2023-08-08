#include<stdio.h>
#include"linkedList.h"


int main() {
    Node* head = NULL;

    Data data1 = { 100 };
    push_front(data1, &head);

    Data data2 = { 200 };
    push_back(data2, &head);

    Data data3 = { 300 };
    push_back(data3, &head);

    Data data4 = { 400 };
    push_back(data4, &head);

    Data data5 = { 900 };
    push_front(data5, &head);

    Data data6 = { 1000 };
    push_front(data6, &head);

    print_linked_list(head);
    return 0;
}
