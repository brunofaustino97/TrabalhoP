/* 
 * File:   functions.h
 * Author: Asus
 *
 * Created on 1 de Abril de 2019, 15:01
 */
#include "structs.h"
#ifndef FUNCTIONS_H
#define FUNCTIONS_H


piloto* fill_pilots(int *tam);

carro* fill_carros(int *tam);

void mostra_menu(piloto *p, int *tamP, carro *c, int *tamC);

int consola();

int mostramenu_informacoes(piloto *p, int *tamP, carro *c, int *tamC);

int show_pilots(piloto *p, int *tam);


int show_cars(carro *p, int *tam);

void criaCorrida();

#endif
