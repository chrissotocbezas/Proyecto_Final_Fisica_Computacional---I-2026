import pandas as pd 
import matplotlib.pyplot as plt
import numpy as np 

# Procedemos a cargar el archivo de texto, para generar la gráfica de telaraña.

with open("cobweb4_datos.txt", "r") as f:
    linea_meta = f.readline().strip().split(",")
    ecuacion = float(linea_meta[0])
    param = float(linea_meta[1])
    x0 = float(linea_meta[2])
    xmin = float(linea_meta[3])
    xmax = float(linea_meta[4])

    datos = np.loadtxt(f, delimiter=",") # En este caso, aunque el archivo esté en formato de texto, con esto lo cargamos con un .csv

x_data = datos[:, 0] # Datos de x, corresponden a la primera columna.
y_data = datos[:, 1] # Los datos en y, corresponden a la segunda columna.

# Procedemos a definir de forma matemática la función para que Python detecte la curva.

x_curva = np.linspace(xmin, xmax, 1000) # Definimos el array entre los valores máximo y mínimo del intervalo seleccionado para esta función.

if ecuacion == 10:
    y_curva = 2 * param * x_curva + 2 * x_curva**2
    txt_equation = f"$f(x) = 2({param})x + 2x^2$"
elif ecuacion == 11:
    y_curva = 1 - param * x_curva**2
    txt_equation = f"$f(x) = 1 - {param}x^2$"
elif ecuacion == 12:
    y_curva = 4 * param * x_curva * (1 - x_curva)
    txt_equation = f"$f(x) = 4({param})x(1-x)$"
elif ecuacion == 13:
    y_curva = param + x_curva**2
    txt_equation = f"$f(x) = {param} + x^2$"
elif ecuacion == 14:
    y_curva = param * (1 - 2*x_curva**2)
    txt_equation = f"$f(x) = {param}(1 - 2x^2)$"

# Procedemos a ejecutar la gráfica

plt.figure(figsize=(8,8))

# Procedemos a graficar la curva y recta identidad dinámicas, esto es parte importante del gráfico de telaraña.

plt.plot(x_curva, y_curva, 'b-', label=txt_equation, linewidth=1.5)
plt.plot([xmin, xmax], [xmin, xmax], 'g--', label='Identidad (y=x)', linewidth=1)

# Procedemos a definir el camino de la telaraña

plt.plot(x_data, y_data, 'r-', label='Órbita (Cobweb)', alpha=0.85, linewidth=1.2)
plt.scatter([x0], [0], color='black', zorder=5, label=f'$x_0$ = {x0}')

# Colocamos la configuración de los ejes...

plt.title(f'Diagrama de Telaraña - Ecuación 1 con parámetro = {param}', fontsize=13)
plt.xlabel('$x_n$', fontsize=12)
plt.ylabel('$x_{n+1}$', fontsize=12)
plt.xlim(xmin, xmax)
plt.ylim(xmin, xmax)
plt.grid(True, linestyle=":", alpha=0.6)
plt.legend(loc='upper left')
plt.savefig(f'Gráfica 3 Diagrama Telaraña valor parámetro = {param}.png', dpi=300)
plt.show()