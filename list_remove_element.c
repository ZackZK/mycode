#include <stdio.h>

typedef struct node{
  int data;
  struct node *next;
} node;

typedef node * list_head;

node nodes[10];

list_head create_list(void)
{
  list_head head = NULL;
  head = &nodes[0];
  int cnt = sizeof(nodes)/sizeof(nodes[0]);
  for(int i=0; i< cnt-1; i++)
  {
    nodes[i].data = i;
    nodes[i].next = &nodes[i+1];
  }
  nodes[cnt-1].data = cnt-1;
  nodes[cnt-1].next = NULL;
  
  return head;
}

void print_list(const list_head head)
{
  node *pNode;
  pNode = (node *)head;
  while(pNode)
  {
    printf("%d ", pNode->data);
    pNode = pNode->next;
  }
  printf("\n");
}

void list_remove_element(list_head *head, int value)
{
  node **pNode = head;
  
  while(*pNode)
  {
    if((*pNode)->data == value) 
    {
      *pNode = (*pNode)->next;
    }
    else
    {
      pNode = &((*pNode)->next);
    }
  }
}

int main()
{
  list_head head;
   head = create_list();
   
   printf("Original list  : ");
   print_list(head);

   list_remove_element(&head, 0);
   printf("After remove 0 : ");
   print_list(head);
   
   list_remove_element(&head, 5);
   printf("After remove 5 : ");
   print_list(head);

   list_remove_element(&head, 9);
   printf("After remove 9 : ");
   print_list(head);
   return 0;

}
