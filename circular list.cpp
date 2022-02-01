#include <iostream>
using namespace std;


void circular_menu();
void insert_front();
void insert_end();
void insert_middle();
void delete_front();
void delete_end();
void delete_middle();
void display_circular_list();
void search_circular_list();
int c=0;
struct Student1
{
    string name;
    string ID;
    int age;
    string dep;
    Student1 *next;
    Student1 *prev;

};
Student1 *head=NULL;
Student1 *tail=NULL;
int main(){

circular_menu();

}

void circular_menu()
{
    system("cls");
    bool check=true;
    int choice;
    while(check)
    {
    cout<<"     ----------Singly Linked List-------------"<<endl;
    cout<<"         1. To add at the front"<<endl;
    cout<<"         2. To add at the end"<<endl;
    cout<<"         3. To add at the middle"<<endl;
    cout<<"         4. To delete the front"<<endl;
    cout<<"         5. To delete at the end"<<endl;
    cout<<"         6. To delete from the middle"<<endl;
    cout<<"         7. To display students data"<<endl;
    cout<<"         8. To search students data"<<endl;
    cout<<"         0. To go to main menu"<<endl;
    cin>>choice;

    switch(choice)
    {
    case 1:
        insert_front();
        break;
    case 2:
        insert_end();
        break;
    case 3:
        insert_middle();
        break;
    case 4:
      delete_front();
        break;
    case 5:
    delete_end();
        break;
    case 6:
        delete_middle();
        break;
    case 7:
    display_circular_list();
        break;
    case 8:
       //search_circular_list();
        break;

    case 0:
        check=false;
        break;
    default:
        cout<<"Incorrect input"<<endl;

    }

    }
}
void insert_front()
{
        system("cls");

    Student1 *q=new Student1;
    cout<<"Enter student name: ";
    cin>>q->name;
    cout<<"Enter student ID: ";
    cin>>q->ID;
    cout<<"Enter student age: ";
    cin>>q->age;
    cout<<"Enter student department: ";
    cin>>q->dep;

    q->next=NULL;

    if (head==NULL)
        head=q;
    else{
        q->next=head;
        head=q;
        q->prev=q->next;
    }
    c++;
}

void insert_end()
{
        system("cls");

    Student1 *temp=new Student1;
    cout<<"Enter  name: ";
    cin>>temp->name;
    cout<<"Enter  ID: ";
    cin>>temp->ID;
    cout<<"Enter age: ";
    cin>>temp->age;
    cout<<"Enter  department: ";
    cin>>temp->dep;
   temp->next=NULL;

    if (head==NULL)
        head=tail=temp;
    else{

    do{
        temp=temp->next;
    }while(temp->next->next=head);
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
        temp->next=head;
    }
c++;
}

void insert_middle()
{
     system("cls");
Student1 *temp=new Student1;
    Student1 *ptr=new Student1;

    temp = head;
     cout<<"Enter student name: ";
    cin>>ptr->name;
    cout<<"Enter student ID: ";
    cin>>ptr->ID;
    cout<<"Enter student age: ";
    cin>>ptr->age;
    cout<<"Enter student department: ";
    cin>>ptr->dep;
        ptr->next=NULL;

    int p;

   cout<<"Enter the position that you want to enter: ";
   cin>>p;

    if (head==NULL)
        head=tail=temp;
    else

        for( int i=1; i<p-1; i++){
            temp=temp->next;
        }
    ptr->next=temp->next;
    temp->next->prev=ptr;
    temp->next=ptr;
    ptr->prev=temp;
    c++;
}

void delete_front()
{    system("cls");

    Student1 *temp;
    if (head==NULL)
        cout<<"No data inside\n";
    else
    {
        temp=head;
        head=head->next;
        head->prev=tail;
        delete temp;
        cout<<"Successfully deleted at the front"<<endl;

    }
    c--;
}


void delete_end()
{    system("cls");

    Student1 *temp;
    if (tail==NULL)
        cout<<"No data inside\n";
    else
    {
        temp=tail;
        tail=tail->prev;
        tail->next=head;
        delete temp;
        cout<<"Successfully deleted at the end"<<endl;
    }
    c--;
}

void delete_middle()
{
    system("cls");
 Student1 *ptr;
 Student1 *temp;
 temp=head;
 int i,p;
 cout<<"enter the position that you want to delete: "<<endl;
 cin>>p;
    if (head==NULL)
        cout<<"No data inside\n";
    else
    for( int i=1; i<p-1; i++){
            temp=temp->next;
        }
        ptr=temp->next;
        temp->next=ptr->next;
        ptr->next->prev=temp;
        delete ptr;
        cout<<"Successfully deleted at the end"<<endl;
c--;

}
void display_circular_list()
{    system("cls");
int i=1;
    Student1 *temp;
    if (head==NULL)
        cout<<"No data inside\n";
    else
    {
        temp=head;
            while(i<=c-1){
         cout<<"Student Name: "<<temp->name<<endl;
            cout<<"Student ID: "<<temp->ID<<endl;
            cout<<"Student Age: "<<temp->age<<endl;
            cout<<"Student Department:"<<temp->dep<<endl;
            cout<<"\n\n";
            temp=temp->next;

            }
    }

}
