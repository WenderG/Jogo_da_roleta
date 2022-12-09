#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

void regras(void){
    system("cls");
    printf("1 - Acerte o numero escolhido aleatoriamente em cada rodada\n2 - Se acertar, o tempo sera deminuido e aumentara sua pontuacao;\n3 - Se errar, sua pontuacao sera reduzida e o tempo voltara para o inicio.\n\n");
    system("pause");
}

void pontuacao(int pontos)
{
    if(pontos < 0)
        pontos = 0;
    else
        pontos += 50;

    printf("Pontos: %d", pontos);
}

void menu(void)
{
    srand(time(NULL));
    int tentativas, numero, numeroSorteado, numeroEscolhido, decisao, aux = 0, tempo = 1000, pontos = 0; 
    bool marcador = true;

    tentativas = 0;

    do{
        system("cls");
        if(tempo < 0){
            tempo = 0;
        }
        printf("----------JOGO DA ADIVINHACAO----------");
        printf("\n\n\n");
        printf("Pontuacao atual: %d", pontos);
        printf("\n\n");
        printf("Menu:\n");
        printf("0 - Sair\n1 - Jogar\n2 - Regras\n\n");
        printf("Decisao: ");
        scanf("%d", &decisao);
        switch(decisao){
            case 0:
                system("cls");
                printf("Que pena...\n");
                printf("Quantidade de tentativas: %d", tentativas);
                printf("\n\n");
                pontuacao(pontos);
                Sleep(2000);
                system("cls");
                printf("Ate a proxima!\n");
                marcador = false;
                break;
            case 1:
                tentativas++;
                numeroSorteado = rand() % 10;
                system("cls");
                Sleep(1500);
                while(!kbhit()){
                    printf("tentativa %d\n\n", tentativas);
                    printf("Acerte o numero %d\n", numeroSorteado);
                    numero = rand() % 11;
                    if(aux != numero){
                        aux = numero;
                    }else{
                        if(numero == 10)
                            numero--;
                        else if(numero == 0)
                            numero++;
                        else
                            numero++;
                    }
                    printf("----------------------------------\n");
                    printf("--------------> %d <---------------\n", numero);
                    printf("----------------------------------\n");
                    printf("\nAperte ENTER para parar");
                    Sleep(tempo);
                    system("cls"); 
                }

                numeroEscolhido = numero;

                if(numeroEscolhido == numeroSorteado){
                    pontos += 10;
		            tempo -= 50;
                    printf("Parabens!\n");
                }else {
		            tempo = 1000;
                    pontos = pontos / 2;
                    printf("Tente de novo!\n");     
                }

                Sleep(2000);
                break;
            case 2:
                regras();
                break;
            default:
                system("cls");
                printf("Entrada invalida!\n\n");
                system("pause");
                break;
        }
    }while(marcador == true);

}

int main(void){
    printf("\n\n\n");
    printf("------BEM-VINDOS!------");
    Sleep(2000);
    
    menu();

    return 0;
}
