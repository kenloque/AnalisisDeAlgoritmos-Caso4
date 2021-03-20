# AnalisisDeAlgoritmos-Caso4

Tarea universitaria de Análisis de Algoritmos 

## Explicación

El algoritmo funciona sobre un ciclo en el cual se crean y se guardan las coordenadas de cada linea de la imagen representada por un par de puntos. Los puntos son creados desde el valor de la altura y el ancho máximo y las coordenadas iniciales, los cuales son alterados de manera porcentual para reducir la imagen.

## F(n)
Donde n=3 por el for interno...

El f(n) = 3 + (19 + 14 + 50 + 49 + 41 + 18 + 8 + 4 + 4)*((3n+1)*n*)

   f(n) = 3 + 207(3n^2 + n)
   f(n) = 621n^2 + 207n + 3

## O(n)
 
   O(n^2)
