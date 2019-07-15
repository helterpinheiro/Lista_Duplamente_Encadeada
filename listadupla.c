#ifndef LISTADUPLA_C_
#define LISTADUPLA_C_

#include "listadupla.h"
#include <stdlib.h>
#include <stdio.h>

//cria a lista dupla
Dllist* dllCreate()
{
	Dllist *l;
	l=(Dllist *)malloc(sizeof(Dllist));
	if(l!=NULL){
		l->first = NULL;
		l->cur = NULL;
		return l;
	}
	return NULL;
}

//funcao retorna o primeiro elemento da lista
Dllist* dllFirst(Dllist *l)
{
	if(l!=NULL){
		if(l->first!=NULL){
			l->cur=l->first;
			return l->cur->data;
		}
	}
	return NULL;
}

//funcao retorna o proximo elemento da lista a partir do cur
void* dllGetNext(Dllist *l)
{
	if(l!=NULL){
		if(l->cur->next!=NULL){
			l->cur=l->cur->next;
			return l->cur->data;
		}
	}
	return NULL;
}

// Insere na primeira posicao da lista
int dllInsertFirst(Dllist *l, void *data)
{
	Dlnode *newnode;
	if(l!=NULL){
		newnode = (Dlnode*)malloc(sizeof(Dlnode));
		if(newnode!=NULL){
			newnode->data=data;
			newnode->next = l->first;
			newnode->prev = NULL;
			l->first = newnode;
			return TRUE;
		}
	}
	return FALSE;
}

//funcao insere na ultima posicao da lista
int dllInsertLast(Dllist *l, void *data)
{
	Dlnode *newnode, *last;

	if(l!=NULL){
		if(l->first!=NULL){
			last = l->first;
			while(last->next!=NULL){
				last = last->next;
			}
			newnode=(Dlnode*)malloc(sizeof(Dlnode));
			if(newnode!=NULL){
				newnode->data = data;
				newnode->next = last->next;
				newnode->prev = last;
				last->next = newnode;
				return TRUE;
			}
		}
	}
	return FALSE;
}

//AUTO DESTRUICAO
int dllDestroy(Dllist *l)
{
	if(l->first==NULL){
			free(l);
			return TRUE;
	}
	return FALSE;
}


//remove determinado no da lista
void* dllRemoveSpec(Dllist *l, void* key, int(*comp)(void*,void*))
{
	Dlnode *cur, *prev;
	int stat;
	void*data;
	if(l!=NULL){
		if(l->first!=NULL){
			cur=l->first;
			stat=comp(key,cur->data);
			while(stat!=NULL && cur->next!=NULL){
				cur=cur->next;
				stat=comp(key,cur->data);
			}
			if(stat == TRUE){
				if(cur == l->first){
                    data = cur->data;
                    l->first = cur->next;
                    free(cur);
				}else{
				    if(cur->next!=NULL){
                        data = cur->data;
                        cur->prev->next = cur->next;
                        cur->next->prev = cur->prev;
                        free(cur);
				    }else{
                        data = cur->data;
                        cur->prev->next = cur->next;
                        free(cur);
				    }
				}
			}
			return data;
		}
	}
    return NULL;
}

// funcao retorna elemento em qualquer posicao na lista
void *dllQuery(Dllist *l, void *key, int(*comp)(void*,void*))
{
    Dlnode *cur;
	int stat;
	if(l!=NULL){
		if(l->first!=NULL){
			cur=l->first;
			stat=comp(key,cur->data);
			while(stat!=TRUE && cur->next!=NULL){
				cur=cur->next;
				stat=comp(key,cur->data);
			}
			if(stat==TRUE){
				return cur->data;
			}
		}
	}
	return NULL;
}
//retorna o numedo de elementos da lista
int dllNumElm(Dllist *l)
{
	int cont=0;
	Dlnode *cur;
	if(l!=NULL){
		if(l->first!=NULL){
			cur=l->first;
			cont++;
			while(cur->next!=NULL){
				cur=cur->next;
				cont++;
			}
			return cont;
		}
	}
	return FALSE;
}

// insere apos o no especificado
int dllInsertAfterSpec(Dllist *l, void* key, int(*comp)(void*,void*),void* data)
{
    int stat;
    Dlnode *cur,*newnode;
    if(l!=NULL){
        if(l->first!=NULL){
            cur = l->first;
            stat = comp(key,cur->data);
            while(stat!=TRUE && cur->next!=NULL){
                    cur=cur->next;
                    stat = comp(key,cur->data);
            }
            if(stat == TRUE){
                newnode=(Dlnode*)malloc(sizeof(Dlnode));
                if(newnode!=NULL){
                    if(cur->next!=NULL){
                        newnode->data = data;
                        newnode->next = cur->next;
                        newnode->prev=cur;
                        cur->next->prev=newnode;
                        cur->next=newnode;
                    }else{
                        newnode->data = data;
                        newnode->next = cur->next;
                        newnode->prev=cur;
                        cur->next = newnode;

                    }
                    return TRUE;

                }
            }
        }
    }
    return FALSE;
}

int dllInsertBeforeSpec(Dllist *l, void* key,int(*comp)(void*,void*),void* data)
{
    int stat;
    Dlnode *cur,*newnode;
    if(l!=NULL){
        if(l->first!=NULL){
            cur = l->first;
            stat = comp(key,cur->data);
            while(stat!=TRUE && cur->next!=NULL){
                    cur=cur->next;
                    stat = comp(key,cur->data);
            }
            if(stat == TRUE){
               newnode = (Dlnode*)malloc(sizeof(Dlnode));
               if(newnode!=NULL){
                    if(cur==l->first){
                        newnode->data=data;
                        newnode->next = cur;
                        newnode->prev = cur->prev;
                        cur->prev=newnode;
                        l->first=newnode;
                    }else{
                        newnode->data=data;
                        newnode->next = cur;
                        newnode->prev=cur->prev;
                        cur->prev->next=newnode;
                        cur->prev=newnode;
                        }
                    }
               }
               return TRUE;
            }

    }
    return FALSE;
}

#endif
