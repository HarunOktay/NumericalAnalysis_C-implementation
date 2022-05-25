#include <stdio.h>
#include <math.h>
#define SIZE 50
int main(){	
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
	return 0;
}
