# Procedemos a ejecutar la gráfica en este código...

import numpy as np 
import matplotlib.pyplot as plt 

# Procedemos a ejecutar los contenedores de datos...

r_puntos = []
x_puntos = []
R_bifurcaciones = []

# Procedemos a leer el archivo generado por C++
print("Leyendo archivo .csv...")
with open("datos_feigenbaum1.csv", "r") as f:
    for linea in f:
        if linea.startswith("#") or not linea.strip():
            continue # Ignorar comentarios y líneas vacías
        
        partes = linea.strip().split(",")
        if partes[0] == "R":
            # Colocamos la constante R_k calculada
            R_bifurcaciones.append(float(partes[2]))
        else:
            # Este es un punto del diagrama de bifurcación (r, x)
            r_puntos.append(float(partes[0]))
            x_puntos.append(float(partes[1]))

# Procedemos a convertir todas las listas en arrays de numpy

r_puntos = np.array(r_puntos)
x_puntos = np.array(x_puntos)

# Procedemos a graficar

plt.figure(figsize=(12, 7), dpi=120)

# Procedemos a calcular el diagrama para observar el comportamiento del diagrama...

plt.plot(r_puntos, x_puntos, ',k', alpha=0.1, label="Órbitas estables(C++)")

# Procedemos a dibujar las líneas verticales.

colores = ['red', 'blue', 'green', 'purple', 'orange']
for idx, r_val in enumerate(R_bifurcaciones):
    if idx < 4: # Procedemos a graficar solo las primeras...
        plt.axvline(x=r_val, color=colores[idx], linestyle='--', alpha=0.8, label=f'R_{idx+1} calculada: {r_val:.5f}')

plt.title("Diagrama de Bifurcación desde C++", fontsize=14)
plt.xlabel("Parámetro de control ($r$)", fontsize=12)
plt.ylabel("$x$ (Estado asintótico)", fontsize=12)
plt.xlim(2.8, 3.7)
plt.ylim(0.2, 1.0)
plt.legend(loc='upper left', markerscale=10)
plt.grid(True, alpha=0.2)
plt.savefig('GraficaAproximacion1.png', dpi=300)
plt.show()