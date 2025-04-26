#include <stdio.h>
#define linhas 10
#define colunas 10

    int main(){
                
        char letras[] = {'A', 'B', 'C', 'D', 'F', 'G', 'H', 'I', 'J', 'K'};
        int matriz [linhas] [colunas] = {};

        //loops aninhados para posicionar os 3 barcos
        
        //barcos na diagonal        
        for (int j = 0 ; j <= 2; j++){  
            matriz[j][j] = 3;  
        }

        for(int i = 5; i <= 7; i++){
            for(int j = 7 - i; j <= 7 - i; j++){
                matriz[i][j] = 3;
            }
        }


        //barco na horizontal
        for(int i = 5; i <= 5; i++){ // O sinal de "=" faz toda diferença ou igualar ele a um número a mais por exemplo 5(daria o mesmo resultado), pois eu posso escolher qualquer linha e igualar para o loop não geral nenhuma outra linha 
          for(int j = 7; j <= 9; j++){// Esse loop faz com que o númeo 3 gere deitado na linha 4 por conta do ultimo código que eu fiz igualando o número a 4
            matriz[i][j] = 3;
          }
        }


        //barco na vertical
        for(int i = 1; i <= 3; i++){// Mesmo racíoninio do último for PORÉM o 3 vai ser adicionado verticalmente por conta que o "I" imprime só linhas em pé e não colunas deitadas igual o "J"
            for(int j = 9; j <= 9; j++){//Selecionei a coluna 2 "C" e igualei no loop para n gerar mais nehuma outra fileira e deixar só uma.
               matriz[i][j] = 3;
            }
        }

        //Bloco de código que irá imprimir o cone
        for(int i = 0; i <= 2; i++){
            for(int j = 2 - i; j <= 2 + i; j++){
                if(matriz[i][j] == 3){
                   matriz[i][j] = 5;
                }else{
                matriz[i][j] = 1;
            }
        }
    }

        //Bloco de código que irá imprimir a cruz
        for(int i = 3; i <= 7; i++){
            for(int j = 4; j <= 4; j++){
                if(i == 5){ // Igualei o I a 5, pois quando chegar na linh 5 o IF irá adicionar mais casas a essa coluna
                    for(int j = 2; j <= 6; j++){
                    if(matriz[i][j] == 3){ //Linha de correção caso há contado com algum navio nas linhas
                        matriz[i][j] = 5;
                    }else{
                        matriz[i][j] = 2;
                    }
               }
            }
            if(matriz[i][j] == 3){ //Linha de correção caso há contado com algum navio nas colunas
                matriz[i][j] = 5;
            }else{
                matriz[i][j] = 2;
            }
        }
    }
      //Bloco de código que vai imprimir o octógono 
      
      for (int i = 0; i <= 2; i++) {
        for (int j = 7 - i; j <= 7 + i; j++) {
            if (i == 2) {
                // Loop interno com variáveis diferentes para evitar conflito
                for (int k = 4; k >= 3; k--) { 
                    for (int l = 3 + k; l <= 11 - k; l++) { 
                        if (matriz[k][l] == 3) {
                            matriz[k][l] = 5;
                        } else {
                            matriz[k][l] = 4;
                        }
                    }
                }
            }
            // Verifica e altera o valor na matriz
            if (matriz[i][j] == 3) {
                matriz[i][j] = 5;
            } else {
                matriz[i][j] = 4;
            }
        }
    }

        printf(" TABULEIRO BATALHA NAVAL\n");
        printf("   ");
        for(int i = 0; i <= 9; i++){
        printf("%c ", letras[i]); // Imprime letras das colunas
    }
        printf("\n");
        for(int i = 0; i <= 9; i++){
        printf("%2d ", i + 1);  //Imprime as linhas de 1 até 10 
        for(int j = 0; j <= 9; j++){ // Imprime o número 0 da tabela representando a água
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}