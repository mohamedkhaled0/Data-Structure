#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#define ARRAY_ BASED_IMPLEMENTATION
//#define LINKED_BASED_IMPLEMENTATION


/***************************        ARRAY_ BASED_IMPLEMENTATION          *************************/

#ifdef  ARRAY_ BASED_IMPLEMENTATION
#define MAXLIST 100
typedef int ListElement;
typedef ListElement ListEntry;


typedef struct list1{
int Size ;
ListEntry entry [MAXLIST];
} List ;

// *  FUNCTION PROTOTYPE * //

void CreatList(List *pl);
int ListEmpty(List *pl);
int ListFull(List *pl);
int ListSize(List *pl);
void DestroyList(List *pl);
void InsertList(int p,ListEntry e,List *pl);
void DleteList (int p , ListEntry *pe , List *pl) ;
void RetrieveList (int p , ListEntry *pe , List*pl ) ;
void Replaclist(int p , ListEntry e , List*pl);
void TraverseList(List *pl ,void (*pf)(ListEntry));


#endif


/*************************      LINKED_BASED_IMPLEMENTATION               ************************/

#ifdef LINKED_BASED_IMPLEMENTATION

#define MAXLIST 100
typedef int ListElement;
typedef ListElement ListEntry;


typedef struct list_node {
ListEntry entry;
struct list_node *next;
}ListNode;


typedef struct list_ {
ListNode *head ;
int Size ;
}List ;


// *  FUNCTION PROTOTYPE * //

void CreatList(List *pl);
int ListEmpty(List *pl);
int ListFull(List *pl);
int ListSize(List *pl);
void DestroyList(List *pl);
void InsertList(int p,ListEntry e,List *pl);
void DleteList (int p , ListEntry *pe , List *pl) ;
void RetrieveList (int p , ListEntry *pe , List*pl ) ;
void Replaclist(int p , ListEntry e , List*pl);
void TraverseList(List *pl ,void (*pf)(ListEntry));



#endif // LINKED_BASED_IMPLEMENTATION





#endif // LIST_H_INCLUDED



