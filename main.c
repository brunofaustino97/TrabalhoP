/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Asus
 *
 * Created on 1 de Abril de 2019, 14:24
 */

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include <conio.h>
#include "structs.h"
#include "functions.h"



int main(int argc, char** argv) {
   
    piloto *pilotosArray = NULL;
    carro *carrosArray = NULL;
    
    
    
    int tamP = 0;
    int tamC = 0;

    pilotosArray = fill_pilots(&tamP);
    carrosArray = fill_carros(&tamC);
    
    mostra_menu(pilotosArray,&tamP,carrosArray, &tamC);
    
    
    
    free(pilotosArray);
    free(carrosArray);
    
    return (EXIT_SUCCESS);
}

