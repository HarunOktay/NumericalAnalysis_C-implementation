#include <stdio.h>
#include <stdlib.h>
#define SIZE 50
double koy(double[],double ,int);
void denklemAl(double[], int);
void fonksYaz(double[], int);
void integralAralikParca(double*, double*, double*);

int main() {
	int degg, i, j;
	double dx=1,x1=1,x2=1,dizi[SIZE],total=0,h;
//MENU YAZDÝRMA VE INPUT ALMA
	printf("\n\t\t\t\t~~YAMUK METODU(TRAPEZOIDAL METHOD)~~\n");
	
//Denklemi diziye tanimlayan blok:
	printf("Denklem kacinci dereceden?\n");
	scanf("%d",&degg);
//FONKSÝYONLARI ÇAÐIRIYORUM.
denklemAl(dizi, degg);
fonksYaz(dizi, degg);
integralAralikParca(&x1, &x2, &dx);
//TRAPEZ YONTEMI UYGULANAN KISIM
	h=(x2-x1)/dx;
	for(i=1 ; i < dx ; i++){
		total += 2*koy(dizi, x1+i*h, degg);
	}
	total+=(koy(dizi, x1, degg)+koy(dizi, x2, degg));	
	total=total*h/2;
	printf("\n\nIntegral sonucunuz: %.15f",total);
return 0;
}

double koy(double dizi[],double x,int degg){
	int i,j;
	double dizipow[100],tmp,fx;
	/*Sayiyi fonksiyona koyan blok.*/
		for(i=degg;i>=0;i--){
			tmp=1;
			for(j=i;j>=1;j--){
				tmp*=x;
			}
			tmp*=dizi[i];
			dizipow[i]=tmp;
		}
		tmp=0;
		for(i=degg;i>=0;i--){
			tmp+=dizipow[i];	
		}
		fx=tmp;
		return fx;
}

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
// INTEGRAL ALINACAK ARALIGI VE PARCA SAYISINI ALAN FONKSÝYON 
void integralAralikParca(double* x1, double* x2, double* dx){
	printf("\n\nIntegral alt araligi giriniz.\n");
	scanf("%lf",x1);
	printf("\nIntegral ust araligi giriniz.\n");
	scanf("%lf",x2);
	printf("\nIntegral kac parcaya bolunsun?(Ne kadar yuksek girerseniz o kadar dogru calisir)\n");
	scanf("%lf",dx);
}


