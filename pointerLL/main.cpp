#include <iostream>
using namespace std;
struct node
{
  int data;
  node *next;
};
node *createLinkedList(int n)
{
  node* tmp=new node[n];
  int x;
  for(int i=0;i<n;i++)
  {
      cin>>x;
      tmp[i].data=x;
      tmp[i].next=NULL;
      tmp[i-1].next=&tmp[i];
  }
  return &tmp[0];
}
node* reverse(node *head)
{
    node*p1=NULL;
    node*tmp1=head;
    node*tmp2=NULL;
    while(tmp1!=NULL)
    {
        tmp2=tmp1->next;
        tmp1->next=p1;
        p1=tmp1;
        tmp1=tmp2;
    }
    head=p1;
    return head;
}
void swap(node*p)
{
  int tmp=p->data;
  p->data=p->next->data;
  p->next->data=tmp;
}

bool foo(node* p)
{
  return ((p==NULL)||(p->next==NULL)||((p->data<=p->next->data)&&foo(p->next)));
}

void print(node *head)
{
  while (head != nullptr)
  {
    cout << head->data << " ";
    head = head->next;
  }
  cout<<endl;
}
int main()
{
  int n = 0;
  cin >> n;
  node *head = createLinkedList(n);
  print(head);
 
 cout<<foo(head);
  return 0;
}
