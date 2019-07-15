#ifndef LISTADUPLA_H_
#define LISTADUPLA_H_
#define TRUE 0
#define FALSE 1

typedef struct _slnode_{
	struct _slnode_ *next;
	struct _slnode_*prev;
	void *data;
}Dlnode;

typedef struct _dllist_{
	Dlnode *first;
	Dlnode *cur;
}Dllist;

#ifdef LISTADUPLA_C_
// todas as funcoes aqui
	Dllist* dllCreate();
	Dllist* dllFirst(Dllist *l);
	void* dllGetNext(Dllist *l);
	int dllInsertFirst(Dllist *l, void *data);
	int dllInsertLast(Dllist *l, void *data);
	int dllDestroy(Dllist *l);
	void* dllRemoveSpec(Dllist *l, void* key, int(*comp)(void*,void*));
	void *dllQuery(Dllist *l, void *key, int(*comp)(void*,void*));
	int dllNumElm(Dllist *l);
	int dllInsertAfterSpec(Dllist *l, void* key, int(*comp)(void*,void*),void* data);
	int dllInsertBeforeSpec(Dllist *l, void* key,int(*comp)(void*,void*),void* data);
#else
/// todas as funcoes aqui com extern
	extern Dllist* dllCreate();
	extern Dllist* dllFirst(Dllist *l);
	extern void* dllGetNext(Dllist *l);
	extern int dllInsertFirst(Dllist *l, void *data);
	extern int dllInsertLast(Dllist *l, void *data);
	extern int dllDestroy(Dllist *l);
	extern void* dllRemoveSpec(Dllist *l, void* key, int(*comp)(void*,void*));
	extern void *dllQuery(Dllist *l, void *key, int(*comp)(void*,void*));
	extern int dllNumElm(Dllist *l);
	extern int dllInsertAfterSpec(Dllist *l, void* key, int(*comp)(void*,void*),void* data);
	extern int dllInsertBeforeSpec(Dllist *l, void* key,int(*comp)(void*,void*),void* data);
#endif //LISTADUPLA_C_

#endif// LISTASUPLA_H_
