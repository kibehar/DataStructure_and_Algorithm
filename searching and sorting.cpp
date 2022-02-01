#include<iostream>
using namespace std;

void linear();
void binary();
void mainu();
void simple();
void bubble();
void insertion();
void selection();
void menu();
int main()
{

 menu();
	cout<< endl;
	return 0;

}
void menu()
{
int choice;
here:
    cout<<"*****************|This programming is for searching characters ****************"<<endl;
    cout<<"*****************choose 1 for linear searching***********"<<endl;
    cout<<"*****************choose 2 for binary searching***********"<<endl;
    cout<<"*****************choose 3 for simple sorting***********"<<endl;
    cout<<"*****************choose 4 for bubble sorting***********"<<endl;
   cout<<"*****************choose 5 for insertion sorting***********"<<endl;
   cout<<"*****************choose 6 for selecion sorting***********"<<endl;
    cout<<"*****************chooses 7 for exit**********************"<<endl;
    cin>> choice;

	switch(choice)
	{
		case 1:
        system("cls");//used to clear screean
        linear();
		break;
		case 2:
        system("cls");
        binary();
		break;
		case 3:
		simple();
		break;
		case 4:
        bubble();
        break;
        case 5:
        insertion();
        break;
        case 6:
        selection();
        break;
        case 7:
        exit(1);//closing the system
		break;
		default:
			cout<<"Invalid input !!!\n";
			break;
	}
}
void linear()
{
    int size;
	char input,arrays[size];

cout<<"\n\nEnter the size of the charaters: ";
	cin>> size;

	cout <<"Enter the characters: ";
	for(int i=0; i<size; i++)
	{
		cin>> arrays[i];
	}
	char chars;
	cout<<endl;
	cout <<"Enter the characters that you want to search: ";
	cin>> chars;

	int index = -1;

	for(int i=0;i<size;i++)
	{
		if(arrays[i] == chars )
		{
			index = i;
		}
	}

	if(index == -1)
	{
		cout <<"the characteristics that you inserted is not found on the list \n";
	}

	else
	{
		cout <<"the characters is found in the : " << index << endl;
	}
}
void binary()
{
    int size;
char input;
cout<<"\n\nEnter the size of the charaters: ";
	cin>> size;
char arrays[size];
	cout <<"Enter the characters: ";
	for(int i=0; i<size; i++)
	{
		cin>> arrays[i];
	}
	char chars;
	int bottom=0;
	int index = -1;
	int top=size-1;
	int found=0,middle;
	cout<<endl;
	cout <<"Enter the characters you want to search: ";
	cin>> chars;
	do
	{
		 middle = (top + bottom)/2;

		if(arrays[middle] == chars)
		{
			found=1;
		}
		else if( chars <arrays[middle] )
		{
			top = middle-1;

		}

		else
            bottom=middle+1;
	}while(bottom<=top && found==0);

	if(found==0){
	index=-1;
    cout<<"the character is not found"<<endl;}
	else
	index= middle;
	cout<<"THE character you are searching is found in the index :"<<index;


}
void simple()
{
	int length;
	char chars[length];
    cout <<"\nEnter the number of characters: ";
	cin >> length;
	cout <<endl;
	cout <<"Enter the characters:  ";
	for(int i=0;i<length;i++)
	{
		cin >> chars[i];
	}
	cout <<endl;
	  for(int i=0; i<=length-2;i++)
      for(int j=i+1; j<=length-1; j++)
          if(chars[i] > chars[j])
           {
              swap(chars[i],chars[j]);
            }


	cout<<endl;
	cout <<"=======================================: \n";
    cout <<"============ characters After sorted=====\n";
	for(int i =0;i <length ;i++)
	{
		cout <<"      "<<chars[i] <<" ";
	}
    cout <<"\n==========================================:\n ";
	cout << endl;
}
void bubble()
{
	int length;
	char chars[length];
    cout <<"\nEnter the number of characters: ";
	cin >> length;
	cout <<endl;
	cout <<"Enter the characters:  ";
	for(int i=0;i<length;i++)
	{
		cin >> chars[i];
	}
	cout <<endl;
	for(int i=0; i<length-1;i++)
	{
		for(int j=i+1; j<length;j++)
		{
			if(chars[j] > chars[j+1])
			{
				swap(chars[j],chars[j+1]);
			}
		}
	}
	cout <<"=========================================: ";

	cout<<endl;
	cout <<"==========================================: ";
    cout <<"========== characters After sorted=======\n";
	for(int i =0;i <length ;i++)
	{
		cout<<" " <<chars[i] <<" ";
	}
    cout <<"==================: ";
	cout << endl;
}

void insertion()
{
	int length;
	char chars[length];
    cout <<"\nEnter the number of characters: ";
	cin >> length;
	cout <<endl;
	cout <<"Enter the characters:  ";
	for(int i=0;i<length;i++)
	{
		cin >> chars[i];
	}
for(int i=1; i < length ; i++)
    {
        char temp = chars[i];

        for(int j= i-1; j>=0 && temp < chars[j]; j--)
        {
            chars[j+1] = chars[j];
            chars[j] = temp;
        }
    }

	cout<<endl;
	cout <<"================================================: \n";
    cout <<"======== characters After sorted==================\n";
	for(int i =0;i <length ;i++)
	{
		cout <<chars[i] <<" ";
	}
    cout <<"=====================================================: \n";
	cout << endl;
}
void selection()
{
int length;

    cout <<"\nEnter the number of characters: ";
	cin >> length;
	char chars[length];
	cout <<endl;
	cout <<"Enter the characters:  ";
	for(int i=0;i<length;i++)
	{
		cin >> chars[i];
	}

	for(int i=0; i<length;i++)
	{
		int minin = i;
		for(int j=i+1; j< length ;j++)
		{
			if(chars[j] < chars[ minin])
			{
				 minin = j;
			}
		}
			if( minin!=i)
			{
				swap(chars[i],chars[minin]);
			}
	}
	cout <<"=================================================:\n ";
    cout <<"======== characters After sorted=================== \n";
    	for(int i =0;i <length ;i++)
	{
		cout <<chars[i] <<" ";
	}
	cout << endl;
    cout <<"======================================================: \n";

}

