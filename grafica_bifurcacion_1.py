# Para este archivo de Python, ejecutaremos la gráfica para nuestro diagrama de bifurcación.

import numpy as np
import matplotlib.pyplot as plt 

# Procedemos a cargar los datos generados por nuestro código en C++.

try:
    datos = np.loadtxt("datos_bifurcacion3.txt")
    r_valores = datos[:, 0]
    x_asintotico = datos[:, 1]
except FileNotFoundError:
    print("No se encontró el archivo, vuelva a ejecutar el programa en C++.")
    exit()

# Procedemos a crear la gráfica

plt.figure(figsize=(10,6), dpi=200)

# Procedemos a graficar con marcadores muy pequeños, para una mayor resolución.

plt.plot(r_valores, x_asintotico, ',b', alpha=0.15)

# Procedemos con la configuración de las etiquetas y estilo

plt.title("Diagrama de Bifurcación (Mapa Logístico (Límites acortados))", fontsize=14)
plt.xlabel("Parámetro de control ($r$)", fontsize=12)
plt.ylabel("$x$ asintótico", fontsize=12)
plt.xlim(2.5, 3.8)
plt.ylim(0, 1)
plt.grid(True, linestyle=":", alpha=0.5)

# Procedemos a mostrar y guardar la imagen
plt.tight_layout()
plt.savefig("diagrama_bifurcacion_5.png", dpi=300)
plt.show()