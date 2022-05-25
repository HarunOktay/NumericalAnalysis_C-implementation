#include <stdio.h>
#include <math.h>
#include <windows.h>
#define SIZE 50
double gaussSeidal(double [][SIZE],double[], int , int ,double*);
int main() {
//DEGÝSKEN TANIMLAMASI VE MENU KISMI
	int i, j, N;
	double max, MISS, tmp[SIZE], dx,Matris[SIZE][SIZE], root[SIZE];
	printf("\n\n\n\n\n\t\t\t\t\t~~GAUSS-SEIDAL METODU~~\n");
	sleep(3);
	system("cls");
	printf("gireceginiz denklemin bilinmeyen sayisi:\n");
	scanf("%d",&N);
	printf("Sapma payini giriniz.\n(NOT:Sapma payini ne kadar kucuk alirsaniz koke o kadar cok yaklasirsiniz.)");
	scanf("%lf",&MISS);
	printf("\n\t\t\t\t\t!!!!!ONEMLI NOT!!!!!\n \t\tDENKLEMLERI GIRERKEN EN BUYUK SAYILAR KOSEGENLERE GELECEK SEKILDE GIRINIZ:\n");
	sleep(3);

//DENKLEMLERI MATRISE TANIMLAYAN BLOK
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("Matris[%d][%d] degerini giriniz.",i+1,j+1);
			scanf("%lf",&Matris[i][j]);
		}
		printf("%d. denklemin sonucu nedir?\n",i+1);
		scanf("%lf",&Matris[i][N]);
	}
	for(i=0;i<N;i++){
		tmp[i]=1;
	}
//MATRISI YAZDIRAN BLOK
	for(i=0;i<N;i++){
		printf("|");
		for(j=0;j<N;j++){
			printf(" %lf ",Matris[i][j]);
		}
		printf("/ %lf |\n",Matris[i][N]);
	}
//GAUSS SEIDEL FONKSIYONUNU CAGIRIYORUM
	do{
		max=0;
		for(i=0;i<N;i++){
			root[i] = gaussSeidal(Matris,root,i,N,&max);
		}
		dx=max;
	}while(dx > MISS);
	printf("\n\nKokler: ");
	for(i=0;i<N;i++){
		printf(" x%d=%lf ",i+1,root[i]);
	}
return 0;
}
//GAUSS SEIDEL ALGORITMASININ UYGULANDIGI KISIM:
double gaussSeidal(double Matris[][SIZE],double root[], int i, int N,double *max){
	int j;
	double tmp=0,dx;
	for(j=0 ; j<N ; j++){
		if(i!=j){
			tmp += -1*Matris[i][j]*root[j];
		}
	}
	tmp += Matris[i][N];
	tmp /= Matris[i][i];
	dx=fabs(root[i]-tmp);
	if(dx >* max ){
		*max = dx;
	}
	return tmp;
}
