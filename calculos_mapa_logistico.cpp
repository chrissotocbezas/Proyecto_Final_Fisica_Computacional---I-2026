#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>

// Importamos las bibliotecas necesarias para poder ejecutar nuestro nuevo programa para C++...

// Procedemos a ejecutar nuestra función para nuestro sistema caótico...

/* En esta sección, colocamos algunas ecuaciones que nos pueden ser útiles para generar */
double ecuacion_1(double x, double c) {
    return 2.0 * c * x + 2.0 + x * x;
}

double ecuacion_2(double x, double mu){
    return 1.0 - mu * x * x;
}

double ecuacion_3(double x, double c){
    return c + x * x;
}

double ecuacion_4(double x, double b){
    return b * (1.0 - 2.0 * x * x);
}


/* En esta sección, podemos encontrar el caso del mapa logístico estándar, esta ecuación se le han asignado diferentes valores,
y tenemos en este caso, que r será igual para lambda, ya que la ecuación es tomada del libro de texto que se usa como referencia 
para este proyecto. Más específicamente, la ecuación usada corresponde */

double caso_mapa_logistico_estandar(double x, double lambda) {
    return 4.0 * lambda * x * (1.0 - x);
}

/* Procedemos a armar nuestro programa principal, donde tenemos en este caso, que guardar los datos en un archivo de texto,
esto lo hacemos con el fin de realizar una gráfica con base en lo que obtenemos, estos archivos serán utilizados luego para ejecutar
una gráfica en Python. */

int main() {
    // Procedemos a definir los parámetros para la configuración de la simulación

    int ID_ecuacion = 14; // Este número será para avisarle a Python qué graficar...
    double param = 0.23; // Definimos el parámetro de control para la función elegida
    double x0 = 0.2; // Definimos este valor como nuestra condición inicial
    int iteraciones = 175; // Estos corresponden a los pasos de la telaraña

    // Procedemos a definir los límites para el gráfico de Python

    double xmin = 0.0;
    double xmax = 1.0;

    // Donde podemos definir algunas condiciones para la configuración de la simulación, en donde tenemos ahora que:

    if (ID_ecuacion == 11) { xmin = -1.5; xmax = 1.5; }
    if (ID_ecuacion == 13) { xmin = -2.0; xmax = 2.0; }
    if (ID_ecuacion == 14) { xmin = -1.2; xmax = 1.2; }

    std::ofstream archivo("cobweb4_datos.txt"); // Esto pertenece a la biblioteca fstream, y se utsa para generar archivos de texto desde C++.
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo. " << std::endl;
        return 1;
    }

    // Procedemos a exportar los datos que serán parte del encabezado...

    archivo << ID_ecuacion << "," << param << "," << x0 << "," << xmin << "," << xmax << "\n";

    double x_actual = x0; // Esto nos ayudará a actualizar el paso del mapa logísitco más adelante.
    archivo << x_actual << "," << 0.0 << "\n"; // Esto corresponderá al inicio del eje x.

    // Procedemos a realizar el bucle de iteración, donde ejecutamos el algoritmo de telaraña.

    for (int i = 0; i < iteraciones; ++i) {

        // Procedemos a ejecutar un caso para una ecuación en específico, no se toman los datos para todas las ecuaciones.

        double x_siguiente = caso_mapa_logistico_estandar(x_actual, param);

        // Procedemos a guardar las coordenadas de los pasos de la telaraña
        
        archivo << x_actual << "," << x_siguiente << "\n"; // Este corresponde al paso vertical
        archivo << x_siguiente << "," << x_siguiente << "\n"; // Este corresponde al paso horizontal

        // Finalmente actualizamos de la forma:

        x_actual = x_siguiente;
    
    }

    archivo.close(); // Procedemos a cerrar el archivo.

    std::cout << "Cálculos terminados para la ecuación ( " << ID_ecuacion << " )." << std::endl;
    return 0;
    
}