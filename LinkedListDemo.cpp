#include<iostream>

struct node
{
    std::string name;
    float gpa;
    std::string major;
    node* next;
};
node* head=NULL;

//function prototypes
node* add(std::string,float,std::string);
node* remove(std::string);
void print();
bool contains(std::string);
bool isEmpty();
void clear();

int main()
{
    while(true)
    {
        int option;
        std::string name;
        std::string major;
        float gpa;

        std::cout<<"Select one of the following options:"<<std::endl;
        std::cout<<"1. Add new student"<<std::endl;
        std::cout<<"2. Remove a student"<<std::endl;
        std::cout<<"3. Check if a students exists"<<std::endl;
        std::cout<<"4. Check if list is empty"<<std::endl;
        std::cout<<"5. Print Current List"<<std::endl;
        std::cout<<"6. Clear list"<<std::endl;
        std::cout<<"7. Quit"<<std::endl;

        std::cin>>option;

        if(option==1)
        {
            std::cout<<"Enter name: ";
            std::cin>>name;
            std::cout<<"Enter Major: ";
            std::cin>>major;
            std::cout<<"Enter GPA: ";
            std::cin>>gpa;
            add(name,gpa,major);
        }
        else if (option==2)
        {
            std::cout<<"Enter name of student to remove: "<<std::endl;
            std::cin>>name;
            remove(name);
        }
        else if (option==3)
        {
            std::cout<<"Enter name to check: ";
            std::cin>>name;

            if (!contains(name))
            {
                std::cout<<"Student does not exist"<<std::endl;
            }
            else
            {
                std::cout<<"Student exists"<<std::endl;
            }
        }
        else if (option==4)
        {
            if (!isEmpty())
            {
                std::cout<<"List is not empty"<<std::endl;
            }
            else
            {
                std::cout<<"List is empty"<<std::endl;
            }
        }
        else if (option==5)
        {
            print();
        }
        else if (option==6)
        {
            clear();
        }
        else if (option==7)
        {
            return 0;
        }
        else
        {
            std::cout<<"Entered invalid choice"<<std::endl;
        }
    }
}

//function returns true if the linked list is empty, false otherwise
bool isEmpty()
{
    if (head==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//function adds a new node to the front of the list
node* add(std::string n, float g,std::string m)
{
    node* newNodePtr=new node;
    newNodePtr->name=n;
    newNodePtr->gpa=g;
    newNodePtr->major=m;

    newNodePtr->next=head;
    head=newNodePtr;

    return head;
}

//function prints the current list
void print()
{
    if (head==NULL)
    {
        std::cout<<"List is empty"<<std::endl;
    }
    else
    {
        node* currPtr=head;
        while(currPtr!=NULL)
        {
            std::cout<<"Name:"<<currPtr->name<<" Major:"<<currPtr->major<<" GPA:"<<currPtr->gpa<<std::endl;
            currPtr=currPtr->next;
        }
    }
}

//function clears all entries in the list
void clear()
{
    node* currPtr=head;

    while(currPtr!=NULL)
    {
        head=head->next;
        currPtr->next=NULL;
        delete currPtr;
        currPtr=head;
    }
}

//function checks whether a student is contained in the list
//returns true if student is in list, false otherwise
bool contains(std::string key)
{
    node* currPtr=head;

    while(currPtr!=NULL)
    {
        if(currPtr->name==key)
        {
            return true;
        }
        else
        {
            currPtr=currPtr->next;
        }
    }

    return false;
}

//function removes a entry from the list
//returns a pointer to the head of the list
node* remove(std::string toRemove)
{
    node* currPtr=head;
    node* prevPtr=currPtr;

    if (!contains(toRemove))
    {
        std::cout<<"Entry not found"<<std::endl;
        return head;
    }
    else
    {
        if (head->name==toRemove)
        {
                head=head->next;
                delete currPtr;
                return head;
        }

        while(currPtr!=NULL)
        {
            if (currPtr->name==toRemove)
            {
                prevPtr->next=currPtr->next;
                currPtr->next=NULL;
                delete currPtr;
                return head;
            }
            else
            {
                prevPtr=currPtr;
                currPtr=currPtr->next;
            }
        }
    }

    return head;
}
