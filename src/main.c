/* Tarefa de decifrar uma cifra
 Fernanda Esteves Coelho Chaves RA:215835
 */

#include <stdio.h>

#define TAM_BUFFER 60
char buffer_entrada[TAM_BUFFER];
char buffer_saida[TAM_BUFFER];
/*
com o codigo do cifrador, a senha e sabendo que o cifrador eh do tipo Vigenere, a criacao de um decifrador pode ser feita de forma simples
utilizando o proprio codigo do cifrador

Para decifrar o codigo, basta pegar o primeiro alfabeto da mensagem criptografada e a chave gerada, analisar a tabela de cifra Vigenere, onde
a linha correspondente sera o primeiro alfabeto da mensagem original e repetir o mesmo processo para todos os alfabetos na mensagem criptografada.

Este processo esta descrito na funcao DECIFRADOR, principamente na linha 26 	
*/	
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
