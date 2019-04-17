/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "functions.h"
#include "structs.h"

piloto* fill_pilots(int *tam) {
    
    FILE *f;
    piloto* p;

    int conta = 0;

    piloto aux[100];

    f = fopen("pilotos.txt", "rt");

    if (f == NULL) {
        puts("Erro na leitura do ficheiro!!\n Verifique o erro...");
        *tam = 0;
        exit(1);
    }

    while (!feof(f)) {
        fscanf(f, "%[^\n]", aux[conta].name);
        fscanf(f, "%d %d %d %d %f %f %d\n", &aux[conta].id, &aux[conta].birthday.dia, &aux[conta].birthday.mes, &aux[conta].birthday.ano, &aux[conta].peso, &aux[conta].experience, &aux[conta].punishment);
        conta++;
    }

    *tam = conta;

    p = malloc(*tam * sizeof (piloto));

    if (p == NULL) {
        fclose(f);
        *tam = 0;
        return 0;
    }

    for (int i = 0; i < *tam; i++) {
        p[i] = aux[i];
    }
    fclose(f);
    return p;
}

carro* fill_carros(int *tam) {
    FILE *f;
    carro *c;

    int conta = 0;

    carro car_aux[100];

    f = fopen("carros.txt", "rt");

    if (f == NULL) {
        puts("Erro na abertura do ficheiro!!\nVerifique o erro...");
        *tam = 0;
        exit(1);
    }

    while (!feof(f)) {
        fscanf(f, "%d %d %d\n", &car_aux[conta].id, &car_aux[conta].power, &car_aux[conta].broken);
        conta++;
    }
    *tam = conta;

    c = malloc(*tam * sizeof (carro));

    if (c == NULL) {
        fclose(f);
        *tam = 0;
        return 0;
    }

    for (int i = 0; i < *tam; i++) {
        c[i] = car_aux[i];
    }
    fclose(f);
    return c;

}

int consola() {
    int opcao = 0;

    scanf("%d", &opcao);

    return opcao;
}

void mostra_menu(piloto *p, int *tamP, carro *c, int *tamC) {
    int escolha = 0;
    int flag = -1;

    do {
        printf("  ____                         _           _                       _  __          _         ____  ___               \n");
        printf(" | __ )  ___ _ __ ___   __   _(_)_ __   __| | ___     __ _  ___   | |/ /__ _ _ __| |_ ___  / __ \\|_ _|___  ___  ___ \n");
        printf(" |  _ \\ / _ \\ '_ ` _ \\  \\ \\ / / | '_ \\ / _` |/ _ \\   / _` |/ _ \\  | ' // _` | '__| __/ __|/ / _` || |/ __|/ _ \\/ __|\n");
        printf(" | |_) |  __/ | | | | |  \\ V /| | | | | (_| | (_) | | (_| | (_) | | . \\ (_| | |  | |_\\__ \\ | (_| || |\\__ \\  __/ (__ \n");
        printf(" |____/ \\___|_| |_| |_|   \\_/ |_|_| |_|\\__,_|\\___/   \\__,_|\\___/  |_|\\_\\__,_|_|   \\__|___/\\ \\__,_|___|___/\\___|\\___|\n");
        printf("                                                                                           \\____/                   \n");

        puts("\n");
        puts("\n");
        puts("\t\t\t\t\t\t1 - Informacoes\n");
        puts("\n");
        puts("\n");
        puts("\t\t\t\t\t\t2 - Campeonato\n");
        puts("\n");
        puts("\n");
        puts("\t\t\t\t\t\t3 - Corrida\n");
        puts("\n");
        puts("\n");
        puts("\t\t\t\t\t\t4 - Sair\n");


        escolha = consola();


        system("cls");
        switch (escolha) {
            case 1:
                printf("\t  ___        __                                 /\\/|           \n");
                printf("\t |_ _|_ __  / _| ___  _ __ _ __ ___   __ _  ___|/\\/   ___  ___ \n");
                printf("\t  | || '_ \\| |_ / _ \\| '__| '_ ` _ \\ / _` |/ __/ _ \\ / _ \\/ __|\n");
                printf("\t  | || | | |  _| (_) | |  | | | | | | (_| | (_| (_) |  __/\\__ \\ \n");
                printf("\t |___|_| |_|_|  \\___/|_|  |_| |_| |_|\\__,_|\\___\\___/ \\___||___/\n");
                printf("\t                                            )_)                \n");


                puts("\n");
                puts("\n");
                puts("\t\t\t\t1 - Pilotos");
                puts("\n");
                puts("\t\t\t\t2 - Carros");
                puts("\n");
                puts("\t\t\t\t3 - Sair");


                escolha = consola();

                switch (escolha) {
                    case 1:
                        flag = show_pilots(p, tamP);
                        break;

                    case 2:
                        flag = show_cars(c, tamC);

                        break;
                    case 3:
                        system("cls");
                        puts("Pressione uma tecla para desligar...");
                        getch();
                        exit(1);
                }

                break;

            case 2:
                puts("Aqui mostra os campeonatos!! ");
                break;
            case 3:
                system("cls");
                criaCorrida();
            case 4:
                system("cls");
                puts("Pressione uma tecla para desligar...");
                getch();
                exit(1);
        }
    } while (flag != 1);
}

int show_pilots(piloto *p, int *tam) {

    int i;
    int escolha = 0;
    system("cls");

    puts("FUNCAO ||SHOW PILOTS||");


    for (i = 0; i < *tam; i++) {

        printf("\tPiloto %d:\n", i + 1);
        puts("Nome:");
        puts(p[i].name);
        puts("\nID:");
        printf("%d", p[i].id);
        puts("\nData de Nascimento: ");
        printf("%d %d %d", p[i].birthday.dia, p[i].birthday.mes, p[i].birthday.ano);
        puts("\nPeso:");
        printf("%f", p[i].peso);
        puts("\nExperiencia: ");
        printf("%0.2f", p[i].experience);
        puts("\nPenalizacao: ");
        printf("%d", p[i].punishment);

        puts("\n");
    }
    getch();
    puts("Deseja voltar ao menu anterior?");
    escolha = consola();

    return 0;
}

int show_cars(carro *p, int *tam) {
    int i;
    system("cls");

    puts("FUNCAO ||SHOW CARS||");

    for (i = 0; i < *tam; i++) {
        printf("Carro %d\n", i + 1);
        printf("ID : %d\n", p[i].id);
        printf("Potencia: %d\n", p[i].power);
        printf("Tempo de Avaria: %d\n", p[i].broken);

        puts("\n");
    }
    getch();
    return 0;
}

void criaCorrida() {
    

    pcorrida lista = NULL;
    
    pcorrida corrida1;

    
    corrida1 = malloc(sizeof(corrida));
    if(corrida1 == NULL)
    {
        puts("Erro na alocação de memoria!!!!");
        exit(1);
    }
    
    system("cls");

    puts("Preencha os dados para comecar uma corrida: \n");
    do {
        puts("Numero de voltas : ");
        scanf("%d", &corrida1->laps);
        puts("\nComprimento : ");
        scanf("%d", &corrida1->lenght);
        puts("\nNumero maximo de participantes : ");
        scanf("%d", &corrida1->max_racers);
        if (corrida1->lenght > 1000 || corrida1->lenght < 500) {
            puts("\nIntroduza um numero valido para o comprimento da pista!!");
            scanf("\n%d", &corrida1->lenght);
        } else if (corrida1->laps > 10 || corrida1->laps < 5) {
            puts("\nIntroduza um numero valido para o numero de voltas!!");
            scanf("\n%d", &corrida1->laps);
        }

    } while (corrida1->lenght > 1000 || corrida1->lenght < 500 || corrida1->laps > 10 || corrida1->laps < 5);

    system("cls");

    puts("   ____                _     _                   _           _                                                                 \n");
    puts(" / ___|___  _ __ _ __(_) __| | __ _    ___ _ __(_) __ _  __| | __ _    ___ ___  _ __ ___    ___ _   _  ___ ___  ___ ___  ___  \n");
    puts("| |   / _ \\| '__| '__| |/ _` |/ _` |  / __| '__| |/ _` |/ _` |/ _` |  / __/ _ \\| '_ ` _ \\  / __| | | |/ __/ _ \\/ __/ __|/ _ \\ \n");
    puts("| |__| (_) | |  | |  | | (_| | (_| | | (__| |  | | (_| | (_| | (_| | | (_| (_) | | | | | | \\__ \\ |_| | (_|  __/\\__ \\__ \\ (_) |\n");
    puts(" \\____\\___/|_|  |_|  |_|\\__,_|\\__,_|  \\___|_|  |_|\\__,_|\\__,_|\\__,_|  \\___\\___/|_| |_| |_| |___/\\__,_|\\___\\___||___/___/\\___/ \n");
    
    printf("\t\t\t\tNumero de Voltas : %d",corrida1->laps);
    printf("\t\t\t\tComprimento da Pista : %d",corrida1->lenght);
    printf("\t\t\t\tNumero de Participantes : %d",corrida1->max_racers);
    
    lista->prox = corrida1;
    corrida1->prox = NULL; 
    
}



