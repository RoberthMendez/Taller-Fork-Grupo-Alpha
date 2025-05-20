# Multiplicación de Matrices con OpenMP

Este proyecto implementa una versión paralela del algoritmo clásico de multiplicación de matrices utilizando OpenMP. Dentro del membrete del fichero mmClasicaOpenMP.c se encuentra una breve descripción del programa, unas conclusiones realizadas luego del análisis del código y un par de recomendaciones sobre el programa.

## Autor
- Roberth Méndez

## Archivos

- `mmInterfazOpenMP.h`: Contiene las declaraciones de funciones auxiliares.
- `mmInterfazOpenMP.c`: Implementación de las funciones auxiliares.
- `mmClasicaOpenMP.c`: Programa principal que realiza la multiplicación paralela de matrices.

## Compilacion
```bash
gcc mmClasicaOpenMP.c mmInterfazOpenMP.c -o clasicaOpenMP -fopenmp
```
##Recomendaciones
- No utilizar más hilos que los soportados por el sistema para evitar pérdida de rendimiento.
- La impresión de matrices solo se realiza si su tamaño es menor a 9 para facilitar la lectura.

