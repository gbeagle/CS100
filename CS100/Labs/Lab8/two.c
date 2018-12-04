#include <stdio.h>
#include <stdlib.h>

typedef struct letters {
	char info;
	struct letters *next;	//points to another struct letter
} Letter;

int main(void){

	Letter *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l, *m;


	a = malloc( sizeof(Letter) );
	b = malloc( sizeof(Letter) );
	c = malloc( sizeof(Letter) );
	d = malloc( sizeof(Letter) );
	e = malloc( sizeof(Letter) );
	f = malloc( sizeof(Letter) );
	g = malloc( sizeof(Letter) );
	h = malloc( sizeof(Letter) );
	i = malloc( sizeof(Letter) );
	j = malloc( sizeof(Letter) );
	k = malloc( sizeof(Letter) );
	l = malloc( sizeof(Letter) );
	m = malloc( sizeof(Letter) );

	a->info = 'E';   a->next = b;
	b->info = 'L';   b->next = c;
	c->info = 'E';   c->next = d;
	d->info = 'V';   d->next = e;
	e->info = 'E';   e->next = f;
	f->info = 'N';   f->next = g;
	g->info = 'P';   g->next = h;
	h->info = 'L';   h->next = i;
	i->info = 'U';   i->next = j;
	j->info = 'S';   j->next = k;
	k->info = 'T';   k->next = l;
	l->info = 'W';   l->next = m;
	m->info = 'O';   m->next = NULL;

	Letter *ptr = a;
	while(ptr != NULL){
		printf("%c ", ptr->info);	
		ptr = ptr->next;
	}
	printf("\n");

	a->info = 'E';   a->next = b;
	b->info = 'L';   b->next = d;
	c->info = 'E';   c->next = NULL;
	d->info = 'V';   d->next = e;
	e->info = 'E';   e->next = g;
	f->info = 'N';   f->next = c;
	g->info = 'P';   g->next = h;
	h->info = 'L';   h->next = i;
	i->info = 'U';   i->next = j;
	j->info = 'S';   j->next = m;
	k->info = 'T';   k->next = l;
	l->info = 'W';   l->next = a;
	m->info = 'O';   m->next = f;

	ptr = k;
	while(ptr != NULL){
		printf("%c ", ptr->info);	
		ptr = ptr->next;
	}
	printf("\n");

	return 0;
}



