using namespace std;
#include <iostream>

void singly_menu();
void circular_menu();
void insert_front_singly();
void insert_end_singly();
void insert_midd_singly();
void delete_front_singly();
void delete_end_singly();
void delete_middle_singly();
void display_singly();
void search_singly();

struct Student1
{
    string name;
    string ID;
    int age;
    string dep;
    Student1 *next;

};
Student1 *head=NULL;
Student1 *tail=NULL;
int main()
{
 singly_menu();
    return 0;

}

void singly_menu()
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
        insert_front_singly();
        break;
    case 2:
        insert_end_singly();
        break;
    case 3:
        insert_midd_singly();
        break;
    case 4:
        delete_front_singly();
        break;
    case 5:
        delete_end_singly();
        break;
    case 6:
        delete_middle_singly();
        break;
    case 7:
        display_singly();
        break;
    case 8:
        search_singly();
        break;

    case 0:
        check=false;
        break;
    default:
        cout<<"Incorrect input"<<endl;

    }

    }
}


void circular_menu()
{
    bool check=true;
    int choice;
    while(check)
    {
    cout<<"     ----------Circular Linked List-------------"<<endl;
    cout<<"         1. To add student data in  the front"<<endl;
    cout<<"         2. To add student data at the end"<<endl;
    cout<<"         3. To add student data in  the middle"<<endl;
    cout<<"         4. To delete student data from  the front"<<endl;
    cout<<"         5. To delete student data from  the end"<<endl;
    cout<<"         6. To delete student data from the middle"<<endl;
    cout<<"         7. To display students data"<<endl;
    cout<<"         0. To go to main menu"<<endl;
    cin>>choice;

    }
}

void insert_front_singly()
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
    }
}

void insert_end_singly()
{
        system("cls");

    Student1 *q=new Student1;
    cout<<"Enter  name: ";
    cin>>q->name;
    cout<<"Enter  ID: ";
    cin>>q->ID;
    cout<<"Enter age: ";
    cin>>q->age;
    cout<<"Enter  department: ";
    cin>>q->dep;
    q->next=NULL;

    if (head==NULL)
        head=q;
    else
        {
            Student1 *p=head;
            while(p!=NULL)
            {
                p=p->next;
            }
            p->next=q;
        }
}

void insert_midd_singly()
{
        system("cls");

    string studId;
    int pos;
    Student1 *q=new Student1;

 cout<<"at which position you want to enter the student records? "<<endl;
 cin>>pos;
   Student1 *temp = head, *temp_prev, *ptr;
    int count = 0;

    while(temp != nullptr){
        temp = temp->next;
        count++;
        if(count > 1)
            break;
    }

    temp = head;

    if(count < 2){
        cout<<"no enough elements!!\n";
        return;
    }

    for(int i = 1; i < pos; i++){
        temp_prev = temp;
        if(temp->next == nullptr){
            cout<<"No enough elements!!\n";
            return;
        }
        temp = temp->next;
    }

    ptr = new Student1;
   cout<<"Enter name:";
  cin>>q->name;
  cout<<"Enter id:";
  cin>>q->ID;
  cout<<"Enter age:";
  cin>>q->age;
  cout<<"Enter department:";
  cin>>q->dep;
 q->next=NULL;
    ptr->next = temp;
    temp_prev->next = ptr;
  cout<<"Successfully inserted"<<endl;
}

void delete_front_singly()
{
        system("cls");

    Student1 *q;
    if (head==NULL)
        cout<<"No data inside\n";
    else
    {
        q=head;
        head=head->next;
        delete q;
        cout<<"Successfully deleted at the front"<<endl;
    }
}

void delete_end_singly()
{
        system("cls");

    Student1 *q, *p;
    if (head==NULL)
        cout<<"No data inside\n";
    else
    {
        q=head;
        while(q->next!=NULL)
        {
            p=q;
            q=q->next;
        }
        delete q;
        cout<<"Successfully deleted at the end"<<endl;
    }
}

void delete_middle_singly()
{
        system("cls");

	 Student1  *q;
     if(head==NULL)
       cout<<"Empty";
     else{
        q= head;
       int counter ,middle;
       while(q->next != NULL){
         counter++;
        }
        middle=(counter +1)/2;
        for(int i=1;i<=middle;i++){
           q=q->next;
          }
       delete q;
     cout<<"successfully deleted!"<<endl;
       }
}

void display_singly()
{
        system("cls");

    Student1 *q = new Student1;
    if (head==NULL)
        cout<<"No data inside\n";
    else
    {
        q=head;
        while(q!=NULL)
        {
            cout<<"Student Name: "<<q->name<<endl;
            cout<<"Student ID: "<<q->ID<<endl;
            cout<<"Student Age: "<<q->age<<endl;
            cout<<"Student Department: "<<q->dep<<endl;
            q=q->next;

        }
    }
}

void search_singly()
{
        system("cls");

    if(head==NULL)
          cout<<"No data inside\n";
    else{
    string studId;
    cout<<"Enter student ID: ";
    cin>>studId;

    Student1 *q;
    q=head;

    while(q->ID!=studId)
    {
               q=q->next;
    }
    cout<<"Student name: "<<q->name<<endl;
    cout<<"Student ID: "<<q->ID<<endl;
    cout<<"Student age: "<<q->age<<endl;
    cout<<"Student department: "<<q->dep<<endl;
    }
}
