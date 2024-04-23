/*
 * AndreNascimentoInfo2ParaCasa.c
 *
 *  Created on: 26 de fev. de 2024
 *      Author: user
 */
/*Alisson, tentei de todas as formas procurar a palavra João no arquivo, porém aparentemente não está identificando, por conta do til no a, e eu não sei o que fazer,
 * já tentei de tudo e não funciona, nem mesmo com o locale. Qualquer outra palavra o programa consegue encontrar.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int exa (){
	char palavra[50];
	char c[10000];
	int j = 0;

	FILE * f;

	f = fopen("FaroesteCaboclo.txt","r");

	if (f != NULL){
		printf("Digite a palavra que deseja procurar:\n");
		gets(palavra);

		while((fgets(c, sizeof(c), f)) != NULL){
			if(strstr(strupr(c), strupr(palavra)) != NULL){
				j++;
			}
		}

	}else{
		printf("Impossível abrir o arquivo.");

		return 1;
	}

	printf("%d",j);

	fclose(f);

	return 0;
}
char* sp(const char* s, const char* v, const char* n){
	char* resultado;
	int i, cnt = 0;
	int nt = strlen(n);
	int vt = strlen(v);

	for(i = 0; s[i] != '\0'; i++){
		if(strstr(&s[i], v) == &s[i]){
			cnt++;

			i += vt - 1;
		}
	}

	resultado = (char*)malloc(i + cnt * (nt - vt) + 1);

	i = 0;
	while(*s){
		if(strstr(s, v) == s){
			strcpy(&resultado[i], n);
			i += nt;
			s += vt;
		}else{
			resultado[i++] = *s++;
		}
	}

	resultado[i] = '\0';
	return resultado;
}
int exb(){
	char ps[50];
	char pn[50];
	char c;
	char cc;
	int i = 0;
	int j = 0;
	char* resultado = NULL;

	FILE * f;

	f = fopen("FaroesteCaboclo.txt","r");

	FILE * s;

	s = fopen("FaroesteCaboclo2.txt", "w");

	if ((f != NULL) && (s != NULL)){
		printf("\nDigite a palavra que deseja substituir:\n");
		scanf("%s", ps);

		printf("Digite a nova palavra:\n");
		scanf("%s", pn);

		while((c = fgetc(f)) != EOF){
			i++;
		}

		char ar[i];

		fseek(f, 0, SEEK_SET);

		while((cc = fgetc(f)) != EOF){
			for(j = 0; j < i; j++){

				ar[j] = cc;
				cc = fgetc(f);
			}
		}

		resultado = sp(ar, ps, pn);

		}else{
			printf("Impossível abrir os arquivos.");

			return 1;
		}

	fputs(resultado,s);

	free(resultado);

	fclose(f);
	fclose(s);
	return 0;
}

int main(){
	setbuf(stdout, NULL);
	setlocale(LC_ALL,"Portuguese");

	exa();
	exb();

	return 0;
}
