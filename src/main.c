/* Tarefa de decifrar uma cifra
 Fernanda Esteves Coelho Chaves RA:215835
 */

#include <stdio.h>

#define TAM_BUFFER 60
char buffer_entrada[TAM_BUFFER];
char buffer_saida[TAM_BUFFER];


const char senha[] = "SENHASECRETA";

char decifrador(char a, char b){
	char a1, b1, c1;
	if (a>='A' && a<='Z') {
    	a1 = a -'A';
    	b1 = b -'A';
    	c1 = 'A'+ (a1-b1+ ('Z'-'A'+1)) % ('Z'-'A'+1);
    	return c1;
  	} else return a;

}




int main() {

 int j=0;
  int i=0;

  /* Leitura da entrada */
  fgets(buffer_entrada, TAM_BUFFER, stdin);


  for (i=0; (i<TAM_BUFFER) && (buffer_entrada[i]!='\0') && (buffer_entrada[i]!='\n'); i++) {

    buffer_saida[i] = decifrador(buffer_entrada[i], senha[j]);
    j++;
    if (senha[j]=='\0') j=0;
  }
  buffer_saida[i]='\0';



  /* Escrever saida na tela */
  printf("%s\n", buffer_saida);

  return 0;
}
