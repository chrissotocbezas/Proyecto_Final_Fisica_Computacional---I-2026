# Instrucciones para Ejecución de Códigos para cada uno de los Procedimientos

Nombre: Christopher Soto Cabezas.

## Proyecto de Mapa Logístico...

Este proyecto consiste en el estudio de diferentes formas de mapas logísticos, sus configuraciones y sus significados. En este proyecto, se van a indicar cómo compilar cada archivo y qué archivos utilizar para cada caso.

#### Primera Actividad (Caso de los Mapas de Telarañas)

Para este archivo, se debe utilizar de forma primaria el archivo conocido como:

calculos_mapa_logistico.cpp

Este archivo se deberá de compilar, mediante g++ -std=c++17 calculos_mapa_logistico.cpp -o calculos_mapa_logistico

En este archivo, se encuentran compilados todos los datos que se usarán para procesar en el código dado para hacer la gráfica de telaraña.

Cargar los datos del archivo en formato .txt, al archivo grafica_telarana_multiple.py, asegúrarse que el nombre del archivo que está cargando coincida con el nombre del archivo que se está abriendo.

Ejecutar el archivo python con python3 grafica_telarana_multiple.py

#### Segunda Actividad (Construcción Óptima Diagramas de Bifurcación)

Para esta actividad, se deben ejecutar los archivos:

1. calculos_diagrama_bifurcacion.cpp
2. grafica_bifurcacion_1.py

Se debe compilar de la misma forma que el archivo de calculos_mapa_logistico.cpp y posteriormente, ejecutar el archivo, para que quede en la forma de datos tipo .txt, en este caso, se debe asegurar que el archivo .txt en ambos programas coincida para ejecutar una gráfica correcta.

¡Se puede generar un archivo muy grande de datos para este caso, por lo que este recomendable ajustar bien los parámetros para evitar saturación del sistema!

#### Tercera Actividad (Constantes Universales de Feigenbaum)

Los archivos a ejecutar para esta actividad corresponden a:

1. calculo_constantes_universales1.cpp
2. calculo_constantes_universales2.cpp
3. grafica_aproximacion_universal.py

En este caso, se debe resaltar que el primer archivo (1), solo se encuentra seleccionado para ejecutar un caso genérico del mapa logístico. El otro archivo, se encuentra disponible para ejecutar múltiples gráficas con diferentes funciones.

La compilación es la misma:

g++ -std=c++17 calculo_constantes_universales2.cpp. -o calculo_constantes_universales2

Y para la gráfica de Python:

python3 grafica_aproximacion_universal1.py

Asegurarse que el archivo .csv coincida en nombres para una ejecución correcta.