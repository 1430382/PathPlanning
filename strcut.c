#include <stdio.h>
#include <stdlib.h>
#define FILA 8
#define COLUMNA 8
struct{
	int space; //variables dentro de nuestra estructura
	int transform;
}typedef mapa;
void imprimeMatriz(mapa matriz[][COLUMNA]);
int main(int argc, char *argv[]) {
	int i,j;
	
	mapa _mapa[FILA][COLUMNA];
	
	for(j=0;j<FILA; j++)
		for(i=0;i<COLUMNA; i++){
			_mapa[j][i].transform=9999;
			if(j==0 || j==FILA-1 || i==0 || i==COLUMNA-1)
				_mapa[j][i].space=1;
			else 
				_mapa[j][i].space=0;
		}
    imprimeMatriz(_mapa);	
    _mapa[4][5].space=1;
    _mapa[4][4].space=1;
	_mapa[5][2].space=1;
	_mapa[5][3].space=1;
	_mapa[5][2].space=1;
	_mapa[5][6].space=1;	
_mapa[3][3].transform=0;	
	int temp, changes=0;
	do{
		changes=0;
	for(j=FILA-2;j>0; j--){
		for(i=1;i<COLUMNA-1; i++){
			if(_mapa[j][i].space==0){
				if(_mapa[j][i-1].space==0){
					temp=_mapa[j][i-1].transform+1;
					if(temp<_mapa[j][i].transform){
						_mapa[j][i].transform=temp;
						changes++;                                                     
					}
				}
				if(_mapa[j+1][i-1].space==0){
					temp=_mapa[j+1][i-1].transform+1;
					if(temp<_mapa[j][i].transform){
						_mapa[j][i].transform=temp;
						changes++;
					}
				}
				if(_mapa[j+1][i].space==0){
					temp=_mapa[j+1][i].transform+1;
					if(temp<_mapa[j][i].transform){
						_mapa[j][i].transform=temp;
						changes++;
					}
				}
				if(_mapa[j+1][i+1].space==0){
				   temp=_mapa[j+1][i+1].transform+1;
					if(temp<_mapa[j][i].transform){
						_mapa[j][i].transform=temp;
						changes++;
					}
				}
			}
		}
	}
    for(j=1;j<FILA-1; j++){
	    for(i=COLUMNA-2; i>0; i--){
			if(_mapa[j][i].space==0){
				if(_mapa[j][i+1].space==0){
					temp=_mapa[j][i+1].transform+1;
					if(temp<_mapa[j][i].transform){
						_mapa[j][i].transform=temp;
						changes++;                                                     
					}
				}
				if(_mapa[j-1][i+1].space==0){
					temp=_mapa[j-1][i+1].transform+1;
					if(temp<_mapa[j][i].transform){
						_mapa[j][i].transform=temp;
						changes++;                                                     
					}
				}
			if(_mapa[j-1][i].space==0){
					temp=_mapa[j-1][i].transform+1;
					if(temp<_mapa[j][i].transform){
						_mapa[j][i].transform=temp;
						changes++;                                                     
					}
				}
				if(_mapa[j-1][i-1].space==0){
					temp=_mapa[j-1][i-1].transform+1;
					if(temp<_mapa[j][i].transform){
						_mapa[j][i].transform=temp;
						changes++;                                                     
					}
				}
			}
		}
      }
    }while (changes>0);
  imprimeMatriz(_mapa);
    system("PAUSE");
	return 0;
}
void imprimeMatriz(mapa matriz[][COLUMNA]){
	int i,j;
	for(j=0;j<FILA; j++){
		for(i=0;i<COLUMNA; i++){
			printf("%d\t",matriz[j][i].space);
		}
		printf("\n");
	}
	printf("\n");
    for(j=0;j<FILA; j++){
		for(i=0;i<COLUMNA; i++){
			printf("%d\t",matriz[j][i].transform);
		}
		printf("\n");
	}
	printf("\n");
}
