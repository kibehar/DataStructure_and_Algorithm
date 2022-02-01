
#include <iostream>
using namespace std;


void doubly_menu();
void insert_front_doubly();
void insert_end_doubly();
void insert_middle_doubly();
void delete_front_doubly();
void delete_end_doubly();
void delete_middle_doubly();
void display_doubly_forward();
void search_doubly();

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
int main()
{
 doubly_menu();
    return 0;

}



void doubly_menu()
{
        system("cls");
    bool check=true;
    int choice;
    while(check)
    {
    cout<<"     ----------Doubly Linked List-------------"<<endl;
    cout<<"         1. To add at the front"<<endl;
    cout<<"         2. To add at the end"<<endl;
    cout<<"         3. To add  the middle"<<endl;
    cout<<"         4. To delete from  the front"<<endl;
    cout<<"         5. To delete  from  the end"<<endl;
    cout<<"         6. To delete from the middle"<<endl;
    cout<<"         7. To display  data"<<endl;
    cout<<"         8. To search  data"<<endl;
    cout<<"         0. To go to main menu"<<endl;
    cin>>choice;

        switch(choice)
    {
    case 1:
        insert_front_doubly();
        break;
    case 2:
        insert_end_doubly();
        break;
    case 3:
        insert_middle_doubly();
        break;
    case 4:
        delete_front_doubly();
        break;
    case 5:
        delete_end_doubly();
        break;
    case 6:
        delete_middle_doubly();
        break;
    case 7:
        display_doubly_forward();
        break;
    case 8:
        search_doubly();
        break;
    case 0:
        check=false;
        break;
    default:
        cout<<"Incorrect input"<<endl;

    }
    }
}




void insert_front_doubly()
{    system("cls");

    Student1 *temp=new Student1;
    cout<<"Enter student name: ";
    cin>>temp->name;
    cout<<"Enter student ID: ";
    cin>>temp->ID;
    cout<<"Enter student age: ";
    cin>>temp->age;
    cout<<"Enter student department: ";
    cin>>temp->dep;

    temp->next=NULL;

    if (head==NULL)
        head=tail=temp;
    else{
        temp->next=head;
        temp->prev=temp;
        head=temp;
    }
}

void insert_end_doubly()
{    system("cls");
    Student1 *temp=new Student1;
    cout<<"Enter student name: ";
    cin>>temp->name;
    cout<<"Enter student ID: ";
    cin>>temp->ID;
    cout<<"Enter student age: ";
    cin>>temp->age;
    cout<<"Enter student department: ";
    cin>>temp->dep;
    temp->next=NULL;

    if (head==NULL)
        head=tail=temp;
    else
    {
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
}

void insert_middle_doubly()
{ system("cls");
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
}


void delete_front_doubly()
{    system("cls");

    Student1 *temp;
    if (head==NULL)
        cout<<"No data inside\n";
    else
    {
        temp=head;
        head=head->next;
        head->prev=NULL;
        delete temp;
        cout<<"Successfully deleted at the front"<<endl;

    }
}

void delete_end_doubly()
{    system("cls");

    Student1 *temp;
    if (tail==NULL)
        cout<<"No data inside\n";
    else
    {
        temp=tail;
        tail=tail->prev;
        tail->next=NULL;
        delete temp;
        cout<<"Successfully deleted at the end"<<endl;
    }
}

void delete_middle_doubly()
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


}

void display_doubly_forward()
{    system("cls");

    Student1 *temp;
    if (tail==NULL)
        cout<<"No data inside\n";
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            cout<<"Student Name: "<<temp->name<<endl;
            cout<<"Student ID: "<<temp->ID<<endl;
            cout<<"Student Age: "<<temp->age<<endl;
            cout<<"Student Department: \n\n"<<temp->dep<<endl;
            temp=temp->next;


        }
    }

}

void search_doubly()
{    system("cls");

    if(head==NULL)
          cout<<"No data inside\n";
    else{
    string studId;
    cout<<"Enter student ID: ";
    cin>>studId;

    Student1 *temp;
    temp=head;

    while(temp->ID!=studId)
    temp=temp->next;
    cout<<"Student name: "<<temp->name<<endl;
    cout<<"Student ID: "<<temp->ID<<endl;
    cout<<"Student age: "<<temp->age<<endl;
    cout<<"Student department: "<<temp->dep<<endl;
    }
}

