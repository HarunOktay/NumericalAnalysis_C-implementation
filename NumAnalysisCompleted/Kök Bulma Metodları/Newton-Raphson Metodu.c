#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>
#define SIZE 50
//Fonksiyon ön tanýmlamalarý:
void denklemAl(double[], int);
void fonksYaz(double[], int);
void tahminAl(double*);
double turevAl(double[], double , int, double);
double koy(double[], double, int);
double newtonRaphson(int, double[], double, double*, double);
//main fonksiyonum:
int main(){
	int degg;
	double x, result, tmp, dizi[SIZE], yanlislik, MISS;
	//MENU YAZDÝRMA VE INPUT ALMA
	printf("\n\t\t\t\t\t~~NEWTON-RAPHSON METODU~~\n");
	printf("girmek istediginiz fonksiyonun derecesini giriniz.\n");
	scanf("%d",&degg);
	
//Kullanýcýdan denklemin katsayýlarýný alan fonksiyonu çaðýrýyorum.
	denklemAl(dizi, degg);
//kullanýcýya girdiði fonksiyonu gösteren fonksiyonu çaðýrýyorum.
	fonksYaz(dizi, degg);
//kök aramaya baþlayacaðýmýz aralýðý alan fonksiyonu çaðýrýyorum
	tahminAl(&x);
	printf("Sapma payini giriniz.\n(NOT:Sapma payini ne kadar kucuk alirsaniz koke o kadar cok yaklasirsiniz.)");
	scanf("%lf",&MISS);
	
//Newton Metodunu uygulayan fonksiyonu çaðýrýyorum:
	yanlislik = newtonRaphson(degg, dizi, x, &result, MISS);
	printf("\n\t\t\t\t%.15f HATA ILE, BULUNAN YAKLASIK KOK = %.10f",yanlislik ,result);
	return 0;	
}//denklemi diziye tanýmlayan fonksiyon
void denklemAl(double dizi[SIZE], int degg){
int i;
	for(i = degg ; i >= 0 ; i--){
		if(i > 0){
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
void tahminAl(double* x){
	printf("\nTahmini kok arama noktasi giriniz:");
	scanf("%lf",x);
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
	double dizipow[SIZE],tmp,fx;
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
		for(i=degg;i>=0;i--){
			tmp += dizipow[i];	
		}
		fx = tmp;
		
		return fx;
}
double newtonRaphson(int degg, double dizi[SIZE], double x, double* result, double MISS){
	double tmpx, hata, fx = 1, dfx = 1;
	tmpx = x;
	int sayac = 1;
	do{
		x = tmpx;
		fx = koy(dizi, x, degg);
		dfx = turevAl(dizi, x, degg, MISS);
		tmpx = x - (fx/dfx);
		hata = fabs(x-tmpx);
		printf("\n\t\t\t\t%d. deneme sonucu:",sayac);
		sayac++;
		sleep(1);
		printf("\n\t\t\t\tx2=x1-f(x)/f'(x)\tx=%lf-(%lf/%lf)\t=x=%lf\n",x,fx,dfx,tmpx);
	}while(hata > MISS);
	*result = tmpx;
	return hata;
}
double turevAl(double dizi[SIZE], double x, int degg, double MISS){
	double turev;
	turev = (koy(dizi, x + MISS, degg)- koy(dizi, x, degg))/MISS;
	return turev;
}
