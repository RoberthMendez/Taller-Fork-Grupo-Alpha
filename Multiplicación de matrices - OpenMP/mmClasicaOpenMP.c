/**********************************************************************************************************
 * - Pontificia Universidad Javeriana
 * - Nombres: Gabriel Jaramillo, Viviana Gomez, Roberth Mendez, Luz Adriana Salazar, Guden Silva
 * - Clase: Sistemas Operativos
 * - Fecha: 2025-04-30
 * - Tema: Evaluación de Rendimiento
 * - Descripción: Se ejecuta el algoritmo clásico de multiplicación de matrices (filas por columnas)
 *	 	  repartiendo el trabajo de filas por columnas entre múltiples hilos con OpenMP.
 *
 * - Conclusión: El programa funciona correctamente ya que se ejecuta el algoritmo satisfactoriamente
 *		 gracias a las siguientes razones:
 *		- Antes de ejecutar el algoritmo de multiplicación se establecen los hilos a usar
 *		  mediante la instrucción "omp_set_num_threads()" usando como parámetro
 *		  la cantidad de hilos ingresada por el usuario.
 *		- A la hora de ejecutar la función de multiplicación de matrices, se hace uso de
 *		  las directivas "#pragma" para decirle al compilador que se distribuya el trabajo
 *		  de multiplicación entre los hilos establecidos.
 *		- Se establecen las variables "Suma", "pA" y "pB" privadas para cada hilo,
 *		  con el fin de evitar condiciones de carrera.
 *
 * - Recomendaciones: Con el fin de obtener un rendimiento alto del algoritmo, se recomienda
 *		      no usar una mayor cantidad de hilos mayor a la cantidad máxima de hilos del sistema.
 *		      Evitando esto se aprovecha al máximo el paralelismo.
 ***********************************************************************************************************/

#include "mmInterfazOpenMP.h"

/*
 * Función principal que:
 * 1. Valida argumentos de entrada (tamaño y número de hilos)
 * 2. Reserva memoria e inicializa matrices
 * 3. Realiza la multiplicación de matrices en paralelo 
 * 4. Mide el tiempo de ejecución
 * 5. Imprime las matrices si son pequeñas
 */
int main(int argc, char *argv[]){
	if(argc < 3){
		printf("\n Use: $./clasicaOpenMP SIZE Hilos \n\n");
		exit(0);
	}

	int N = atoi(argv[1]);  // Dimensión de la matriz
	int TH = atoi(argv[2]); // Número de hilos a utilizar

	// Reservar memoria para matrices A, B y C 
	size_t *matrixA  = (size_t *)calloc(N*N, sizeof(size_t));
	size_t *matrixB  = (size_t *)calloc(N*N, sizeof(size_t));
	size_t *matrixC  = (size_t *)calloc(N*N, sizeof(size_t));

	srand(time(NULL));      // Inicializa semilla para números aleatorios 

	omp_set_num_threads(TH); // Establece número de hilos a usar con OpenMP

	iniMatrix(matrixA, matrixB, N); // Inicializa las matrices A y B

	impMatrix(matrixA, N);  // Imprime matriz A si es pequeña
	impMatrix(matrixB, N);  // Imprime matriz B si es pequeña

	InicioMuestra();              // Inicia cronómetro
	multiMatrix(matrixA, matrixB, matrixC, N); // Multiplica matrices
	FinMuestra();                 // Finaliza cronómetro e imprime el tiempo

	impMatrix(matrixC, N);        // Imprime matriz resultado si es pequeña

	free(matrixA);                // Libera memoria asignada a matriz A
	free(matrixB);                // Libera memoria asignada a matriz B
	free(matrixC);                // Libera memoria asignada a matriz C

	return 0;
}
