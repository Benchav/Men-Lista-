#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct elemento
{
   int info;
   struct elemento *sig;
}nodo;


void mensaje(void);	//Funcion para mensaje
int menu(void);  	//Funcion para Menu de opciones
nodo *nuevoelemento(void);
nodo *crearlista(nodo *);
nodo *insertainicio(nodo *, int);
nodo *insertafinal(nodo *,int);
nodo *insertaAX(nodo *p, int,int);
nodo *insertaDX(nodo *p, int,int);
void visualizar(nodo *);
nodo *eliminarinicio(nodo *);
nodo *eliminarultimo(nodo *p);
nodo *eliminarAX(nodo *p, int);
nodo *eliminarDX(nodo *p, int);
void *buscar(nodo *,int);
int main()
{
   nodo *p,*q;
   int num,elem,opc,flag=0;
   do
   {
      opc=menu();
      switch(opc)
      {
	 case 1:
	    p=crearlista(p);
	    mensaje();
	    break;
	 case 2:
	    printf("\nLa lista es la siguiente\n");
	    visualizar(p);
	    mensaje();
	    break;

    case 3:
	    printf("\nDe el elemento a insertar : ");
	    scanf("%d",&num);
	    p=insertainicio(p,num);
	    mensaje();
	    break;

    case 4:
	    printf("\nDe el elemento a insertar : ");
	    scanf("%d",&num);
	    p=insertafinal(p,num);
	    mensaje();
	    break;
    case 5:
	    printf("\nDe el elemento a insertar : ");
	    scanf("%d",&num);
       printf("\nDe la referencia del Elemento a Insertar (X): ");
	    scanf("%d",&elem);
	    p=insertaAX(p,num,elem);
	    mensaje();
	    break;
    case 6:
	    printf("\nDe el elemento a insertar : ");
	    scanf("%d",&num);
	    printf("\nDe la referencia del Elemento a Insertar (X): ");
	    scanf("%d",&elem);
       p=insertaDX(p,num,elem);
	    mensaje();
	    break;
	 case 7:
	    p=eliminarinicio(p);
	    mensaje();
	    break;
	 case 8:
	    p=eliminarultimo(p);
	    mensaje();
	    break;
	 case 9:
	    printf("\nDe la referencia del Elemento a Eliminar (X): ");
	    scanf("%d",&elem);
	    p=eliminarAX(p,elem);
	    mensaje();
	    break;
    case 10:
	    printf("\nDe la referencia del Elemento a Eliminar (X): ");
	    scanf("%d",&elem);
	    p=eliminarDX(p,elem);
	    mensaje();
	    break;
    case 11:
	    printf("\nDe el Elemento a Buscar: ");
	    scanf("%d",&elem);
	    buscar(p,elem);
	    mensaje();
	    break;
	 case 12:
	    flag=1;
	    break;
      }
   }while(!flag);
}

void mensaje(void)
{
   printf("\n\nPresione una tecla para continuar....");
   getch();
}

int menu(void)
{
   int opcion;
  // clrscr();
   printf("MENU DE LISTA");
   printf("\n1 -> Crear la Lista");
   printf("\n2 -> Visualizar la Lista");
   printf("\n3 -> Insertar al Inicio");
   printf("\n4 -> Insertar al Final");
   printf("\n5 -> Insertar antes de X");
   printf("\n6 -> Insertar Despues de X");
   printf("\n7 -> Eliminar al Inicio");
   printf("\n8 -> Eliminar al Final");
   printf("\n9 -> Eliminar antes de X");
   printf("\n10 -> Eliminar despues de X");
   printf("\n11 -> Buscar un Nodo");
   printf("\n12 -> SALIR");
   printf("\n\nDE SU OPCION : ");
   scanf("%d",&opcion);
   return(opcion);
}

nodo *nuevoelemento()
{
   return((nodo *) malloc(sizeof(nodo)));
}

nodo *crearlista(nodo *p)
{
   nodo *q,*t;
   char resp;
 //  clrscr();
   p=nuevoelemento();
   printf("\nDe la informacion del nodo : ");
   scanf("%d",&p->info);
   p->sig=NULL;
   t=p;
   printf("\nDesea introducir otro nodo [s/n] ? ");
   scanf(" %c",&resp);
   while (toupper(resp)=='S')
   {
      q=nuevoelemento();
      printf("\nDe la informacion del nodo : ");
      scanf("%d",&q->info);
      q->sig=NULL;
      t->sig=q;
      t=q;
      printf("\nDesea introducir otro nodo [s/n] ? ");
      scanf(" %c",&resp);
   }
   return(p);
}

void visualizar(nodo *p)
{
   nodo *q;
   q=p;
   while(q!=NULL)
   {
      printf(" %d",q->info);
      q=q->sig;
   }
}


nodo *insertainicio(nodo *p,int num)
{
   nodo *q,*t;
   t=nuevoelemento();
   t->info=num;
   t->sig=p;
   p=t;
   return(p);
}

nodo *insertafinal(nodo *p,int num)
{
   nodo *q,*t;
   q=p;
   while(q->sig!=NULL)
   {
      q=q->sig;
   }
   t=nuevoelemento();
   t->info=num;
   t->sig=NULL;
   q->sig=t;
   return(p);
}

nodo *insertaAX(nodo *p, int num,int elem)
{
  	nodo *q,*t,*r;
  	int band=1;
   t=p;
   q=p;

   while((q->info!=elem)&&(band==1))
   {
   	if(q->sig!=NULL)
      {
        t=q;
        q=q->sig;
      }
      else band=0;
   }
   if(band==1)
   {
   r=nuevoelemento();
   r->info=num;
   	if(p==q)
      {
      	r->sig=p;
      	p=r;
      }
      else
      {
      	t->sig=r;
      	r->sig=q;
      }
   }
   else
   {
    printf("\nEl Nodo dado como Referencia no se Encuentra");
   }
 return(p);
}
nodo *insertaDX(nodo *p, int num,int elem)
{
  	nodo *q,*t;
  	int band=1;
   q=p;

   while((q->info!=elem)&&(band==1))
   {
   	if(q->sig!=NULL)
      {
        q=q->sig;
      }
      else
      {band=0;}
   }
   if(band==1)
   {
   t=nuevoelemento();
   t->info=num;
   t->sig=q->sig;
   q->sig=t;
   }
   else
   {
    printf("\nEl Nodo dado como Referencia no se Encuentra");
   }
 return(p);
}

nodo *eliminarinicio(nodo *p)
{
   nodo *q,*t;
   q=p;
   printf("\nElemento eliminado %d ",q->info);
   p=q->sig;
   free(q);
   return(p);
}
nodo *eliminarultimo(nodo *p)
{
   nodo *q,*t;
   q=p;
   if (p->sig==NULL)
      p->sig=NULL;
   else
   { while(q->sig!=NULL)
      {
      t=q;
      q=q->sig;
      }  t->sig=NULL;
   }

   printf("\nElemento eliminado %d ",q->info);
   free(q);
   return(p);
}
nodo *eliminarAX(nodo *p, int elem)
{
   nodo *q,*t,*r;
   int band=1;

   if (p->info==elem)
     printf("\nNo Existe un nodo que preseda a X\n");

   else
   { q=p;
     t=p;
     band=1;
    while ((q->info != elem) && (band==1))
      {
      if (q->sig!=NULL)
          {
            r=t;
            t=q;
            q=q->sig;
	   }
	else band=0;
      }

    if (band==0)
       printf("\El elemnto no se encuentra en la lista\n");
    else
    {
     if (p->sig==q)
       p=q;
     else
       r->sig=q;
     printf("\nElemento eliminado %d ",t->info);
     free(t);
    }
   }

  return(p);
}
nodo *eliminarDX(nodo *p, int elem)
{
   nodo *q,*t,*r;
   int band=1;

   if (p->info==elem)
     printf("\nNo Existe un nodo que postseda a X\n");

   else
   { q=p;
     t=p;
     r=p;
     band=1;
    while ((r->info!=elem) && (band==1))
      {

      	if (r->sig!=NULL)
      	{
            r=t;
            t=q;
            q=q->sig;
	   	}
			else band=0;
      }
    	if (band==0)
       printf("\El elemnto no se encuentra en la lista\n");
    	else
    	{
     	if (p->sig==q)
       p=q;
     	else
       r->sig=q;
     printf("\nElemento eliminado %d ",t->info);
     free(t);
    }
   }

  return(p);
}

void *buscar(nodo *p,int elem)
{  bool b=false;
 	nodo *q;
   q=p;
   while(q!=NULL)
   {
   if(q->info==elem)
      {
      printf("Existe el elemento %d",elem,"en la Lista");
      b= true; break;
      }
      q=q->sig;
   }
   if(b==false)
   {printf("Error==> No Existe el Elemento %d",elem,"en la Lista");}
}







