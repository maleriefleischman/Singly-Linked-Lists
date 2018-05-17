#include<iostream>
using namespace std;

//Data structure for a node in the list
struct node {
  int data;
  node * next;

  //Default Constructor
  node() {
    data = 0;
    next = NULL;
  }

  //Parameterized Constructor
  node(int value) {
    data = value;
    next = NULL;
  }
};

//SINGLY LINKED LIST
class list {

private:
  node * head;
  node * tail;

public:
  //CONSTRUCTOR
  list() {
    head = NULL;
    tail = NULL;
  }

  //DESTRUCTOR
  ~list() {
    //Point to the start of the list
    node * cursor = head;

    //Keep a second pointer to hold the address of the next node to delete
    node * next = head;
    
    //Delete each node in the list in order
    while(next != NULL) {
      next = cursor->next;
      delete cursor;
      cursor = next;
    }
  }

  //DISPLAY: Prints the data of all elements in the list in order to stdout
  void display() {
    //Declare a pointer and point it at the start of the list
    node * cursor = head;

    //Print the data of each element. 
    if(cursor == NULL){
      cout<<"empty \n";
      return;
    }

    while(cursor != NULL) {
      cout<<cursor->data<<" ";
      cursor = cursor->next;
    }
    cout<<"\n";
  }
  
  //APPEND: adds a new node to the end of the list
  void append(int value) {
    //Construct a new node and declare a pointer named n that points to it.
    node * n = new node(value);

    /* If there's a node at the end of our list,
     * update it's pointer to point to our new node;
     */
    if(tail!=NULL)
      tail->next = n;
    
    //If our list is empty, update head to point to our new node.
    if(head==NULL)
      head=n;

    //Point the list tail to our new node
    tail = n;
  }

  //PREPEND: adds a new node to the beginning of the list
  void prepend(int value) {
    node*n = new node(value);
    if (head != NULL){
      n->next=head;
    }

    else{
      head = n;
      tail = n;
    }
    head = n;
  }

  //INSERT: inserts a new node into the position specified
  void insert(int position, int value) {
    if (position == 1){
      prepend(value);
    }
    if (position > 1){
      if (head == NULL){
	cout << "empty \n";
	return;
      }
      else{
	node * cursor = head;
	node * next = head;
	next = cursor->next;
	int j = 1;
	
	while (cursor != tail && j != position-1){
	  cursor = cursor->next;
	  next = next->next;
	  j++;
	}
	if(cursor == tail  && j == position-1){
	  append(value);
	  return;
	}
	else if(j == position-1){
	    node * n= new node(value);
	    cursor->next = n;
	    n->next = next;
	    return;
	}
	   else{
	     cout<< "error \n";
	     return;
	   }
      }
    }
  }
  
  //
  
  //DELETE HEAD: Deletes the first node in the list
  void deleteHead() {
    node*cursor = head;
    node*next = head;
  
    if (head == NULL){
      cout<<"empty \n";
      return;
    }

    else if (tail == head){
      delete head;
      head = NULL;
      tail = NULL;
      return;
    }

    else{
      next = cursor->next;
      delete cursor;
      }
    head = next;
  }

  //DELETE TAIL: Deletes the last node in the list
  void deleteTail() {
    node * before = head;
    node * cursor = head;

    

    if(head==NULL){
      cout<<"empty \n";
      return;
    }
    
    if(head == tail){
      delete head;
      head = NULL;
      tail = NULL;
      return;
    }

   else{
     cursor = before->next;
    while(cursor != tail){
      cursor = cursor->next;
      before = before->next;
      }
    delete cursor;
   }
    tail = before;
    tail->next = NULL;
  }

  //DELETE AT: Deletes a node at the specified position.
  void deleteAt(int position) {
    if (position == 1){
      deleteHead();
      return;
    }
    else if (position < 1){
      cout << "error selected number is less than 1 \n";
      return;
    }
   else if (position > 1){
     if (head == NULL){
       cout<< "empty list \n";
       return;
     }
     else{
       node * next = head;
       node * cursor = head;
       next = cursor -> next;
       int j = 1;
       while ( next != tail && j != position -1){
	 cursor = cursor -> next;
	 next = next -> next;
	 j++;
       }
       if ( next == tail && j == position-1){
	 deleteTail();
	 return;
       }
       else if (next == tail && j < position-1){
	 cout<<"error: specified postion larger than list \n";
	 return;
       }
       else {
	 cursor-> next = next -> next;
	 delete next;
	 return;
       }
     }
      
    }
  }

  //POP aka delete the last element and return it's value
  int pop(){
    if (head == NULL){
      cout<<"haha empty jk";
      return 0;
    }
    else{
	int value = tail->data;
	deleteTail();
	return value;
      }
    
  }
  
  //PRINT LENGTH: Prints the length of the list to stdout
  void printLength() {
    if (head == NULL){
      cout<<"0 \n";
      return;
    }
    else if (head == tail){
      cout<<"1 \n";
      return;
    }
    else{
      node * cursor = head;
      int j = 0;
      while (cursor != NULL){
	cursor = cursor->next;
	j++;
      }
      cout<<j<<"\n";
    }
  }

  //DISPLAY REVERSE: Prints the data of all elements in the list in reverse order to stdout
  //prepends original list in reverse order
  void Reverse() {
    if (head == NULL){
      cout<<"0 \n";
      return;
    }

    else if (head == tail){
      cout<<head->data;
      return;
    }
    else{
      node * cursor = head;
      //prepends each data point ex: 123 > 321123
      //list will become doubly long with first half being in reverse order of original
      while (cursor != NULL){
	prepend(cursor->data);
	cursor=cursor->next;
      }
      //continue from original 'head' data point and delete original list with deleteTail
     node *  placeholder = head;
      while (placeholder != NULL){
	deleteTail();
	placeholder = placeholder->next;
      }

    }
  }

};

//MAIN: Test our singly linked list.
int main() {
  list * testlist = new list;
  
	  testlist->insert(1,4);
	  testlist->display();
	  testlist->insert(1,9);
	  testlist->display();
	  testlist->insert(3,11);
	  testlist->display();
	  testlist->insert(3,12);
	  testlist->display();
	  testlist->insert(6,12);
	  testlist->display();
	  testlist->append(1);
	  testlist->append(2);
	  testlist->append(3);
	  testlist->display();
	  testlist->insert(3,10);
	  testlist->display();
	  testlist->printLength();
	  testlist->display();
	  testlist->Reverse();
	  testlist->display();
	  cout<<testlist->pop()<<" \n";
	  testlist->display();

	  

  delete testlist;

  return 0;
}
