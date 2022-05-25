#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>
#define SIZE 50
void bisectionMethod();
void regulaFalsiMethod();
void newtonRaphsonMethod();
void inverseMatrix();
void gaussElimination();
void gaussSeidalMethod();
void trapezoidal();
void simpson();
void gregoryNewton();
void sayisalTurev();
void denklemAl(double[], int);
void fonksYaz(double[], int);
void aralikAl(double*, double*);
void integralAralikParca(double*, double*, double*);
double koy(double[], double, int);
void tahminAl(double*);
double turevAl(double[], double , int, double);
double ileriTurev (double[], double, double, int);
double geriTurev(double[], double, double, int );
double merkeziTurev(double[], double, double, int ) ;
double bisection(int, double[], double, double, double);
double regulaFalsi(int, double[], double, double, double);
double newtonRaphson(int, double[], double, double*, double);
void matrisYaz(double[][2*SIZE], int);
void matrisInverse(double[][2*SIZE], double[][2*SIZE],int );
double gaussSeidal(double [][SIZE],double[], int , int ,double*);
double ucSekiz(double[],double, double, double, int, double);
double birUc(double[],double, double, double, int, double);
int main(){
int metod, cikis = 1;
	while(cikis = 1){
			
		printf("\n\n\n\nSAYISAL ANALIZ DONEM PROJESI\n\n");
		printf("\n\t\t\t\t~~1)IKIYE BOLME METODU (BISECTION)~~\n");
		printf("\n\t\t\t\t~~2)YER DEGISTIRME METODU (REGULA-FALSI)~~\n");
		printf("\n\t\t\t\t~~3)NEWTON-RAPHSON METODU~~\n");
		printf("\n\t\t\t\t~~4)TERS MATRIS(INVERSE Matris)~~\n");
		printf("\n\t\t\t\t~~5)GAUSS-ELIMINASYON METODU~~\n");
		printf("\n\t\t\t\t~~6)GAUSS-SEIDAL METODU~~\n");
		printf("\n\t\t\t\t~~7)YAMUK METODU(TRAPEZOIDAL METHOD)~~\n");
		printf("\n\t\t\t\t~~8)SIMPSON METODU ILE INTEGRAL HESAPLAMA~~\n");
		printf("\n\t\t\t\t~~9)GREGORY-NEWTON ENTERPOLASYONU~~\n");
		printf("\n\t\t\t\t~~10)ILERI-GERI-MERKEZI SAYISAL TUREV~~\n");
		printf("\n\t\t\t\t~~0) -cikis\n\n\n");
		printf("lutfen menuden bir secim yapiniz : ");
		scanf("%d", &metod);
		system("cls");
		
		switch(metod){
			case 1:
				bisectionMethod();
				break;
			case 2:
				regulaFalsiMethod();
				break;
			case 3:
				newtonRaphsonMethod();
				break;
			case 4:
				inverseMatrix();
				break;
			case 5:
				gaussElimination();
				break;
			case 6:
				gaussSeidalMethod();
				break;
			case 7:
				trapezoidal();
				break;
			case 8:
				simpson();
				break;
			case 9:
				gregoryNewton();
				break;
			case 10:
				sayisalTurev();
				break;	
		
			case 0:
				cikis = 0;
				break;	
			default:
				printf("\n\thatali secim lutfen bir daha deneyin\n");
				break;	
			
		}
	}
}

void bisectionMethod(){
	double MISS, x1, x2, x3, tmp, dizi[SIZE];
	int degg;
//MENU YAZDÝRMA VE INPUT ALMA
	printf("\n\t\t\t\t\t~~IKIYE BOLME METODU (BISECTION)~~\n");
	printf("girmek istediginiz fonksiyonun derecesini giriniz.\n");
	scanf("%d",&degg);

//Kullanýcýdan denklemin katsayýlarýný alan fonksiyonu çaðýrýyorum.
	denklemAl(dizi, degg);
//kullanýcýya girdiði fonksiyonu gösteren fonksiyonu çaðýrýyorum.
	fonksYaz(dizi, degg);
//kök aramaya baþlayacaðýmýz aralýðý alan fonksiyonu çaðýrýyorum
	aralikAl(&x1, &x2);
	
	printf("Sapma payini giriniz.\n(NOT:Sapma payini ne kadar kucuk alirsaniz koke o kadar cok yaklasirsiniz.)");
	scanf("%lf",&MISS);
//Bisection fonksiyonunu çaðýrýyorum.	
		x3 = bisection(degg, dizi, x1, x2, MISS);
		printf("\n\t\t\t\tYAKLASIK BULUNAN KOK = %.15f",x3);
		sleep(5);
}

void regulaFalsiMethod(){
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
	printf("\n\t\t\t\tYAKLASIK BULUNAN KOK = %.15f",x3);
	sleep(5);
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
//Fonksiyonu yazdiran fonksiyon
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
		if(dizi[1]!=0 && dizi[1] == (int)dizi[1]){
			printf("%dx",(int)dizi[1]);
		}
		else if(dizi[1] != 0){
			printf("%lfx",dizi[1]);
		}
		if(dizi[0]>0){
				printf("+");
		}
		if(dizi[0]!=0 && dizi[0] == (int)dizi[0]){
			printf("%d",(int)dizi[0]);
		}
		else if(dizi[0]!=0){
			printf("%lf",dizi[0]);
		}
}
//kökü arayacaðýmýz aralýðý input alan fonksiyon
void aralikAl(double* x1, double* x2){
	printf("\nKok aralik baslangici giriniz:");
	scanf("%lf",x1);
	printf("\nKok aralik bitisi giriniz:");
	scanf("%lf",x2);
}
//DEGERLERI DENKLEMIN ICINE KOYUP DEGER BULAN FONKSIYON
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

double bisection(int degg, double dizi[SIZE], double x1, double x2, double MISS){
	double x3, dx, fx1=1,fx2=1,fx3=1;
	int sayac = 1;
	do{
		fx1 = koy(dizi,x1,degg);
		fx2 = koy(dizi,x2,degg);
		printf("\t\t\t\tf(%f)=%f\tf(%f)=%f",x1,fx1,x2,fx2);
		x3 = (x1+x2)/2;
		fx3 = koy(dizi,x3,degg);
		printf("\n\t\t\t\tMetod uygulaniyor...\n\t\t\t\t(%d. iterasyon) sonucu:f(%f) = %.16f\n\n" ,sayac,x3,fx3);
		sleep(1);
		sayac++;		
		if(fx1*fx3 <= 0){
			x2=x3;
		}
		else if(fx2*fx3<=0){
			x1 = x3;
		}
		dx = fx3;
		if(dx < 0){
			dx*=-1;
		}
	}while(dx > MISS);
	return x3;
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
void newtonRaphsonMethod(){
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
	printf("\n\t\t\t\t%.15f HATA ILE, BULUNAN YAKLASIK KOK = %.15f",yanlislik ,result);
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
//kökü arayacaðýmýz aralýðý input alan fonksiyon
void tahminAl(double* x){
	printf("\nTahmini kok arama noktasi giriniz:");
	scanf("%lf",x);
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
void inverseMatrix() {
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
	sleep(5);
}
void gaussElimination(){
//DEÐÝÞKEN TANIMLAMASI VE MENU KISMI
	float matrix[SIZE][SIZE], coz_matrix[SIZE];
	int N, exit = 0;
	int i, j, k;
	printf("\n\t\t\t\t~~GAUSS-ELIMINASYON METODU~~\n");
	printf("gireceginiz denklemin bilinmeyen sayisi:\n");
	scanf("%d", &N);
//EXIT DEGÝÞKENÝ ÝLE EÐER KULLANICI KÖÞEGENLERÝNDE 0 OLAN DEÐER GÝRERSE, UYARIP YENÝDEN ÝNPUT GÝRMESÝNÝ SAÐLIYORUM.
	do
	{ 
		exit = 0;
		for(i = 0 ; i < N ; i++){
			printf("%d. denklemin degisken katsayilarini giriniz : \n",i+1);
			for(j = 0 ; j < N ; j++){
				printf("Matris[%d][%d] degerini giriniz.",i+1,j+1);
				scanf("%f", &matrix[i][j]);		
			}
			if(matrix[i][i] == 0){
				exit = 1;
			}
		}
		if(exit == 0){
			printf("\nSonuc vektorunu giriniz\n\n");
			for(i=0;i<N;i++){
				printf("c%d:",i+1);
				scanf("%f", &coz_matrix[i]);
			}
			for(i=0 ; i < N ; i++){
				printf("|");
					for(j=0 ; j < N ; j++){
						printf(" %f ",matrix[i][j]);
					}
			printf("/ %f |\n",coz_matrix[i]);
			}
			sleep(1);
			printf("denklem cozuluyor...");
			sleep(1);
//GAUSS ELÝMÝNASYON YÖNTEMÝYLE ÇÖZÜM
			for(i=0;i<N;i++){
				for(k=0 ; k<N ; k++){
				    if(k != i){
					    matrix [i][k] /= matrix[i][i];   
					}
				}
				coz_matrix[i] /= matrix[i][i];
				matrix [i][i] = 1;
				for(j = 0 ; j < N ; j++){
					if(j != i){
						for(k = 0 ; k < N ; k++){
							if(k != i){
								matrix[j][k] -= matrix[j][i] * matrix[i][k];
							}
						}
						coz_matrix[j] -= matrix[j][i]*coz_matrix[i];
						matrix[j][i] = 0;
					}
				}
			}
			printf("\nDenklem cozum kumesi:\n");
			for(i=0 ; i<N ; i++){
					printf("x%d = %.15f\n", i+1, coz_matrix[i]);
			}
		}else{
			printf("MATH ERROR:\nMATRISIN KATSAYILARININ YERLERINI DEGISTIRIP TEKRAR DENEYINIZ\n(matris kosegen elemanlari 0'dan farkli olmali)!\n");	
			sleep(2);
			system("cls");
		}
	}while(exit == 1);
	sleep(5);
}

void trapezoidal() {
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
void simpson(){
	int degg, secim, exitt = 1, i, j;
	double dx=1,x1=1,x2=1,dizi[SIZE],total=0,h;
//MENU YAZDÝRMA VE INPUT ALMA
	printf("\n\t\t\t\t~~SIMPSON METODU ILE INTEGRAL HESAPLAMA~~\n");
	printf("Denklem kacinci dereceden?\n");
	scanf("%d",&degg);
//FONKSÝYONLARI ÇAÐIRIYORUM.
denklemAl(dizi, degg);
fonksYaz(dizi, degg);
integralAralikParca(&x1, &x2, &dx);
	
/*Simpson yontemi*/
	h = (x2 - x1)/dx;
	while(exitt == 1){
		printf("\n\t1)SIMPSON 1/3 METODU ILE\n\t2)SIMPSON 3/8 METODU ILE\n\tHANGI YONTEM ILE INTEGRAL ALMAK ISTIYORSUNUZ:");
		scanf("%d",&secim);
		switch(secim){
		case 1:
			total = birUc(dizi, x1, x2, h, degg, dx);	
			break;
		case 2:
			total = ucSekiz(dizi, x1, x2, h, degg, dx);
			break;
		}
		printf("\n\nIntegral sonucunuz: %f",total);
		printf("\n\nCikmak istiyorsaniz 0 giriniz. baska yontemle ayni degerin integralini almak istiyorsaniz 1 giriniz.");
		scanf("%d",&exitt);
	}
}
	double ucSekiz(double dizi[],double x1, double x2, double h, int degg, double dx){
		int i;
		double total;
		for(i=1 ; i < dx ; i++){
			if(i%3 == 1){
				total+=2*koy(dizi, x1+i*h, degg);
			}
			else{
				total+=3*koy(dizi, x1+i*h, degg);
			}
		}
		total += (koy(dizi, x1, degg)+koy(dizi, x2, degg));	
		total = (3*total*h)/8;
		return total;
		}
		double birUc(double dizi[],double x1, double x2, double h, int degg, double dx){
		int i;
		double total;
			for(i=1 ; i<dx ; i++){
			if(i%2 == 1){
				total+=4*koy(dizi, x1+i*h, degg);
			}
			else{
				total+=2*koy(dizi, x1+i*h, degg);
			}
		}
		total += (koy(dizi, x1, degg)+koy(dizi, x2, degg));	
		total = total*h/3;
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
void gaussSeidalMethod() {
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
}
void gregoryNewton(){	
//ön tanýmlamalar:
	double ax[SIZE], ay[SIZE][SIZE] = {0};
	double x, h, payda, factt, tmp;
	double sonuc;
	int n, diff, count, flag = 1;
	int i, j;
	
//MENU YAZDÝRMA ve INPUT ALMA
	printf("\n\t\t\t\t~~GREGORY-NEWTON ENTERPOLASYONU~~\n");
	printf("Gireceginiz X veri sayisini giriniz.: ");
	scanf("%d", &n);
	printf("Gireceginiz ilk X degerini giriniz: ");
	scanf("%lf", &ax[0]);
	printf("X degerleri arasindaki fark (h) : ");
	scanf("%lf", &h);
	
//X DEGERLERÝNÝ TUTAN DÝZÝYÝ DOLDURUYORUM 
	for(i=1;i<n;i++){
		ax[i] = ax[i-1] + h;
	}
	for(i=0;i<n;i++){
		printf("f(%.1f) Y degeri giriniz giriniz : ",ax[i]);
		scanf("%lf", &ay[i][0]);
	}
	printf("bulmak istediginiz X degeri giriniz : ");
	scanf("%lf", &x);
	diff = 1;
//SONLU FARKLAR OlUSTURAN BLOK
	while(flag == 1 && diff < n){
		for(i=0 ; i < n-1 ; i++){
			ay[i][diff] = ay[i+1][diff-1] - ay[i][diff-1];
		}
		i = 0;
		flag = 0;
		while(i < n-diff-2 && flag == 0){
			if( (ay[i][diff]) != (ay[i+1][diff]) ){
				flag = 1;
			}
			i++;	
		}
		diff++;
	}
//SONLU FARKLAR TABLOSUNU YAZDIRAN BLOK
	printf("\n");
	for(i = 0 ; i < n ; i++){
		j = 0;
		while(j < n-i && j < diff){
			printf("%8.2f | ",ay[i][j]);
			j++;
		}
		printf("\n");
	}
// ENTERPOLASYONU FORMULE DOKUP CALISTIRAN BLOK
	sonuc = 0;
	factt = 1;
	for(i = 0 ; i < diff ; i++){
		if(i!=0){ 
			factt *= i;
		}
		tmp = 1;
		for(j = 0 ; j < i ; j++){
			tmp *= (x-ax[j]);
		}
		sonuc += (ay[0][i] * tmp) / (pow(h,i)*factt);
	}
	printf("\n\nsonuc = %.15f\n", sonuc);
}
void sayisalTurev(){
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
			result = ileriTurev(dizi, x, h_Turev, degg);
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
double ileriTurev (double dizi[SIZE], double x, double h_Turev, int degg){
	double turev;
	turev = (koy(dizi, x + h_Turev, degg)- koy(dizi, x, degg))/h_Turev;
	return turev;
}







