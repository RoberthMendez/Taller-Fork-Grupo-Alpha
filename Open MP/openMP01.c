/*********************************************************************
 * Autor: Roberth Mendez
 * Programa: openMP01.c
 * Fecha: 13 de Mayo 2025
 * Tema: Programación Paralela - Introduccion OpenMP
 * Descripción: Se crean hilos y para cada hilo se imprime una cadena
 *		de caracteres junto con el id de cada hilo
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main (int argc, char *argv[]){

	//Se imprime un mensaje que indica la cantidad de hilos con las que se va a trabajar 
	//(Máximo de hilos disponibles en la máquina)
	printf("OpenMP ejecutado con %d hilos\n", omp_get_max_threads());

	#pragma omp parallel
	{
		//Esta instrucción será ejecutada por todos los hilos
		printf("Hello World desde el thread %d\n", omp_get_thread_num()); //Imprime el id del hilo en el que se encuentra
	}

	return 0;


}
