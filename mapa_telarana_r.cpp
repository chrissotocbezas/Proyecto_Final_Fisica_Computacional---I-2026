/* En este archivo, procedemos a colocar un caso genérico para la función 
del mapa logístico, en este caso, se realizan cálculos similares al caso propio de la función del mapa logístico, 
y se procederán a realizar cambios en los parámetros y la forma de la ecuación, la cual resulta ser el caso genérico.
*/

#include <iostream>
#include <fstream>
#include <vector>

// Agregamos las bibliotecas útiles para generar nuestro código.

double mapa_logistico(double x, double r) {
    return r * x * (1.0 -x); // Esta ecuación corresponde a la forma genérica del mapa logístico.
}

int main() {
    // Procedemos a dar los parámetros para la simulación

    double r = 0.75; // Parámetro de control
    double x0 = 0.8; // Condición inicial
    int iteraciones = 100; // Colocamos el número de pasos.

    // Colocamos un xmin y un xmax

    double xmin = -2.0;
    double xmax = 1.0;

    std::ofstream archivo("cobweb4_data.txt");
    if (!archivo.is_open()){
        std::cerr << "Error al abrir el archivo para escribir." << std::endl;
        return 1;
    }

    // Procedemos a guardar los parámetros en la primera línea, esto lo hacemos con el objetivo de que Python reconozca los
    // datos de la tabla.

    archivo << r << "," << x0 << "," << iteraciones << "," << xmin << "," << xmax << "\n";

    double x_actual = x0;

    /*Para el gráfico de telaraña, procedemos a empezar verticalmente desde (x0, 0)*/

    archivo << x_actual << "," << 0.0 << "\n";

    // Armamos el bucle for para realizar las iteraciones del mapa de telaraña.

    for (int i = 0; i < iteraciones; ++i) {
        double x_siguiente = mapa_logistico(x_actual, r);

        // Procedemos a ejecutar el movimiento vertical de la curva.

        archivo << x_actual << "," << x_siguiente << "\n";

        // Procedemos a ejecutar el caso para el movimiento horizontal a la línea de identidad...

        archivo << x_siguiente << "," << x_siguiente << "\n";

        x_actual = x_siguiente;
    }
    
    archivo.close();
    std::cout << "Datos exportados exitosamente a 'cobweb2_data,txt'" << std::endl;
    return 0;
}