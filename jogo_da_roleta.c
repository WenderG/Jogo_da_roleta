#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

int main(void){
    srand(time(NULL));
    int tentativas, numero, numeroSorteado, numeroEscolhido, i, tempo = 1000; 
    bool marcador = true;
    char decisao;

    tentativas = 0;
    printf("------BEM-VINDOS!------");
    Sleep(2000);

    do{
        system("cls");
        if(tempo > 0){
            tempo = tempo;
        }else{
            tempo = 0;
        }
        printf("Voce tentara acertar o numero (S/N)?\n");
        printf("Tempo %d\n", tempo);
        scanf("%c", &decisao);
        switch(decisao){
            case 's':
                tentativas++;
                printf("Vamos começar!\n");
                Sleep(1500);
                numeroSorteado = rand() % 10;
                system("cls");
                Sleep(1500);
                while(!kbhit()){
                    printf("tentativa %d\n", tentativas);
                    printf("Acerte o numero %d\n", numeroSorteado);
                    numero = rand() % 10;
                    printf("%d\n", numero);
                    printf("Aperte ENTER para parar");
                    Sleep(tempo);
                    system("cls"); 
                }

                numeroEscolhido = numero;

                if(numeroEscolhido == numeroSorteado){
		            tempo = tempo - 50;
                    printf("tentativa %d\n", tentativas);
                    printf("Parabens!\n");
                    Sleep(2000);
                    break;
                }else {
		            tempo = 1000;
                    printf("tentativa %d\n", tentativas);
                    printf("Tente de novo!\n");
                    Sleep(2000);
                    break;
                }
            case 'n':
                system("cls");
                printf("Que pena...");
                Sleep(1000);
                system("cls");
                printf("Quantidade de tentativas: %d", tentativas);
                Sleep(2000);
                system("cls");
                printf("Ate a proxima!\n");
                marcador = false;
        }
    }while(marcador == true);

    return 0;
}