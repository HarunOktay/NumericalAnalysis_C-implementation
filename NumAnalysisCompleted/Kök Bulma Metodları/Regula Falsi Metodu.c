#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#define SIZE 50
//Fonksiyon ön tanýmlamalarý:
void denklemAl(double[], int);
void aralikAl(double*, double*);
void fonksYaz(double[], int);
double koy(double[], double, int);
double regulaFalsi(int, double[], double, double, double);
//Main Fonksiyonum
int main(){
	double x1, x2, x3, tmp, MISS, dizi[SIZE];
	int degg;
	
	//MENU YAZDÝRMA
	printf("\n\t\t\t\t\t~~YER DEGISTIRME METODU (REGULA-FALSI)~~\n");
	printf("girmek istediginiz fonksiyonun derecesini giriniz.\n");
	scanf("%d",&degg);
	
//Kullanýcýdan denklemin katsayýlarýný alan fonksiyonu çaðýrýyorum.
	denklemAl(dizi, degg);
//kullanýcýya girdiði fonksiyonu gösteren fonksiyonu çaðýrýyorum.
	fonksYaz(dizi, degg);
//kök aramaya baþlayacaðýmýz aralýðý alan fonksiyonu çaðýrýyorum
	aralikAl(&x1, &x2);
//Regula Falsi Metodunu uygulayan fonksiyonu çaðýrýyorum:
	printf("Sapma payini giriniz.\n(NOT:Sapma payini ne kadar kucuk alirsaniz koke o kadar cok yaklasirsiniz.)");
	scanf("%lf",&MISS);
	x3 = regulaFalsi(degg, dizi, x1, x2, MISS);
	printf("\n\t\t\t\tYAKLASIK BULUNAN KOK = %f",x3);
	printf("\nCikis icin bir tusa basiniz...");
	return 0;	
}
//denklemi diziye tanýmlayan fonksiyon
void denklemAl(double dizi[SIZE], int degg){
int i;
	for(i = degg ; i >= 0 ; i--){
		if(i>0){
			printf("%d. dereceli terimin katsayisini giriniz.\n", i);
			scanf("%lf",&dizi[i]);
		}
		else{
			printf("Sabit terimi giriniz.\n");
			scanf("%lf",&dizi[i]);
		}	
	}
}
//kökü arayacaðýmýz aralýðý input alan fonksiyon
void aralikAl(double* x1, double* x2){
	printf("\nKok aralik baslangici giriniz:");
	scanf("%lf",x1);
	printf("\nKok aralik bitisi giriniz:");
	scanf("%lf",x2);
}

void fonksYaz(double dizi[], int degg){
int i;
	printf("Fonksiyonunuz: \t");
	for(i = degg; i>=2 ;i--){
		if(dizi[i]==(int)dizi[i]){
			printf("%dx^%d",(int)dizi[i],i);
		}
		else{
			printf("%lfx^%d",dizi[i],i);
		}
		while(i>2&&dizi[i-1]==0){
			i--;
		}
		if(i>2&&dizi[i-1]>0){
			printf("+");
		}
	}
	if(dizi[1]>0){
			printf("+");
	}
	if(dizi[1]!=0 && dizi[1] == (int)dizi[1]){
		printf("%dx",(int)dizi[1]);
	}
	else if(dizi[1] != 0){
		printf("%lfx",dizi[1]);
	}
	if(dizi[0]>0){
			printf("+");
	}
	if(dizi[0]!=0&&dizi[0]==(int)dizi[0]){
		printf("%d",(int)dizi[0]);
	}
	else if(dizi[0]!=0){
		printf("%lf",dizi[0]);
	}
}

double koy(double dizi[], double x, int degg){
	int i,j;
	double dizipow[SIZE], tmp, fx;
		/*Sayiyi fonksiyona koyan blok.*/
		for(i = degg ; i >= 0 ; i--){
			tmp=1;
			for(j = i ; j >= 1 ; j--){
				tmp*=x;
			}
			tmp *= dizi[i];
			dizipow[i] = tmp;
		}
		tmp = 0;
		for(i = degg; i >= 0 ;i--){
			tmp += dizipow[i];	
		}
		fx = tmp;
		return fx;
}

double regulaFalsi(int degg, double dizi[SIZE], double x1, double x2, double MISS){
	double x3, dx, fx1=1,fx2=1,fx3=1;
	int sayac = 1;
	do{
		fx1 = koy(dizi,x1,degg);
		fx2 = koy(dizi,x2,degg);
		printf("\t\t\t\tf(%f)=%f\tf(%f)=%f",x1,fx1,x2,fx2);
		x3 = ((x1 * fx2)-(x2 * fx1))/(fx2 - fx1);
		fx3 = koy(dizi,x3,degg);
		printf("\n\t\t\t\tMetod uygulaniyor...\n\t\t\t\t(%d. iterasyon) sonucu:f(%.15f) = %.15f\n\n" ,sayac,x3,fx3);	
		sayac++;
		sleep(1);
		if(fx1*fx3 <= 0){
			x2 = x3;
		}
		else if(fx2*fx3 <= 0){
			x1 = x3;
		}
		dx = fx3;
		if(dx < 0){
			dx*=-1;
		}
	}while(dx > MISS);
	return x3;
}
