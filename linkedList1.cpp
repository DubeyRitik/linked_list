#include <bits/stdc++.h>
using namespace std;

struct node {
  int data;
  struct node *next;
}*head = NULL,*last = head;


void create(int arr[],int n) {
  struct node *t;
  head = new struct node;
  head->data = arr[0];
  head->next = NULL;
  last = head;

  for(int i=1;i<n;i++) {
    t = new struct node;
    t->data = arr[i];
    t->next = NULL;
    last->next = t;
    last = t;
  }
}

int count(struct node *p) {
  int cnt = 0;

  while(p) {
    cnt++;
    p = p->next;
  }
  return cnt;
}

int rCount(struct node *p) {
  if(p) {
    return rCount(p->next) + 1;
  }
  return 0;
}

int sum(struct node *p) {
  int s = 0;
  while(p) {
    s += p->data;
    p = p->next;
  }
  return s;
}

int rSum(struct node *p) {
  if(p) {
    return rSum(p->next) + p->data;
  }
  return 0;
}

int maxElement(struct node *p) {
  int max = INT_MIN;
  while(p) {
    if(p->data > max) {
      max = p->data;
    }
    p = p->next;
  }
  return max;
}

int rMax(struct node *p) {
  if(p) {
    return max(rMax(p->next),p->data);
  }
  return INT_MIN;
}

void display(struct node *p) {
  while(p) {
    cout<<p->data<<" ";
    p = p->next;
  }
  cout<<endl;
}
void search(struct node *p, int key) {
  struct node *q = NULL;
  while(p) {
    if(p->data==key) {
      q->next = q->next->next;
      p->next = head;
      head = p;
    }
    q = p;
    p = p->next;
  }
}


void insert(struct node *p, int value, int index) {
  if(index < 0 || index > count(head)) 
  return;
  struct node *t = new struct node;
  t->data = value;
  t->next = NULL;
  if(index == 0) {
    t->next = head;
    head = t;
  }
  else {
    for(int i=0;i<index-1;i++) {
      p = p->next;
    }
    t->next = p->next;
    p->next = t;
  }
}

void insertAtLast(int value) {
  struct node *t = new struct node;
  t->data = value;
  t->next = NULL;
  if(last == NULL) {
    head = last = t;
  }
  else {
    last->next = t;
    last = t;
  }
}


void insertInSortedLL(int value) {
  struct node *t = new struct node;
  struct node *p = head;
  t->data = value;
  t->next = NULL;
  if(head==NULL) {
    head = t;
  }
  else {
    
    if(value < p->data) {
      t->next = p;
      head = t;
    }

    while(p->next->data < value)
    p = p->next;
    t->next = p->next;
    p->next = t;
  }
}

void deleteLL(struct node*p,int index) {
  if(index < 0 || index > count(head))
  return;
  struct node *t;
  if(index==1){
    t = p;
    p = p->next;
    head = p;
    t->next = NULL;
    delete t;
  }
  else {
    for(int i=0;i<index-2;i++) {
      p = p->next;
    }
    t = p->next;
    p->next = t->next;
    delete t;
  }
}

bool isSorted(struct node *p) {
   while(p->next) {
    if(p->data > p->next->data)
    return false;
    p = p->next;
   }
   return true;
}

void removeDup(struct node *p) {
  struct node *q = NULL;

  while(p->next) {
    
    if(q->data == p->data) {
      q->next = p->next;
      delete p;
      p = q->next;
    }
    else {
    q = p;
    p = p->next;
    }
  }
}

void reverseLL(struct node *p) {
  struct node *q=NULL,*r=NULL;




  while(p) {
    r = q;
    q = p;
    p = p->next;
    q->next = r;
  }


  head = q;
}


void recursiveReverseLL(struct node *q,struct node *p) {
  if(p)  {
    recursiveReverseLL(p,p->next);
    p->next = q;
  }
  else {
    head = q;
  }
}

void concat(struct node *p,struct node *q) {

}


int main() {
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  int n = 5;
  int arr[n] = {1,2,3,4,5};
  create(arr,n);
  display(head);
  
  

  display(head);
  



  return 0;
}
