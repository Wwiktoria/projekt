#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

//ustalam wielkosc siatki
int rzad = 20;
int kolumna = 20;
int k=1;
char s='*';
char d=' ';


//tworzymy granice
int linia_rzedu(){
	printf("\n");
	//for(int i=0; i<kolumna; i++){printf(" -----");}
	//printf("\n");*/
}

//zwracamy ilość żywych sąsiadów
  int licz_ilosc_zywych_sasiadow(int a[rzad][kolumna], int   r, int c){
	  int i, j, count=0;
	  for(i=r-1; i<=r+1; i++){
		  for(j=c-1;j<=c+1;j++){
			  if((i==r && j==c) || (i<0 || j<0) || (i>=rzad ||   j>=kolumna)){
			  	continue;
			  }
			  if(a[i][j]==1){
				  count++;
		  	}
		  }
	  }
	  return count;
  }

int main(){


	  int a[rzad][kolumna], b[rzad][kolumna];
	  int i,j;
	  int zywe_komorki_sasiadow;
	  int c[rzad][kolumna];

	  //tworzę macierz z żywymi i martwymi komórkami (losowa)
	  for(i=0; i<rzad; i++){
		  for(j=0;j<kolumna;j++){
			  a[i][j] = rand() % 2;


		  }
	  }

	  /*wyświetlam macierz
	  printf("Pierwotna generacja:");
	    linia_rzedu();
	  for(i=0; i<rzad; i++){
		  //printf(":");
		  for(j=0;j<kolumna;j++){
			  //printf(" %d :",a[i][j]);
	  	}
		  linia_rzedu();
	  }*/
do{
    a[rzad][kolumna]=c[rzad][kolumna];
	  //obliczam zależności z żywymi sąsiadami
	  for(i=0; i<rzad; i++){
		  for(j=0;j<kolumna;j++){
			  zywe_komorki_sasiadow =licz_ilosc_zywych_sasiadow(a,i,j);
			  if(a[i][j]==1 && (zywe_komorki_sasiadow==2 ||   zywe_komorki_sasiadow==3)){
			  	b[i][j]=s;
			  }

			  else if(a[i][j]==0 && zywe_komorki_sasiadow==3){
				  b[i][j]=s;
			  }

			  else{
				  b[i][j]=d;
			  }
		  }
	  }

	  //wyświetlam następną generację
	  printf("\nNastępna generacja:");
	  linia_rzedu(rzad);
	  for(i=0; i<rzad; i++){
		 // printf(":");
		  for(j=0;j<kolumna;j++){
			  printf(" %c ",b[i][j]);
		  }
		  linia_rzedu(rzad);
	  }


c[i][j]= b[i][j];
Sleep(2000);
system("cls");
}while(k>0);

return 0;}

	