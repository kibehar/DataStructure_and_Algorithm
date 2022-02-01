using namespace std;
#include <iostream>

void menu();
void push_array();
void pop_array();
void push_list();
void pop_list();
void dec_bin();
void post_pre();
void transversing();

struct datas {
   int data;
   struct datas *next;
};
struct Node* top = NULL;
int stack[50], n=50, first=-1;

int main()
{
 menu();
    return 0;

}


void menu()
{
    system("cls");
    bool check=true;
    int choice;
    while(check)
    {
    cout<<"     ----------Singly Linked List-------------"<<endl;
    cout<<"         1. choose for array pushing"<<endl;
    cout<<"         2. choose for array poping"<<endl;
    cout<<"         3. choose for linkedlist pushing"<<endl;
    cout<<"         4. choose for linkedlist poping"<<endl;
    cout<<"         5. choose to change from decimal to binary"<<endl;
    cout<<"         6. choose to change from postfix to prefix"<<endl;
    cout<<"         7. choose for transvering"<<endl;
    cout<<"         0. To exit"<<endl;
    cin>>choice;

    switch(choice)
    {
    case 1:
      push_array();
        break;
    case 2:
        pop_array();
        break;
    case 3:
       push_list();
        break;
    case 4:
      pop_list();
        break;
    case 5:
        dec_bin();
        break;
    case 6:
   post_pre();
        break;
    case 7:
        transversing();
        break;

    case 0:
   exit(1);
        break;
    default:
        cout<<"Incorrect input"<<endl;

    }

    }
}


void push_array(){
    int x;
cout<<"enter the value that u want to push: ";
cin>>x;
 if(first>=n-1)
   cout<<"the Stack is Overflow"<<endl;
   else {
      first++;
      stack[first]=x;
   }
}

void pop_array(){

 if(first<=-1)
   cout<<"the Stack is Underflow"<<endl;
   else {
      cout<<"The popped element is "<< stack[first] <<endl;
      first--;
   }

}

void push_list(){
 int x;
cout<<"enter the value that u want to push: ";
cin>>x;
 if(top==NULL)
   cout<<"Stack "<<endl;
 datas *newnode = new datas;
   newnode->data = x;
   newnode->next = top;
   top = newnode;
}

void pop_list(){
 int x;
cout<<"enter the value that u want to push: ";
cin>>x;
  if(top==NULL)
   cout<<"Stack Underflow"<<endl;
   else {
      cout<<"The popped element is "<< top->data <<endl;
      top = top->next;
      datas *temp = topPtr;
      top = topPtr->item;
      topPtr = topPtr->next;
      temp->next = NULL;
      delete temp;

   }
}

void dec_bin(){
int x;
cout<<"Enter the number that u want to change it: ";
cin>>x;
   while(n!=0) {
push_array(x%2);
      x=x/2;
   }
print();
}

void print(){
if(first<=-1){
   cout<<"the Stack is Underflow"<<endl;}
   while(first!=-1 and first!<-1){
      cout<<" "<<pop_array();
   }
}
