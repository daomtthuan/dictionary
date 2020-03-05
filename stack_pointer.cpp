//Cai dat Stack bang Pointer

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>

typedef int Element_Type;
typedef struct Node
{
	Element_Type Element;
	Node *Next;
};
typedef Node *Stack;


void Make_Null_Stack(Stack *S)
{
	(*S) = (Node*)malloc(sizeof(Node));
	(*S)->Next = NULL;
}

int Empty_Stack(Stack S)
{
	return (S->Next == NULL);
}

Element_Type Top(Stack S)
{
	return S->Next->Element;
}

void Pop(Stack *S)
{
	Node *T = (*S)->Next;
	(*S)->Next = (*S)->Next->Next;
	free(T);
}

void Push(Element_Type X, Stack *S)
{
	Node *T = (Node*)malloc(sizeof(Node));
	T->Element = X;
	T->Next = (*S)->Next;
	(*S)->Next = T;
}
