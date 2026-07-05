// Procedemos a colocar bibliotecas necesarias, para generar nuestro mapa de bifurcación.
// Esto corresponde a los cálculos.

#include <iostream>
#include <fstream>
#include <vector>

int main(){

    // Colocamos los parámetros de la simulación.

    const double r_min = -2.0;
    const double r_max = -0.5;
    const double dr = 0.008; // Este valor corresponde al paso fino para el barrido de r

    const int N_trans = 1000; // Este valor corresponderá a las iteraciones descartadas (también conocidas como transitorios).
    const int N_guardado = 100; // Esto corresponderá a las iteraciones guardadas (conocidos como casos asintóticos).

    // Procedemos a abarir un archivo para guardar los datos.
    // El archivo estará en formato de texto.

    std::ofstream archivo("datos_bifurcacion3.txt");
    if (!archivo.is_open()){ // Esto lo colocamos para poder crear nuestro archivo.
        std::cerr<< "Error al abrir el archivo, vuelva a intentarlo de nuevo. " << std::endl;
        return 1; // Verificamos que se ejecute lo que estamos planteando mediante este return.
    }

    // Procedemos a ejecutar el barrido del parámetro de control r.
    // Este parámetro puede tomar un valor diferente como lambda, dependiendo de la bibliografía que estemos utilizando.

    for (double r = r_min; r <= r_max; r += dr) {
        double x = -r/2.0; // Procedemos con una condición inicial arbitraria para el intervalo (0,1)

        // Volvemos a generar un nuevo bucle for, para el filtrado de datos transitorios o de las iteraciones descartadas.

        for (int i = 0; i < N_trans; ++i) {
            x = 2.0 * r * x + 2.0 * x * x;
        }

        // Y ejecutamos el mapeo para el atractor, donde usamos los datos dados por N_guardado
        
        for (int i = 0; i < N_guardado; ++i) {
            x = 2.0 * r * x + 2.0 * x * x;
            archivo << r << " " << x << "\n";
        }
    }

    archivo.close();
    std::cout << "Cálculos completados." << std::endl;
    return 0;
}