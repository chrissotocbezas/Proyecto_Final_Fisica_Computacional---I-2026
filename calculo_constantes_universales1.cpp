/* Para este caso de cálculo de las constantes universales de Feigenbaum,
procedemos a ejecutar una serie de cálculos con el caso genérico de 
la ecuación logística, el segundo archivo quedará para realizar pruebas de los métodos obtenidos.*/

// Procedemos a incluir las librerías necesarias para ejecutar nuestro cálculo.

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <fstream>

double mapa_logistico_p_veces_generico(double r, double x0, int periodo){
    double x = x0;
    // Colocamos un bucle for, para realizar las iteraciones que sean necesarias para este mapa logístico.
    for (int i = 0; i < periodo; ++i){
        x = r * x * (1.0 - x);
    }
    return x; // Le pedimos a esta función que devuelva x actualizado al final, lo que corresponde con la ecuación logística.
}

// Procedemos a realizar una función cero donde queremos encontrar: f^{2^k}(0.5) - 0.5 = 0

double ecuacion_superestable(double r, int period){
    return mapa_logistico_p_veces_generico(r, 0.5, period) - 0.5;
}

// Procedemos a colocar el método de bisección para encontrar la raíz en un intervalo [a, b]

double buscar_raiz(double a, double b, int periodo, double tol = 1e-12) {
    double c = a;
    // Realizamos la iteración mediante el bucle while...
    while ((b - a) >= tol) {
        c = (a + b) / 2.0;
        if (ecuacion_superestable(c, periodo) == 0.0) {
            break;
        } else if (ecuacion_superestable(a, periodo) * ecuacion_superestable(c, periodo) < 0) {
            b = c;
        } else {
            a = c;
        }
    }
    return c; // Se debe devolver c al final de la iteración.
}

int main() {
    // Procedemos a ejecutar los intervalos iniciales estimados para buscar R_k

    std::vector<std::pair<double, double>> intervalos = {
        {2.0, 3.0},
        {3.2, 3.49},
        {3.5, 3.54},
        {3.56, 3.57},
        {3.569, 3.570}
    };

    std::vector<double> R;
    for (size_t i = 0; i < intervalos.size(); ++i){
        R.push_back(buscar_raiz(intervalos[i].first, intervalos[i].second, std::pow(2, i)));

    }

    // Procedemos a crear un archivo CSV para exportar los datos...

    std::ofstream archivo("datos_feigenbaum1.csv");
    if (!archivo.is_open()){
        std::cerr << "Error al abrir el archivo para escribir. \n";
        return 1;
    }

    // Procedemos a guardar los R_k en las primeras líneas.

    archivo << "# Puntos Superestables encontrados\n";
    for (size_t i = 0; i < R.size(); ++i){
        archivo << "R, " << i + 1 << "," << std::setprecision(12) << R[i] << "\n";
    }

    // Procedemos a generar los puntos del diagrama de bifurcación (esto es la órbita asintótica)...

    archivo << "# Datos del Diagrama: r, x\n";
    int n_pasos = 800;
    int n_ultimos = 100;
    int puntos_r = 3000;

    double r_min = 2.4;
    double r_max = 4.0;
    double dr = (r_max - r_min) / puntos_r;

    // Procedemos a realizar iteraciones...

    for (int i = 0; i <= puntos_r; ++i){
        double r = r_min + i * dr;
        double x = 0.5; // Definimos la condición inicial...

        // Procedemos a realizar iteraciones para limpiar el transitorio...
        // Esto lo podemos ejecutar mediante un bucle for

        for(int j = 0; j < n_pasos; ++j){
            x = r * x * (1.0 - x);
            // Procedemos a guardar las últimas iteraciones (atractor estable)
            if (j >= (n_pasos - n_ultimos)){
                archivo << r << "," << x << "\n";
            }
        }
    }    
    archivo.close();
    std::cout << "¡Datos exportados correctamente!\n";
    return 0;
    
}