/*
 * AndreNascimentoInfo2_05_03.c
 *
 *  Created on: 5 de mar. de 2024
 *      Author: user
 */


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void trataArquivo(FILE *file, int i){
	int s = 0;
	char palavra[100];
	int cont = 0;
	char  * token;
	char line[200];

	while(fgets(line,sizeof(line),file)){
			token = strtok(line," .,-;:");
			while(token != NULL){
				if(strlen(token) > s){
					s = strlen(token);
					strcpy(palavra,token);
				}
				if(strlen(token) > i){
					cont++;
				}

				token = strtok(NULL," .,-;:");
			}
	}
	printf("A maior palavra é: ");
	puts(palavra);
	printf("Existem %d palavras maiores que %d chars.\n",cont, i);
}

int main(){
	setbuf(stdout, NULL);
	setlocale(LC_ALL,"Portuguese");

	char nomeAr[30];

	printf("Qual dos testamentos você deseja abrir?\n");
	scanf("%s",nomeAr);

	strcat(nomeAr,".txt");


	FILE *f = fopen(nomeAr,"r");

	if (f == NULL){
		printf("Não foi possível abrir o arquivo.\n");
	}

	trataArquivo(f, 15);

	fclose(f);
	return 0;
}
