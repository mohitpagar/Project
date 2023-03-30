#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Structure for Singly Linear and Singly Circular

template <class T>
struct nodeS
{
    T data;
    struct nodeS *next;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Structure for Doubly Linear and doubly Circular

template <class T>
struct nodeD
{
    T data;
    struct nodeD *next;
    struct nodeD *prev;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Class of Singly Linear Linked List

template <class T>
class SinglyLL
{
    public:
        struct nodeS<T> * First;

        SinglyLL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

        void Display();
        int Count();
};

template <class T>
SinglyLL<T> :: SinglyLL()   
{  
    First = NULL;
}

template <class T>
void SinglyLL<T> :: InsertFirst(T no)
{
    struct nodeS<T> * newn = new nodeS<T>;

    newn -> data = no;
    newn -> next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn -> next = First;
        First = newn;
    }
}

template <class T>
void SinglyLL<T> :: InsertLast(T no)
{
    struct nodeS<T> * newn = new nodeS<T>;
    struct nodeS<T> * temp = First;

    newn -> data = no;
    newn -> next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
}

template <class T>
void SinglyLL<T> :: InsertAtPos(T no, int ipos)
{
    int NodeCnt = 0;
    NodeCnt = Count();

    if((ipos < 1) || (ipos > NodeCnt + 1))
    {
        cout<<"Invalid Position \n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == NodeCnt +1)
    {
        InsertLast(no);
    }
    else
    {
        struct nodeS<T> * newn = new nodeS<T>;

        newn-> data = no;
        newn -> next = NULL;

        struct nodeS<T> * temp = First;

        for(int iCnt = 1; iCnt < ipos -1; iCnt++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next = newn;
    }
}

template <class T>
void SinglyLL<T> :: DeleteFirst()
{
    if(First == NULL)
    {
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct nodeS<T> * temp = First;
        First = temp -> next;
        delete temp;
    }
}

template <class T>
void SinglyLL<T> :: DeleteLast()
{
    if(First == NULL)
    {
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct nodeS<T> * temp = First;

        while(temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }
        delete temp -> next;
        temp -> next = NULL;
    }
}

template <class T>
void SinglyLL<T> :: DeleteAtPos(int ipos)
{
    int NodeCnt = 0;
    NodeCnt = Count();

    if((ipos < 1) || (ipos > NodeCnt))
    {
        cout<<"Invalid Position \n";
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == NodeCnt)
    {
        DeleteLast();
    }
    else
    {
        struct nodeS<T> * temp1 = First;

        for(int iCnt = 1; iCnt < ipos -1; iCnt++)
        {
            temp1 = temp1 -> next;
        }
        struct nodeS<T> * temp2 = temp1 -> next;

        temp1-> next = temp2 -> next;
        delete temp2;
    }
}

template <class T>
void SinglyLL<T> :: Display()
{
    cout<<"Elements of Linked List are : "<<"\n";

    struct nodeS<T> * temp = First;

    while(temp != NULL)
    {
        cout<<" | "<<temp -> data << " | ->";
        temp = temp -> next;
    }
    cout<<"NULL"<<"\n";
}

template <class T>
int SinglyLL<T> :: Count()
{
    struct nodeS<T> * temp = First;
    int iCnt = 0;

    while(temp != NULL)
    {
        iCnt++;
        temp = temp -> next;
    } 
    return iCnt;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Class of Singly Circular Linked List

template <class T>
class SinglyCL
{
    public:
        struct nodeS<T> * First;

        SinglyCL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

        void Display();
        int Count();
};

template <class T>
SinglyCL<T> :: SinglyCL()
{
    First = NULL;
    Last = NULL;
}

template <class T>
void SinglyCL<T> :: InsertFirst(T no)
{
    struct nodeS<T> * newn = new nodeS<T>;

    newn -> data = no;
    newn -> next = NULL;

    if((First == NULL) || (Last == NULL))
    {
        First = Last = newn;
        Last -> next = First;
    }
    else
    {
        newn -> next = First;
        First = newn;
        Last -> next = First;
    }
}

template <class T>
void SinglyCL<T> :: InsertLast(T no)
{
    struct nodeS<T> * newn = new nodeS<T>;

    newn -> data = no;
    newn -> next = NULL;

    if((First == NULL) || (Last == NULL))
    {
        First = Last = newn;
        Last -> next = First;
    }
    else
    {
        Last -> next = newn; 
        Last = newn;
        Last -> next = First;
    }
}

template <class T>
void SinglyCL<T> :: InsertAtPos(T no, int ipos)
{
    int NodeCnt = 0;

    NodeCnt =Count();
    if((ipos < 1) || (ipos > NodeCnt +1 ))
    {
        cout<<"Invalid Position \n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == NodeCnt + 1)
    {
        InsertLast(no);
    }
    else
    {
        struct nodeS<T> * newn = new nodeS<T>;

        newn -> data = no;
        newn -> next = NULL;

        struct nodeS<T> * temp = First;

        for(int iCnt = 1; iCnt < ipos - 1; iCnt++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next = newn;
    } 
}

template <class T>
void SinglyCL<T> :: DeleteFirst()
{
    struct nodeS<T> * temp = First;

    if((First == NULL) || (Last == NULL))
    {
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = Last = NULL;
    }
    else
    {
        First = temp -> next;
        delete temp;
        Last -> next = First;
    }
}

template <class T>
void SinglyCL<T> :: DeleteLast()
{
    struct nodeS<T> * temp = First;

    if((First == NULL) || (Last == NULL))
    {
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = Last = NULL;
    }
    else
    {
        while(temp -> next != Last)
        {
            temp = temp -> next;
        }
        delete temp -> next;
        Last = temp;
        Last -> next = First;
    }
}

template <class T>
void SinglyCL<T> :: DeleteAtPos(int ipos)
{
    int NodeCnt = 0;

    NodeCnt = Count();
    if((ipos < 1) || (ipos > NodeCnt))
    {
        cout<<"Invalid Position \n";
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == NodeCnt)
    {
        DeleteLast();
    }
    else
    {
        struct nodeS<T> * temp1 = First;

        for(int iCnt = 1; iCnt < ipos - 1; iCnt++)
        {
            temp1 = temp1 -> next;
        }
        struct nodeS<T> * temp2 = temp1 -> next;
        temp1 -> next = temp2 -> next;
        delete temp2;
    }
}

template <class T>
void SinglyCL<T>::Display()
{
    struct nodeS<T> * temp = First;

    cout<<"Elements of Linked List are : "<<"\n";
    cout<<"->";
    do
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp -> next;
    }while(temp != Last->next);
    cout<<"\n";
}

template <class T>
int SinglyCL<T> ::Count()
{
    struct nodeS<T> * temp = First;
    int iCnt = 0;

    do
    {
        iCnt++;
        temp = temp -> next;
    }while(temp != Last -> next);
    return iCnt++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Class of Doubly Linear Linked List

template <class T>
class DoublyLL
{
    public:
        struct nodeD<T> * First;

        DoublyLL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

        void Display();
        int Count();
};

template <class T>
DoublyLL<T> :: DoublyLL()
{
    First = NULL;
}

template <class T>
void DoublyLL<T> :: InsertFirst(T no)
{
    struct nodeD<T> * newn = new nodeD<T>;

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        First -> prev = newn;
        newn -> next = First;
        First = newn;
    }
}

template <class T>
void DoublyLL<T> :: InsertLast(T no)
{
    struct nodeD<T> * newn = new nodeD<T>;

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
       struct nodeD<T> * temp = First;

       while(temp -> next != NULL)
       {
        temp = temp -> next;
       }
       temp ->next = newn;
       newn -> prev = temp;
    }
}

template <class T>
void DoublyLL<T> :: InsertAtPos(T no, int ipos)
{
    int NodeCnt = 0;

    NodeCnt =Count();
    if((ipos < 1) || (ipos > NodeCnt + 1))
    {
        cout<<"Invalid Position \n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == NodeCnt + 1)
    {
        InsertLast(no);
    }
    else
    {
        struct nodeD<T> * newn = new nodeD<T>;

        newn -> data = no;
        newn -> next = NULL;
        newn -> prev = NULL;

        struct nodeD<T> * temp = First;

        for(int iCnt = 1; iCnt < ipos -1; iCnt++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        newn -> prev = temp;
        temp -> next -> prev = newn;
        temp -> next = newn;
    }
}

template <class T>
void DoublyLL<T> :: DeleteAtPos(int ipos)
{
    int NodeCnt = 0;

    NodeCnt = Count();

    if((ipos < 1) || (ipos > NodeCnt))
    {
        cout<<"Invalid Position \n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == NodeCnt)
    {
        DeleteLast();
    }
    else
    {
        struct nodeD<T> * temp1 = First;

        for(int iCnt = 1; iCnt < ipos -1; iCnt++)
        {
            temp1 = temp1 -> next;
        }
        struct nodeD<T> * temp2 = temp1 -> next;
        temp1 -> next = temp2 -> next;
        temp2 -> next -> prev = temp1;
        delete temp2;
    }
}

template <class T>
void DoublyLL<T> :: DeleteFirst()
{
    if(First == NULL)
    {
        return;
    }
    else if( First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First -> next;
        delete First -> prev;
    }
}

template <class T>
void DoublyLL<T> :: DeleteLast()
{
    if(First == NULL)
    {
        return;
    }
    else if( First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct nodeD<T> * temp = First;

        while(temp -> next -> next !=NULL)
        {
            temp = temp -> next;
        }
        delete temp -> next;
        temp -> next = NULL;
    }
}

template <class T>
void DoublyLL<T> :: Display()
{
    cout<<"Elements of Linked LIst are : "<<"\n";

    struct nodeD<T> * temp = First;
    printf("NULL <==> ");

    while(temp != NULL)
    {
        cout<<" | "<<temp -> data<< "| =>";
        temp = temp -> next;
    }
    cout<<"NULL"<<"\n";
}

template <class T>
int DoublyLL<T> ::Count()
{
    struct nodeD<T> * temp = First;
    int iCnt = 0;

    while(temp != NULL)
    {
        iCnt++;
        temp = temp -> next;
    }
    return iCnt;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Class of Doubly Circular Linked List

template <class T>
class DoublyCL
{
    public:
        struct nodeD<T> * First;

        DoublyCL();
        
        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);

        void Display();
        int Count();
};

template <class T>
DoublyCL<T> :: DoublyCL()
{
    First = NULL;
    Last = NULL;
}

template <class T>
void DoublyCL<T> :: InsertFirst(T no)
{
    struct nodeD<T> * newn = new nodeD<T>;

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        First -> prev = newn;
        newn -> next = First;
        First = newn;
    }
    First -> prev = Last;
    Last -> next = newn;
}

template <class T>
void DoublyCL<T>  :: InsertLast(T no)
{
    struct nodeD<T> * newn = new nodeD<T>;

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = Last = newn;
    }
    else
    {
       Last -> next = newn;
       newn -> prev = Last;
       Last = newn;
    }

    First -> prev = Last;
    Last -> next = First;
}

template <class T>
void DoublyCL<T> :: InsertAtPos(T no, int ipos)
{
    int NodeCnt = 0;

    NodeCnt =Count();
    if((ipos < 1) || (ipos > NodeCnt + 1))
    {
        cout<<"Invalid Position \n";
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == NodeCnt + 1)
    {
        InsertLast(no);
    }
    else
    {
    struct nodeD<T> * newn = new nodeD<T>;

        newn -> data = no;
        newn -> next = NULL;
        newn -> prev = NULL;

        struct nodeD<T> * temp = First;

        for(int iCnt = 1; iCnt < ipos -1; iCnt++)
        {
            temp = temp -> next;
        }
        
        newn -> next = temp -> next;
        temp -> next -> prev = newn;

        newn -> prev = temp;
        temp -> next = newn;
    }
}

template <class T>
void DoublyCL<T> :: DeleteAtPos(int ipos)
{
    int NodeCnt = 0;
    NodeCnt = Count();

    if((ipos < 1) || (ipos > NodeCnt))
    {
        cout<<"Invalid Position \n";
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == NodeCnt)
    {
        DeleteLast();
    }
    else
    {
        struct nodeD<T> * temp1 = First;

        for(int iCnt = 1; iCnt < ipos -1; iCnt++)
        {
            temp1 = temp1 -> next;
        }
        struct nodeD<T> * temp2 = temp1 -> next;

        temp1 -> next = temp2 -> next;
        temp2 -> next -> prev = temp1;
        delete temp2;
    }
}

template <class T>
void DoublyCL<T> :: DeleteFirst()
{
    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if( First == Last )
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First -> next;
        delete Last -> next;

        First -> prev = Last;
        Last -> next = First;
    }
}

template <class T>
void DoublyCL<T> :: DeleteLast()
{
    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if( First == Last )
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        Last = (Last) -> prev;
        delete (First)->prev;       // free((*Last)->next);

        (First)->prev = Last;
        (Last)->next = First;
    }
}

template <class T>
void DoublyCL<T>  :: Display()
{
    struct nodeD<T> * temp = First;

    if(First == NULL && Last == NULL)
    {
        cout<<"Linked list is empty"<<"\n";
        return;
    }

    cout<<"Elements of Linked list are : "<<"\n";
    cout<<"<=>";

    do
    {
        cout<<"| " <<temp->data<<"|<=> ";
        temp = temp -> next;
    }while(temp != Last->next);

    cout<<"\n";
}

template <class T>
int DoublyCL<T> :: Count()
{
    int iCnt = 0;
    struct nodeD<T> * temp = First;

    if(First == NULL && Last == NULL)
    {
        return iCnt;
    }

    do
    {
        iCnt++;
        temp = temp -> next;
    }while(temp != Last ->next);

    return iCnt;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    
    return 0;
}