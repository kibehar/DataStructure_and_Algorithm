#include <iostream>
#define MAX_SIZE 5
using namespace std;
bool isempty();
bool isfull();
void enQueue();
int deQueue();
void display();
void enQueue_circ();
int deQueue_circ();
void display_circ();
void enQueue_list();
void  deQueue_list();
void display_list();
void menu();
void menu_array();
void menu_list();
void menu_circle();


int myqueue[MAX_SIZE],name[MAX_SIZE], front=-1, rear=-1, QUEUESIZE=0;
struct Node
{
int data;
struct Node* next;
struct Node* prev;
};

Node *Front = NULL;
Node *Rear = NULL;


int main()
{
menu();
return 0;
}

void menu(){
    system("cls");
    bool check=true;
    int choice;
    while(check)
    {
    cout<<"\n\n";
    cout<<"     ----------Queue implementation-------------"<<endl;
    cout<<"         1. Array Based queue "<<endl;
    cout<<"         2. linked list queue "<<endl;
    cout<<"         3. circle"<<endl;
    cout<<"         0. To exit"<<endl;
    cin>>choice;

    switch(choice)
    {
    case 1:
    menu_array();
        break;
    case 2:
        menu_list();
        break;
    case 3:
       menu_circle();
        break;

    case 0:
       exit(1);
    default:
        cout<<"Incorrect input"<<endl;

    }

    }
}
void menu_array(){
    system("cls");
    bool check=true;
    int choice;
    while(check)
    {
    cout<<"\n\n";
    cout<<"     ----------Queue implementation-------------"<<endl;
    cout<<"         1. To enqueue "<<endl;
    cout<<"         2. To dequeue "<<endl;
    cout<<"         3. To display"<<endl;
    cout<<"         0. To exit"<<endl;
    cin>>choice;

    switch(choice)
    {
    case 1:
    enQueue();
        break;
    case 2:
        deQueue();
        break;
    case 3:
        display();
        break;

    case 0:
       menu();
       break;
    default:
        cout<<"Incorrect input"<<endl;

    }

    }
}

void menu_list(){
    system("cls");
    bool check=true;
    int choice;
    while(check)
    {
    cout<<"\n\n";
    cout<<"     ----------Queue linked list implementation-------------"<<endl;
    cout<<"         1. To enqueue "<<endl;
    cout<<"         2. To dequeue "<<endl;
    cout<<"         3. To display"<<endl;
    cout<<"         0. To exit"<<endl;
    cin>>choice;

    switch(choice)
    {
    case 1:
    enQueue_list();
        break;
    case 2:
        deQueue_list();
        break;
    case 3:
        display_list();
        break;

    case 0:
       menu();
       break;
    default:
        cout<<"Incorrect input"<<endl;

    }

    }
}
void menu_circle(){
    system("cls");
    bool check=true;
    int choice;
    while(check)
    {
    cout<<"\n\n";
    cout<<"     ----------Queue circle implementation-------------"<<endl;
    cout<<"         1. To enqueue "<<endl;
    cout<<"         2. To dequeue "<<endl;
    cout<<"         3. To display"<<endl;
    cout<<"         0. To exit"<<endl;
    cin>>choice;

    switch(choice)
    {
    case 1:
    enQueue_circ();
        break;
    case 2:
        deQueue_circ();
        break;
    case 3:
        display_circ();
        break;

    case 0:
       menu();
       break;
    default:
        cout<<"Incorrect input"<<endl;

    }

    }
}

bool isFull(){
if(rear<MAX_SIZE-1){
return true;
        }
return false;
    }

bool isEmpty(){
if(QUEUESIZE==0) return true;
else return false;
    }


void enQueue(){
    system("cls");
int value;
cout<<"Enter the value that you want to enqueue: ";
cin>>value;
 if(rear<MAX_SIZE-1){
        rear++;
        myqueue[rear]=value;
        QUEUESIZE++;
        if(front==-1)
            front++;
                     cout<<value<<" inserted successfully!!"<<endl ;

    }
    else
        cout<<"Queue overflow";

    }




int deQueue(){
 system("cls");
int value;

    if(isEmpty()){
        cout << "Queue is underflow!!" << endl;
           return(-1); }
if(QUEUESIZE>0)
{
    value=myqueue[front];
    front++;
    QUEUESIZE--;
}
else
         cout << endl << "Deleted => " << value << " from myqueue";
         cout<<"\n  deleted successfully!!"<<endl;
return(value);
        }


    /* Function to display elements of Queue */
void display()
{
         system("cls");
int i;
if(isEmpty()) {
cout << endl << "Queue is Empty!!" << endl;
        }
else {
cout << endl << "Queue elements : ";
for(i=front; i<=rear; i++)
cout << myqueue[i] << "\t";
cout<<"\n\n";
        }
    }


void enQueue_circ(){
    int x;
    cout<<"Enter the value that you want to enqueue: ";
cin>>x;
   if (QUEUESIZE<MAX_SIZE){
   rear++;
       if(rear==MAX_SIZE)
        rear=0;
    name[rear]=x;
    QUEUESIZE++;
    if(front== -1)
        front++;
                             cout<<x<<" inserted successfully!!"<<endl ;

}
else
    cout<<"Queue overflow";

}
int deQueue_circ(){
    int x;
 if(isEmpty()){
        cout << "Queue is empty!!" << endl;
           return(x); }

else
{
    if(QUEUESIZE>0){
        x=name[front];
        front++;
    QUEUESIZE--;
}
          cout << endl << "Deleted => " << x << " from myqueue";
         cout<<"\n  deleted successfully!!"<<endl;
        return(x);
}

}


void display_circ()
{
         system("cls");
int i;
if(isEmpty()) {
cout << endl << "Queue is Empty!!" << endl;
        }
else {
cout << endl << "Queue elements : ";
for(i=front; i<=rear; i++)
cout << name[i] << "\t";
cout<<"\n\n";
        }
    }


    void enQueue_list()
{
    int y;
    cout<<"Enter the value that you want to enqueue: ";
    cin>>y;
 Node *temp = new Node;
 temp->data= y;
 temp->prev = NULL;
 temp->next=NULL;

 //If inserting the first element/node
 if( Front == NULL )
 {
  Front = temp;
  Rear = temp;
 }
 else
 {
  Rear ->next = temp;
  temp->prev=Rear;
  Rear=temp;    }
}

void deQueue_list ( )
{
 if( isEmpty() )
 cout<<"Queue is empty\n";

 //only one element/node in queue.

 else
 {
 Node * temp=Front;
 Front=Front->next;
 Front->prev  =NULL;
 delete temp;
 }

}

void display_list()
{
 if (isEmpty())
  cout<<"Queue is empty\n";
 else
 {
  Node *temp = Front;
  while( temp!=NULL)
  {
   cout<<temp->data<<" ";
   temp= temp->next;
  }
 }
}
