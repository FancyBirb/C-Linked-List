//Name: Domenic Bartha 								 Mtr-Nr: 813646

#include <stdio.h>
#include <stdlib.h>

struct le
{
	int value;
	struct listenelement *next;
};
typedef struct le listenelement;
typedef listenelement *list;
// muss ich die gegebenen sachen jetzt auch kommentieren ?
int delete_pos(list *l, int pos);
void print_list(list l);
void insert(int v, list *l);
void delete_all(list *l);
int position_of(int v, list l);
list filter_even(list l); 

int main()
{
	// aufgabe 5: 
	list l = NULL;
	list leer = NULL;
	insert(0, &l);
	insert(1, &l);
	insert(2, &l);
	insert(3, &l);
	insert(4, &l);
	insert(5, &l);
	insert(6, &l);
	insert(7, &l);
	print_list(l);
	printf("%d\n", position_of(9,l));
	printf("%d\n", position_of(3,l));
	print_list(l);
	delete_pos(&l,1);
	printf("\n");
	print_list(l);
	print_list(filter_even(l));
	// jetzt die leere liste 
	printf("\nLeere liste ergiebt :");
	print_list(leer);
	printf("%d\n", position_of(3,leer));
	print_list(leer);
	delete_pos(&leer,1);
	printf("\n");
	print_list(leer);
	print_list(filter_even(leer));

}

void insert(int v, list *l) 
{
	listenelement *new;
	new = malloc(sizeof(listenelement));
	new->value = v;
	new->next = *l;
	*l = new;

}

void print_list(list l)
{
	printf("\nliste ist :");
	if (l == NULL)
	{
		printf("leer");
	}
	else
	{
		while (l != NULL)
		{
			printf("%d ", l->value);
			l = l->next;
		}
		printf("\n");
	}
}

void delete_all(list *l)
{
	list next;
	while (*l != NULL)
	{
		next = (*l)->next;
		free(*l);
		*l = next;
	}
}

int position_of(int v, list l)
{
	printf(" postion von %d ist: ",v);
	if (l == NULL)     // wenn lehre liste 
	{
      return-1;
	}
	int count = 0;		// die jute zählvariable 

	while (l != NULL)	// gehe solange bis liste endet 
	{
		if (v == l->value)	// wenn das gesuchte element gleich dem listen element entspricht 
		{
			return count;	// gebe den count ( also an welcher stelle sich v befindet ) wieder
		}
		count++;			// und solange das if nicht aktiviert wird eherhöhere den count 
		l = l->next;		// und gehe tiefer in die list / gehe die liste weiter entlang
	}	
	return -1;				// wenn die liste == null erreicht endet die wile schleife und die abbruch bedingung wird wieder gegeben.
}

int delete_pos(list *l, int pos)  // ich nenen die funktion auch gerne Frankensteins Monster, weil sie auch so zerstückelt und Zerfelderd aussieht.
{	
	list tmp=NULL;			// die neue liste, it is ^^
	tmp = *l; 				// meine kleine safe insel zum zurücksetzen des pointers, setzt aber auch die pointervalues gleich
	int aktuellepos = 0;	// keeps track of my current position in list 
	/*  printf("%p",*l);
		printf("%p",l); ich versetehe den unterschied nicht pls help // update ich verstehs 
	*/
	 if (*l == NULL)    // wenn lehre liste 
   {
      return-1;			// brech ab, nicht erfolgreich
   }

	if (pos == 0) {			// um Head zu entfernen/ neu zusetzen 
		*l= (*l)->next; 	//head auf den nächsten list element bringen
		tmp->next = NULL; 	//schadet nicht ^^
    	free(tmp);			//den speicherplatz befreien wo tmp hinzeigt
    	return 0; 			// Tada liste ist clear von position 0
	}else{

		while (aktuellepos < pos-1) //geht vor dem delete element und ist auch nur dafür da um die liste vor dem delete obj zu bringen
		{	
			if ((*l)->next== NULL){	// soll segmentation fault verhindern 
				*l = tmp;			// und resetet die liste, als ein safty first mechanism
				return -1;
			}else{
			*l = (*l)->next;	// hier wird die liste vowärts gebracht 
			aktuellepos++;		// folgt der aktullen position in der liste 
			}
		}
		if ((*l)->next== NULL){		//abruchbedingung falls die prosition nicht in der liste ist 
				printf("\nout of bound: position not included in list"); 
				*l=tmp;				// da kommt die safe insel in einsatz: um den pointer wieder auf anfang zu bringen
				return -1;
			}
		
		list del = (*l)->next; 	//extravariable zum deleten       (man könnte auch tmp nutzen aber durch zu viel rumprobieren ist mir der weg lieber)
		(*l)->next = del->next; // neuverkettung vorm delete objekt und dem nachvolgenden
		printf("\nElement deleted is : %d",del->value);		// nice to have 
		del->next= NULL;									// nice to have i guess
		*l = tmp; 				// den pointer wieder auf den listen anfang stellen 
		free(del);				// joa nh speicher befreien 			
		
		return 0;				//alles andere als clean code aber funktioniert xD sry das du das nachvollziehen musst was ich hier mache
	}
}

list filter_even(list l)
{
	int x = 0;         // ein überbleibsel der debugg zeit. damit habe ich probiert zu schecken welche iteration sich die schleife befindet 
	list tmp = NULL; 	//new filter list erstellen
	list even = NULL;
	while (l!=NULL)									//läuft die orginal liste durch 
	{
		if (l->value%2==0){							// wenn value in liste gleich even
			insert(l->value,&tmp);					//insert in neue liste
			
		}
	l=l->next; 										//you know the drill :)
	}
	// jetzt muss die liste nochmal invertiert werden um der oginal reinfolge zu entprechen und benutze ich die insert funktion als push funktion 
	while (tmp!=NULL)
	{
		insert(tmp->value,&even);	// ja hier wird halt die liste umgekehrt 
		tmp=tmp->next;				// immer vorwärts in die liste hinein :)
	}
	
	return even;					// qud. das was gefragt war, wird wieder gegeben
	}
									// sorry für die albernen kommentare, war eine kleine tortur den code zu schreiben und dadurch auch eine lange nacht 
									// hab an vielen dingen zu kompliziert gedacht und mich hat der "Typdef listenelemnt *list" verwirrt da ich es nur mit "**"" kenne und ich öfters nicht wusste womit ich jetzt arbeite. 		


	// sooo ich bin durch. Ich lasse mal meine fehler drinne aber als komemntar:
	// viele printf sind drinn um zu scheuen wo die fehler sind 
	// in der form wie die funktion da steht ist sie mir in einer endlosschleife geraten xD
	/*
list filter_even(list l)
{
	int x = 0;
	list tmp = NULL; //new filter list erstellen
	while (l!=NULL)									//läuft die orginal liste durch 
	{
		if (l->value%2==0){							// wenn value in liste gleich even
			 
			listenelement *new;						// neues element 
			new = malloc(sizeof(listenelement));	// das neu zu erstellene element bracht ein speicher ort 
			new->value = l->value;					// even brauch halt den geraden value aus l
			new->next = tmp;						// und muss halt zum nächten even element pointer
			tmp = new;
			printf("%p %d\n",tmp,x);			// test stuff weil ich fehler habe
			x++;													// dann füge es in der even liste ein 
		}
		l = l->next; // der durchlauf parameter
		
	}
	// jetzt muss die liste nochmal invertiert werden um der oginal zu entprechen und dafür kopiere ich die push funktion 
	list even = NULL;
	printf("first pointer of tmp%p\n",tmp);
	printf("first value of tmp%d\n",tmp->value);
	int z=0;
	while (tmp!=NULL)
	{
		//reverseforeven(tmp->value,tmp);
		printf("%d",z);
		z++;
		printf(" %d\n",tmp->value);
		tmp=tmp->next;
		
		
	}
	

	return even;	
}

void reverseforeven(int v, list *even){
	listenelement *new;
	new = malloc(sizeof(listenelement));
	new->value = v;
	new->next = *even;
	*even = new;

}
*/
