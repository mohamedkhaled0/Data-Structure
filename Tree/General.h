#ifndef GENERAL_H_INCLUDED
#define GENERAL_H_INCLUDED

#define EQ(a,b) ((a)==(b))
#define LT(a,b) ((a)<(b))
#define LE(a,b) ((a)<=(b))
#define GT(a,b) ((a)>(b))
#define GE(a,b) ((a)>=(b))

//#define EQ(a, b) (!strcmp((a), (b)))
//#define LT(a, b) (strcmp((a), (b))<0)
//#define LE(a, b) (strcmp((a), (b))<=0)
//#define GT(a, b) (strcmp((a), (b))>0)
//#define GE(a, b) (strcmp((a), (b))>=0)

typedef int KeyType ;

typedef struct elementtype {
 KeyType Key ;
}ElementType;



#endif // GENERAL_H_INCLUDED
