#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>
#define SIZE 50
//Fonksiyon ön tanýmlamalarý:
void denklemAl(double[], int);
void fonksYaz(double[], int);
double turevAl(double[], double , double, int);
double geriTurev(double[], double, double, int );
double merkeziTurev(double[], double, double, int );
double koy(double[], double, int);

int main(){
	double x, result, tmp, h_Turev, dizi[SIZE];
	int degg, secim, exitt = 1;
	
//MENU YAZDÝRMA VE INPUT ALMA
	printf("\n\t\t\t\t~~ILERI-GERI-MERKEZI SAYISAL TUREV~~");
	printf("\ngirmek istediginiz fonksiyonun derecesini giriniz.\n");
	scanf("%d",&degg);
//DENKLEM ALIP YAZDIRAN FONKSIYONLARI CAGIRIYORUM:	
	denklemAl(dizi, degg);
	fonksYaz(dizi, degg);
	
	printf("\nTurevini bulmak istediginiz X degerini giriniz.");
	scanf("%lf",&x);
	printf("h degerini giriniz.\n(NOT:h degerini ne kadar kucuk alirsaniz koke o kadar cok yaklasirsiniz.):");
	scanf("%lf",&h_Turev);
	
	while(exitt == 1){
	printf("\n\t1)ILERI FARKLAR ILE\n\t2)GERI FARKLAR ILE\n\t3)MERKEZI FARKLAR ILE\n\tHANGI YONTEM ILE SAYISAL TUREV ALMAK ISTIYORSUNUZ:");
	scanf("%d",&secim);
	switch(secim){
		case 1:
			printf("\n\t\tILERI FARKLAR YONTEMIYLE TUREV SONUCUNUZ:");
			result = turevAl(dizi, x, h_Turev, degg);
			printf("%lf",result);
			break;
		case 2:
			printf("\n\t\tGERI FARKLAR YONTEMIYLE TUREV SONUCUNUZ:");
			result = geriTurev(dizi, x, h_Turev, degg);
			printf("%lf",result);
			break;
		case 3:
			printf("\n\t\tMERKEZI FARKLAR YONTEMIYLE TUREV SONUCUNUZ:");
			result = merkeziTurev(dizi, x, h_Turev, degg);
			printf("%f",result);
			break;
		}
		printf("\n\nCikmak istiyorsaniz 0 giriniz. baska yontemle turev almak istiyorsaniz 1 giriniz.");
		scanf("%d",&exitt);
	}
	return 0;
}

//KULLANICIDAN DENKLEM ALIP BÝR DÝZÝYE KAYDEDEN FONKSÝYON:
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
//ALINAN DENKLEMI YAZDIRAN FONKSIYON:
void fonksYaz(double dizi[], int degg){
int i;
	printf("Fonksiyonunuz: \t");
	for(i = degg ; i >= 2 ;i--){
		if(dizi[i] == (int)dizi[i]){
			printf("%dx^%d",(int)dizi[i],i);
		}
		else{
			printf("%lfx^%d",dizi[i], i);
		}
// EGER DENKLEMDE KATSAYILAR 0 OLURSA i SAYISINI AZALTARAK 0LI TERIMLERI GEREKSIZ YAZDIRMIYORUM.
		while(i > 2 && dizi[i-1] == 0){
			i--;
		}
		if(i > 2 && dizi[i-1] > 0){
			printf("+");
		}
	}
	if(dizi[1] > 0){
			printf("+");
	}
	if(dizi[1] != 0 && dizi[1] == (int)dizi[1]){
		printf("%dx",(int)dizi[1]);
	}
	else if(dizi[1] != 0){
		printf("%lfx",dizi[1]);
	}
	if(dizi[0] > 0){
			printf("+");
	}
	if(dizi[0] != 0 && dizi[0] == (int)dizi[0]){
		printf("%d",(int)dizi[0]);
	}
	else if(dizi[0] != 0){
		printf("%lf",dizi[0]);
	}
}
//DEGERLERI DENKLEME KOYAN FONKSIYON:
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
		for(i=degg;i>=0;i--){
			tmp += dizipow[i];	
		}
		fx = tmp;
		return fx;
}
//ILERI FARKLA TUREV ALAN FONKSIYON:
double turevAl(double dizi[SIZE], double x, double h_Turev, int degg){
	double turev;
	turev = (koy(dizi, x + h_Turev, degg)- koy(dizi, x, degg))/h_Turev;
	return turev;
}
//GERI FARKLA TUREV ALAN FONKSIYON:
double geriTurev(double dizi[SIZE], double x, double h_Turev, int degg){
	double turev;
	turev = (koy(dizi, x, degg)-koy(dizi, x - h_Turev, degg))/h_Turev;
	return turev;
}
//MERKEZI FARKLA TUREV ALAN FONKSIYON:
double merkeziTurev(double dizi[SIZE], double x, double h_Turev, int degg){
	double turev;
	double ileri, geri;
	turev = (koy(dizi, x + h_Turev, degg) - koy(dizi, x - h_Turev, degg))/(2*h_Turev);
	return turev;
}
