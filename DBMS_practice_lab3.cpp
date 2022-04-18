#include <bits/stdc++.h>
using namespace std;

int ps;

class blank_page
{ 
 public:
  int size;
  int num_records;
  int fp;
  int empty_spc;
  int page_id;
  vector<int> data;
  blank_page *next;
  blank_page *prev;

  blank_page(int s)
  {
    page_id = 0;
    size = s;
    num_records = 0;
    fp = 0;
    empty_spc = s - 16;
    next = NULL;
    prev = NULL;
  }
};

blank_page *head = NULL;

///////////////////////function to insert a value

void insert_d(int rs, int value)
 {
  if(head==NULL)
   {
    blank_page *newPage1 = new blank_page(ps);
    head=newPage1;
    newPage1->data.push_back(value);
    newPage1->empty_spc -= (rs + 4);
    newPage1->fp+=rs;
    newPage1->num_records += 1;
    return;
   }   
  blank_page *tmp=head;
  while(tmp!=NULL)
   {
    if(tmp->empty_spc>=rs+4)
     {
      tmp->data.push_back(value);
      tmp->empty_spc-=(rs + 4);
      tmp->fp+=rs;
      tmp->num_records+=1;
      return;
     }
    tmp=tmp->next;
  }
  blank_page *last = head;
  blank_page *newPage2 = new blank_page(ps);
  while (last->next != NULL)
    last = last->next;
  last->next=newPage2;
  newPage2->prev=last;
  newPage2->data.push_back(value);
  newPage2->empty_spc-=(rs+4);
  newPage2->fp+=rs;
  newPage2->num_records+=1;
  newPage2->page_id=last->page_id+1;
 }

//////////////////////////////function to search a value

int search(int value)
 {
  blank_page *tmp=head;
  bool flag=true;
  while (tmp!=NULL)
   {
    for(int i=0;i<(tmp->data).size();i++)
     {
      if((tmp->data)[i]==value)
       {
        cout<<tmp->page_id<<" "<<(tmp->data).size()-1<<"\n";
        return 0;
       }
     }
    tmp=tmp->next;
    if(tmp==NULL )
     flag=false;
   }
  if(flag==false)
   {
    cout<<"-1 -1"<<"\n";
    return 0;
   }
 }

/////////////////////////////////function to dispaly the status of heap file

void print_status()
 {
  int num_pages=0;
  blank_page *tmp1=head;
  while(tmp1!=NULL)
   {
    num_pages+=1;
    tmp1=tmp1->next;
   }
  int n=num_pages;
  cout<<n<<" ";
  blank_page *tmp2=head;
  while(tmp2!=NULL)
   {
    cout<<tmp2->num_records<<" ";
    tmp2=tmp2->next;
   }
  cout<<"\n";
 }

/////////////////////////////////////////// main function

int main()
 {
  cin>>ps;
  int operation;
  int x;
  int y;
  int v;
  while(7)
   {
    cin>>operation;
    switch(operation)
     {
      case 1:cin>>x>>y;
             insert_d(x, y);
      break;
      case 2:print_status();
      break;
      case 3:cin>>v;
             search(v);
      break;
      case 4:return 0;
     }
   }
 }