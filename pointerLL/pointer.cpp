#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class node
{
public:
    int data;
    node *next;
};
// add the node in the first of LL
void push(node **head, int newdata)
{
    node *newnode = new node();
    newnode->data = newdata;
    newnode->next = NULL;

    newnode->next = *head;
    *head = newnode;
}
//add the node at the end of LL
void append(node **head, int newdata)
{
    node *newnode = new node();
    newnode->data = newdata;
    newnode->next = NULL;

    node *ptr = *head;
    if (*head == NULL)
    {
        *head = newnode;
        return;
    }

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newnode;
    return;
}

void certainPos(node *head, int pos, int newdata)
{
    //allocate a newnode
    node *newnode = new node();
    newnode->data = newdata;
    newnode->next = NULL;
    //assign a ptr to head
    node *ptr = head;
    pos--;
    while (pos > 0)
    {
        ptr = ptr->next;
        pos--;
    }
    newnode->next = ptr->next;
    ptr->next = newnode;
}

void deleteNode(node **head, int pos)
{
    if (head == NULL)
        return;

    node *ptr = *head;
    if (pos == 0)
    {
        *head = ptr->next;
        delete ptr;
        cout << "The LL is NULL" << endl;
        return;
    }
    //pos>0
    pos--;
    while (pos > 0)
    {
        ptr = ptr->next;
        pos--;
    }

    node *tmp = ptr->next;
    ptr->next = ptr->next->next;
    delete tmp;
}

void deleteLL(node **head)
{
    node *tmp = *head;
    node *news = NULL;
    while (tmp != NULL)
    {
        news = tmp->next;
        delete tmp;
        tmp = news;
    }
    *head = NULL;
}

void reverseLL(node **head)
{
    node *current = *head;
    node *previous = NULL;
    node *news = NULL;

    while (current != NULL)
    {
        news = current->next;
        current->next = previous;
        previous = current;
        current = news;
    }
    *head = previous;
}

void reverse2Node(node **head, int pos1, int pos2)
{

    if ((pos1 == 0 && pos2 == 4))
    {
        node *tmp = *head;
        node *tmp2 = *head;
        node *p2 = NULL;
        pos2--;
        while (pos2 > 0)
        {
            tmp2 = tmp2->next;
            pos2--;
        }
        p2 = tmp2->next;

        tmp2->next = *head;
        p2->next = tmp->next;
        tmp->next = NULL;

        *head = p2;

        return;
    }
    pos1--;
    pos2--;
    node *tmp1 = *head;
    node *tmp2 = *head;
    node *p1 = NULL;
    node *p2 = NULL;
    while (pos1 > 0)
    {
        tmp1 = tmp1->next;
        pos1--;
    }
    p1 = tmp1->next;

    while (pos2 > 0)
    {
        tmp2 = tmp2->next;
        pos2--;
    }
    p2 = tmp2->next;

    tmp1->next = p2;
    tmp2->next = p1;
    //assign the next of p1 to the temperature
    node *temp = p2->next;
    p2->next = p1->next;
    p1->next = temp;
    return;
}

void printLL(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

node *deleteValueNode(node *head, int x)
{
    int count = 0;
    node *p = head;
    while (p != NULL)
    {
        if (p->data == x && count == 0)
        {
            node *tmp = head;
            head = head->next;
            delete tmp;
            break;
        }
        if (p->data == x && count != 0)
        {
            deleteNode(&head, count);
            break;
        }
        p = p->next;
        count++;
    }
    return head;
}

node *connect2LL(node *head1, node *head2)
{
    node *p1 = head1;
    // node*p2=head2;
    while (p1->next != NULL)
        p1 = p1->next;

    p1->next = head2;
    return head1;
}

void swapped(node *p1)
{
    int tmp = p1->data;
    p1->data = p1->next->data;
    p1->next->data=tmp;
}

node *bubbleSort(node *head)
{
    node *p2 = NULL;
    node*p1= new node();
    int check;
    do
    {
        check=0;
        p1 = head;
        while (p1->next != p2)
        {
            if (p1->data >= p1->next->data) swapped(p1) ;
                check = 1;
                p1=p1->next;
        }
        p2=p1;
       // head=p1;
    }
    while(check);

    return  p1;
}

node* mergeSort(node* p1, node*p2)
{
   node* sort=NULL;
   node* head=NULL;
   
   if(p1==NULL) return p2;
   if(p2==NULL) return p1;

   if(p1&& p2)
   {
       if(p1->data<=p2->data)
       {
           sort=p1;
           p1=sort->next;
       }
       else
       {
         sort=p2;
           p2=sort->next;
       }
   }
   head=sort;
   while(p1&&p2)
   {
       if(p1->data<=p2->data)
       {
           sort->next=p1;
           sort=p1;
           p1=sort->next;
       }
       else
       {
           sort->next=p2;
           sort=p2;
           p2=sort->next;
       }
   }
   if(p1==NULL) sort->next=p2;
   if(p2==NULL) sort->next=p1;
return head;
}

int main()
{
    node *head = new node();
    head->data = 1;
    head->next = NULL;
    //Creat a Linked-list 1
    push(&head, 5);
    append(&head, 10);
    push(&head, 12);
    certainPos(head, 2, 3);
    bubbleSort(head);
    // Print LL1
    cout << "The LinkedList1 is: " << endl;
    printLL(head);
    cout << endl;
    //Creat a Linked-list 2
    node *head1 = new node();
    int a[5] = {3, 5, 6, 9, 11};
    for (int i = 0; i < 5; i++)
    {
        append(&head1, a[i]);
    }
    // Print LL2
    cout << "The LinkedList2 is: " << endl;
    printLL(head1);
     cout << endl;
    // //After connecting
    // cout << "The Linked-list after connecting is: " << endl;
    // node* connect_head = connect2LL(head, head1);
    // printLL(connect_head);
    // cout << endl;
    // //After sorting
    // cout << "The Linked-list after sorting is: " << endl;
    // node* sort_head = bubbleSort(connect_head);
    // printLL(sort_head);
    // cout << endl;
    //Merge Sort 2 LL 
    cout<<"The Linked-list after merge sort is: "<<endl;
    node* merge_head=mergeSort(head,head1);
    printLL(merge_head);

    return 0;
}