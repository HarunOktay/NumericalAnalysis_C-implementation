#include <stdio.h>
#include <math.h>
#include <windows.h>
#define SIZE 10
int main(){
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
return 0;
}
