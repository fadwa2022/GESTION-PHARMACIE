#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ajouter;
int v;
//structure initiale
typedef struct {
    char nom[100];
    int code;
    int quantite;
    int prix; 
    float prixTTC;
    }produit;
//structure pour statistique
typedef struct{
    int jour;
    int mois;
    int annee;
    int prix;
    int quantitevendus;
    float prixttc;
}date_vendre;
//fct pour ajouter un ou plusieur produits
int ajouter_produit(produit P[],int N,int k){
int i;
printf ("\n\n                   ********************AJOUTE PRODUITS***************\n\n");
//tester le nombre de produit pour avoir si il est convenable avec le stock
do {printf("\n             ------------taper le nombre des produit que vous voulez ajouter--------------\n ");
   ca: if(scanf("%d",&ajouter)==0){
        fflush(stdin);
        printf("\n        SVP enter un nombre:\n ");
           goto ca;}
	 }while(N+ajouter>10000);
//pour que  N soit adapter a les neveaux produit
     N+=ajouter;
  for(i=3+k;i<N;i++){
    printf("\n       saisir le nom de produit :\t");
     scanf("%s",P[i].nom);
a:   printf("\n      saisir le code de produit :\t");
    if(scanf("%d",&P[i].code)==0){
        fflush(stdin);
        printf("\n        SVP enter un nombre\n ");
        goto a;}
b:   printf("\n      saisir la quantite de produit :\t");
    if(scanf("%d",&P[i].quantite)==0){
        fflush(stdin);
        printf("\n        SVP enter un nombre\n ");
        goto b;}
c:  printf("\n       saisir le prix de produit :\t");
    if(scanf("%d",&P[i].prix)==0){
        fflush(stdin);
        printf("\n      SVP enter un nombre\n");
        goto c;}
     P[i].prixTTC= P[i].prixTTC=(P[i].prix*15)/100+P[i].prix;
     }
     return N;
    }
//fct pour afficher les produits de stock
void affiche_produit(produit P[],int N){
    int i;
  printf("\n***********DONNEE DE STOCK***********\n\n");
   for(i=0;i<N;i++)
   { 
    printf("\n<<<<PRODUIT %d:>>>>\n",i+1);
    printf("\n NOM PRODUIT:%s \t CODE PRODUIT:%d \t QUANTITE PRODUIT:%d \t PRIX PRODUIT:%d \t PRIX PRODUIT TTC:%.2f \n",P[i].nom,P[i].code,P[i].quantite,P[i].prix,P[i].prixTTC);
   }
}
//fct pour afficher les produits de stock avec ordre prix
void lister_par_prix(produit P[],int N){
    int i,j;
     printf("\n              ***********DONNEE DE STOCK ORDONNER PAR PRIX***********\n\n");
//box est une structure pour switcher les structure
    produit box;
//ordonee par tri selection des structure
     for(i=0;i<N;i++){
         for(j=i;j<N;j++){
        if(P[i].prix<P[j].prix){
            box=P[i];
            P[i]=P[j];
            P[j]=box;
             }
             }
             }
affiche_produit(P,N);
}
//fct pour afficher les produits de stock avec ordre prix
void lister_par_alphabetique(produit P[],int N){
  int i,j;
produit box;
        printf("\n               ***********DONNEE DE STOCK ORDONNER PAR ALPHABET***********\n\n");
 for (i=0; i<N; i++){
    for (j=i; j<N; j++)
//la fonction strcmp pour comparer les noms des produits
      if (strcmp(P[i].nom,P[j].nom)>0){
      	box=P[i];
        P[i]=P[j];
        P[j]=box;
        }
 }

        affiche_produit(P,N);
  }
//fct pour modifier le stock ou cas de vendre
int Acheter_produit(produit P[],int N,date_vendre V[],int v){
	int i,code,quantite,erreur=0;
	printf("\n               ***********PRODUIT VENDUS***********\n\n");
m:	printf("\n  SAISIR LE CODE DE PRODUIT VENDUS : \n ");
	if(scanf("%d",&code)==0){
        fflush(stdin);
        printf("\n              SVP enter des nombre\n");
        goto m;}
H:	printf("\n  SAISIR LA QUANTITE ACHETER :\n ");
	 if(scanf("%d",&quantite)==0){
        fflush(stdin);
        printf("\n            SVP enter des nombre\n");
        goto H;}
    for (i = 0; i <N; i++)	{
    	if(P[i].code==code){
    		if(quantite>P[i].quantite)
    		  {
    		  	printf("\n CETTE QUANTITE N'EXISTE PAS DANS LE STOCK CHOISIR MOINS \n");
    		  	goto H;
			  }
//modifier la quantite de produit
    	P[i].quantite-=quantite;
//enregistrer la date de chaque modification de quantiter
         erreur++;
          v++;
         printf(" \n-----------------entrer la date d'achate de produite----------------- \n    ") ;
     ba: printf("\n L'ANNEE :  ");
     if(scanf("%d",&V[v].annee)==0){
        fflush(stdin);
        printf("\n           SVP enter un nombre\n");
        goto ba;}
do{  bc: printf("\n LE MOIS :  ");
        if(scanf ("%d",&V[v].mois)==0){
        fflush(stdin);
        printf("\n          SVP enter un nombre\n");
           goto bc;}
		 }while(V[v].mois>12);
        do{  printf("\n LE JOUR : ");
 bcd:  if(scanf ("%d",&V[v].jour)==0){
        fflush(stdin);
        printf("\nSVP enter un nombre\n");
           goto bcd;}
		 }while(V[v].jour>31);
         V[v].prix=P[i].prix;
         V[v].quantitevendus=quantite;
         V[v].prixttc=P[i].prixTTC;
		   	}
	} 
    if(erreur==0)
        printf("!!!!!!!!!!!! LE CODE QUE VOUS VOULER SAISIRE N'EXIST PAS DANS LE STOCK!!!!!!!!!!!\n");
	return v;
}
//fct pour trouver les produits a l aide de code produit
void Rechercher_produits_par_code(produit P[],int N){
int i,j,code[N],erreur=0,nombreproduit;
            printf("\n               ***********CHERCHER PRODUITS PAR CODE***********\n\n");
do{d:printf("\n SAISIRE LE NOMBRE DES CODE QUE VOUS VOULEZ TROUVER  \n ");
   if(scanf("%d",&nombreproduit)==0){
        fflush(stdin);
        printf("\n            SVP enter un nombre\n");
        goto d;}
  }while(nombreproduit>N);
 printf("\n             saisir les codes de produit:     \n");
   for(i=0;i<nombreproduit;i++){
     e:  
    if(scanf("%d",&code[i])==0){
        fflush(stdin);
        printf("\n        SVP enter un nombre\n");
        goto e;}
   }
  for(j=0;j<N;j++){
    for(i=0;i<nombreproduit;i++){
        if(P[j].code==code[i]){
    //erreur est pour verifier si le produit exist
    erreur++;
   printf("\n NOM PRODUIT:%s \t CODE PRODUIT:%d \t QUANTITE PRODUIT:%d \t PRIX PRODUIT:%d \n",P[j].nom,P[j].code,P[j].quantite,P[j].prix);
    }
    }
    }
    if(erreur==0)
        printf("!!!!!!!!!!!!\n LE CODE QUE VOUS VOULER SAISIRE N'EXIST PAS DANS LE STOCK\n!!!!!!!!!!!");

}
//fct pour trouver les produits a l aide de quantite produit
void Rechercher_produits_par_quantite(produit P[],int N){
int i,j,quantite[N],erreur=0,nombreproduit;
printf("\n               ***********CHERCHER PRODUITS PAR QUANTITE***********\n\n");
 do {
  e:  printf("\n        SAISIRE LE NOMBRE DES CODE QUE VOUS VOULEZ TROUVER:     \n ");
  if(scanf("%d",&nombreproduit)==0){
        fflush(stdin);
        printf("\n                SVP enter un nombre\n");
        goto e;
		}
  }while(nombreproduit>N);
 printf("\n             saisir les quantites de produit:     \n");
   for(i=0;i<nombreproduit;i++){
  f:  if(scanf("%d",&quantite[i])==0){
        fflush(stdin);
        printf("\nSVP enter un nombre\n");
        goto f;}
       }
   for(j=0;j<N;j++){
    for(i=0;i<nombreproduit;i++){
        if(P[j].quantite==quantite[i]){
    //erreur est pour verifier si le produit exist
    erreur++;
   printf("\n NOM PRODUIT:%s \t CODE PRODUIT:%d \t QUANTITE PRODUIT:%d \t PRIX PRODUIT:%d \n",P[j].nom,P[j].code,P[j].quantite,P[j].prix);
    }
    }
    }
    if(erreur==0){
       printf("\n!!!!!!!!!!!! LA QUANTITE QUE VOUS VOULER SAISIRE N'EXIST PAS DANS LE STOCK!!!!!!!!!!!\n");
   }
}
//fct pour verifier si il y a des produits qui on moins que 3 article
void Etat_sotock(produit P[],int N){
    int i,erreur=0;
    printf("\n\n                    ***********************ETAT DU STOCK*****************\n");
    printf("\n           produits pour acheter:\n");
     for(i=0;i<N;i++){
        if(P[i].quantite<=3){
        	//erreur est pour verifier si y a des produits qui on moins que 3 articles
                erreur++;
    printf("\n    <<<<%d PRODUIT>>>>\n",i+1);
    printf("\n NOM PRODUIT:%s \t CODE PRODUIT:%d \t QUANTITE PRODUIT:%d \t PRIX PRODUIT:%d \n",P[i].nom,P[i].code,P[i].quantite,P[i].prix);
            }
     }
     if(erreur==0)
        printf("\ntous les produits sont plus que 3 dans le stock\n");
}
//fct pour modifier la quantite des produit acheter par la pharmacie 
int Alimenter_stock(produit P[],int N){
int i,choix,Nouvelle_quantite,erreur=0;  
printf("\n               ***********METTRE A JOUR STOCK***********\n\n");
Q: 
  printf("\n inscrire le code du produit dans vous voulez mettre a jour la quantite: \n");
    hh: 
     if(scanf("%d",&choix)==0){
        fflush(stdin);
        printf("\n            SVP enter un nombre\n");
        goto hh;
		}
//trouver le produit dans le stock
     for(i=0;i<N;i++){
       if(P[i].code==choix){
	  //erreur est une variable qui nous ide pour verifier si le code exist
         erreur++;
         printf("\n   saisir la quantite que vous voulez ajouter: \n");
    g:   
         if(scanf("%d",&Nouvelle_quantite)==0){
        fflush(stdin);
        printf("\n      SVP enter un nombre\n");
        goto g;
		}
         P[i].quantite+=Nouvelle_quantite;
         printf("\n la quantite actuelle  %d\n",P[i].quantite);
		 }
		 }
     if(erreur==0){
        printf("\n!!!!!!!!!!!!!!!le code que vous voulez saisir n'existe pas!!!!!!!!!!!!!!!!!!!!!!!\n");
        goto Q;
                 }
}
//fct pour supprimer un produit 
void Supprimer_les_produits(produit P[],int N){
int i,j,supprimer,erreur=0;
       printf("\n                              ******************SUPPRIMER   PRODUIT*********************  \n\n");
       printf("\nENTRER LE CODE DE PRODUIT QUE VOUS VOULEZ LE SUPPRIMER:  \n");
     h:  
    if(scanf("%d",&supprimer)==0){
        fflush(stdin);
        printf("\n     SVP enter un nombre:\n  ");
        goto h;
		}
      for(i=0;i<N;i++)
        if(P[i].code==supprimer){
        	erreur++;
                for(j=i;j<N;j++)
                  P[j]=P[j+1];}
         if(erreur==0)
         printf("\n         !!!!!!CE PRODUIT N'EXISTE PAS DANS LE STOCK!!!!!!!!         \n\n");
		}
//fct pour voir les statistique du jour
int vendus_par_jour(produit P[],int N,int v,date_vendre V[]){
int i,annee,mois,jour;
int totalprixvendus=0;
float totalprixttcvendus=0;
int vendus=0;
int min=100000;
int max=0;
int erreur=0;
   printf("\n                           ***************STATISTIQUE*******************\n\n");
   printf("\nsaisir la date que vous voulez: \n");
   printf("\n L'ANNEE: ");
aa:  
 if(scanf("%d",&annee)==0){
        fflush(stdin);
        printf("\nSVP enter un nombre\n");
        goto aa;
		}
   printf("\n LE MOIS: ");
ab: 
   if(scanf("%d",&mois)==0){
        fflush(stdin);
        printf("\nSVP enter un nombre\n");
        goto ab;
		}
   printf("\n LE JOUR: ");
abc: 
    if(scanf("%d",&jour)==0){
        fflush(stdin);
        printf("\nSVP enter un nombre\n");
        goto abc;
		}
for(i=0;i<=v;i++){
  	if(V[i].annee==annee&&V[i].mois==mois&&V[i].jour==jour){
//erreur variable pour verifier si la date est enregestrer deja ou non 
  		erreur++;
	   totalprixvendus += V[i].quantitevendus * V[i].prix;
       totalprixttcvendus += V[i].quantitevendus * V[i].prixttc;
	  vendus+= V[i].quantitevendus ;
	  if(min>V[i].prix)
	   min=V[i].prix;
	  if(max<V[i].prix) 
	   max=V[i].prix;
	  } 
	}
	if(erreur==0)
     printf("\n\n                   !!!!!!!!!!AUCUN ARTICLE N'EST VENDU CE JOURS!!!!!!!!!!!!!\n");
 else{	
    printf(" \n\nLE PRIX TOTALE DES PRODUITS VENDUS A %d/%d/%d est : %d \n\n",jour,mois,annee,totalprixvendus);
    printf(" \n\nLE PRIX TOTALE TTC DES PRODUITS VENDUS A %d/%d/%d est : %.2f \n\n",jour,mois,annee,totalprixttcvendus);
    printf(" \n\nLA MOYENNE DES PRODUITS VENDUS A %d/%d/%d est : %.2f \n\n",jour,mois,annee,totalprixvendus/vendus);
    printf(" \n\nLE MINIMUM DES PRIX DES PRODUITS VENDUS A %d/%d/%d est : %d \n\n",jour,mois,annee,min);
    printf(" \n\nLE MAXIMUM DES PRIX DES PRODUITS VENDUS A %d/%d/%d est : %d \n\n",jour,mois,annee,max);
   }
}
void main(){
v =0;
int N=3,k=0;
char choixoperation,choixaffichage,choixrecherche,choixstatisique;
produit P[10000];
date_vendre V[10000];
//initialiser des produits dans le stock
  strcpy(P[0].nom,"Doliprane");
  P[0].code=0;
  P[0].quantite=40;
  P[0].prix=20;
  P[0].prixTTC=23;
  strcpy(P[1].nom,"Brexin");
  P[1].code=1;
  P[1].quantite=40;
  P[1].prix=2;
  P[1].prixTTC=2.03;
 strcpy(P[2].nom,"Aelicidine");
  P[2].code=2;
  P[2].quantite=40;
  P[2].prix=38;
  P[2].prixTTC=43.7;
printf("\n\n\n                     <<<<<<<<<<<<<GESTION DE PHARMACIE>>>>>>>>>>>>>\n\n\n");
X:
printf("                     SAISIR L'OPERATION QUE VOUS VOULEZ EFFECTUER                  \n");
printf("                  *****************************************************\n\n");
printf("                  *         1:AJOUTER DES PRODUITS                    *\n\n");        
printf("                  *         2:LISTER LES PRODUITS                     *\n\n");
printf("                  *         3:CHANGER LA QUANTITE DES PRODUITS VENDUS *\n\n");               
printf("                  *         4:RECHERCHER LES PRODUITS                 *\n\n");
printf("                  *         5:ETAT DU STOCK                           *\n\n");
printf("                  *         6:SUPPRIMER UN PRODUIT                    *\n\n");
printf("                  *         7:ALIMENTER LE STOCK                      *\n\n");
printf("                  *         8:STATIQUE DE VENTE                       *\n\n");
printf("                  *	    9:exit                                    *\n\n");
printf("                  *****************************************************\n");
scanf("%s",&choixoperation);
switch (choixoperation){
case '1':
     N=ajouter_produit(P,N,k);
     k+=ajouter;
     goto X ;
case '2':
Y:printf("\n            *********1:PRODUIT ARBITRAIREMENT*********\n\n             *********2:PRODUIT PAR ORDRE ALPHABETIQUE*********\n\n            *********3:PRODUIT PAR ORDRE DE PRIX*********\n\n            *********4:RETOUR A LA LISTE PRINCIPALE*********\n\n");
  scanf("%s",&choixaffichage);
  switch(choixaffichage){
   case '1':
    affiche_produit(P,N);
     goto X ;
   case '2':
    lister_par_alphabetique(P,N);
       goto X ;
    case '3':
       lister_par_prix(P,N);
        goto X ;
   case '4': goto X ;
   default:
   printf("                !!!!!!!!SAISIR UN CHOIX QUI EXISTE DANS LA LISTE!!!!!!!");
   goto Y;
   
    }
case '3':
    v = Acheter_produit(P,N,V,v);
    goto X ;
case '4':
   W: printf("\n            *********1:RECHERCHER PAR CODE*********\n             *********2:RECHERCHER PAR QUANTITE*********\n           *********3:RETOUR A LA LISTE PRINCIPALE*********\n");
    scanf("%s",&choixrecherche);
    switch(choixrecherche){
     case '1':
    Rechercher_produits_par_code(P,N);
     goto X;
    case '2':
   Rechercher_produits_par_quantite(P,N);
    goto X;
    case '3':
    goto X ;
    default:
    printf("                !!!!!!!!SAISIR UN CHOIX QUI EXISTE DANS LA LISTE!!!!!!!");
    goto W;
    }
case '5':
    Etat_sotock(P,N);
     goto X ;
case '6':
   Supprimer_les_produits(P,N);
   N--;
   goto X ;
case '7':
	Alimenter_stock(P,N);
	goto X ;
case '8':
   vendus_par_jour(P,N,v,V);
            goto X;
case '9':
   break;
default:
    printf("                !!!!!!!!SAISIR UN CHOIX QUI EXISTE DANS LA LISTE!!!!!!!\n");
    goto X;
}
}
