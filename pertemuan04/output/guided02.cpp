#include <iostream> 
using namespace std; 

/// PROGRAM SINGLE LINKED LIST CIRCULAR 
 
 
// Deklarasi Struct Node
struct Node
{
    string data;
    Node *next;
}; 

Node *head, *tail, *baru, *bantu, *hapus; 

void init()
{
head = NULL;
tail = head;
}


// Pengecekan
int isEmpty()
{
if (head == NULL)
return 1; // true
else
return 0; // false