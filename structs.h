/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   structs.h
 * Author: Asus
 *
 * Created on 1 de Abril de 2019, 14:49
 */
#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct data
{
    int dia;
    int mes;
    int ano;
    
}data_nascimento;

typedef struct Pilotos{
    
    char name[100];
    int id;
    data_nascimento birthday;
    float peso;
    float experience;
    int punishment;
    
}piloto;

typedef struct Carros{
    
    int id;
    int power;
    int broken;
    
}carro;

typedef struct Race corrida,*pcorrida;

typedef struct Race{
    
    int laps;
    int lenght;
    int max_racers;
    pcorrida prox;
    
    
}

#endif