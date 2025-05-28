# Explicacion codigo del parqueadero
Hay diferentes funciones usadas en este codigo y cada una de ellas se va a describir a continuacion
## Import time
Esta línea importa el módulo time, que proporciona funciones para trabajar con el tiempo. En este código, se utiliza para obtener la hora actual y calcular la duración de la permanencia de los vehículos en el parqueadero.    
## Def
La palabra clave def se utiliza para definir una función en Python. Cada función puede tener parámetros de entrada y puede devolver un valor. En el código, se utilizan para definir diversas funciones que gestionan el parqueadero, como crear_mapa, mostrar_mapa, ingresar_vehiculo, etc.    
## Enumerate
enumerate es una función incorporada en Python que permite iterar sobre un objeto iterable (como una lista) y obtener tanto el índice como el valor de cada elemento en la iteración. En el código, se utiliza en la función mostrar_mapa para recorrer las filas del mapa y obtener tanto el índice de la fila (i) como la fila misma (fila).    
## espacio_disponible(mapa, fila, columna)
Esta función verifica si hay un espacio disponible en el parqueadero en la posición especificada por fila y columna.

Comprueba si las coordenadas están dentro de los límites del mapa y si la celda correspondiente es un espacio de parqueo ('E') que no está ocupado por otro vehículo.    
## ingresar_vehiculo(mapa, placa, fila, columna, tiempo_permanencia_min)
Esta función permite ingresar un vehículo en el parqueadero.
Verifica si el espacio está disponible utilizando la función espacio_disponible. Si está disponible, registra la entrada del vehículo, incluyendo su posición y el tiempo estimado de permanencia.    
## retirar_vehiculo(placa)
Esta función elimina un vehículo del registro utilizando su placa.
Si la placa no se encuentra en el registro, imprime un mensaje indicando que el vehículo no fue encontrado.    
## calcular_costo(placa)
Esta función calcula el costo de permanencia de un vehículo en el parqueadero.
Utiliza la hora de entrada registrada y el tiempo actual para calcular el tiempo de permanencia en horas y luego multiplica por un costo por hora (en este caso, 2 unidades monetarias por hora).   
## verificar_tiempos(mapa)
Esta función verifica si algún vehículo ha excedido su tiempo de permanencia permitido.
Recorre el registro de vehículos y compara el tiempo actual con la hora de entrada. Si un vehículo ha excedido su tiempo, se imprime un mensaje y se llama a la función retirar_vehiculo para eliminarlo del registro. 
## generar_ruta(mapa, destino)
Esta función genera una ruta desde la entrada del parqueadero hasta la posición de un vehículo específico (destino).
Crea una lista de coordenadas que representan la ruta a seguir, que se utilizará para mostrar visualmente el camino en el mapa.    


