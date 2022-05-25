#include <stdio.h>
#define SIZE 50
void matrisYaz(double[][2*SIZE], int);
void matrisInverse(double[][2*SIZE], double[][2*SIZE],int );
int main() {
//DEÐÝÞKEN TANIMLAMASI VE MENU KISMI
	int i, j, N, exitt;
	double Matris[SIZE][2*SIZE],MatrisInverse[SIZE][2*SIZE];
	printf("\n\t\t\t\t~~ TERS MATRIS(INVERSE Matris)~~\n");
//Matrisi kullanicidan alan blok
	printf("NXN Kare matrisinizin N degerini giriniz:\n");
	scanf("%d",&N);
//EXIT DEGÝÞKENÝ ÝLE EÐER KULLANICI KÖÞEGENLERÝNDE 0 OLAN DEÐER GÝRERSE, UYARIP YENÝDEN ÝNPUT GÝRMESÝNÝ SAÐLIYORUM.
	do{
	exitt = 0;
	for(i=0 ; i<N ; i++){
		for(j=0 ; j<N ; j++){
			printf("Matrisin %d.Satir %d.Sutun elemani nedir?\n",i+1, j+1);
			scanf("%lf",&Matris[i][j]);
		}
		if(Matris[i][i] == 0){
			exitt = 1;
		}
	}
		if(exitt == 1){
			printf("MATH ERROR:\nMATRISIN KATSAYILARININ YERLERINI DEGISTIRIP TEKRAR DENEYINIZ\n(matris kosegen elemanlari 0'dan farkli olmali)!\n");	
			sleep(3);
			system("cls");
		}
	}while(exitt == 1);
	printf("\nMatrisiniz:\n");
	matrisYaz(Matris,N);
	matrisInverse(Matris,MatrisInverse,N);
	printf("\nMatrisinizin tersi:\n");
	matrisYaz(MatrisInverse, N);
	return 0;
}
//Matris yazdiran blok
void matrisYaz(double Matris[][2*SIZE],int N){
	int i,j;
	printf("\n");
	for(i=0 ; i<N ; i++){
		printf("|");
		for(j=0 ; j<N ; j++){
			printf(" %6.2f ",Matris[i][j]);
		}
		printf("|\n");
	}
}
//Gauss-Jordan ile inverse alma
void matrisInverse(double Matris[][2*SIZE],double MatrisInverse[][2*SIZE],int N){
	int i,j,k;
	double tmp;
	for(i=0 ; i<N ; i++){
		for(j=N ; j<2*N ; j++){
			if(i+N == j){
				Matris[i][j] = 1;
			}
			else{
				Matris[i][j] = 0;
			}
		}
	}
//Alt ucgen sifirlama
	for(i=0 ; i<N ; i++){
		tmp = Matris[i][i];
		for(j = 0 ; j<2*N ; j++){
			Matris[i][j] /= tmp;
		}
		for(j = i+1 ; j<N ; j++){
			tmp=Matris[j][i];
			for(k=i ; k<2*N ; k++){
				Matris[j][k] -= tmp*Matris[i][k];
			}
		}
	}
//Ust ucgen sifirlama
	for(i=N ; i>=0 ; i--){
		for(j=i-1 ; j>=0 ; j--){
			tmp=Matris[j][i];
			for(k=i ; k<2*N ; k++){
				Matris[j][k] -= tmp*Matris[i][k];
			}
		}
	}
	for(i=0;i<N;i++){
		for(j=0 ; j<N ; j++){
			MatrisInverse[i][j]=Matris[i][j+N];
		}
	}
}
