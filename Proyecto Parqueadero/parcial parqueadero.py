import time #sirve para contar el tiempo de permanencia del vehiculo
def crear_mapa(filas=8, columnas=8):# Crear un mapa de parqueadero
    return [['E' for _ in range(columnas)] for _ in range(filas)]

def mostrar_mapa(mapa):
    print("Mapa del parqueadero:")#sirve para mostrar el mapa
    print("E: Espacio Libre | O: Ocupado")# sirve para mostrar el mapa si es ocupado o libre
    for fila in mapa:
        print(' '.join(fila))# srive para mostrar el mapa
    print()

registro_vehiculos = {}# es una lista vacia que se va a llenar con los vehiculos que se ingresen al parqueadero

def espacio_disponible(mapa, fila, columna):# se usa la funcion para verificar si esta desocupado el espacio
    if fila < 0 or fila >= len(mapa) or columna < 0 or columna >= len(mapa[0]):# se usa para saber si la posicion es valida
        print("Posición fuera del parqueadero.")
        return False
    if mapa[fila][columna] == 'E':# si el espacio esta libre se devuelve True y se muestra que esta libre
        return True
    else:
        return False

def ingresar_vehiculo(mapa, placa, fila, columna, tiempo_permanencia_min):# se usa para ingresar el vehiculo al parqueadero con todo lo que se pide para que sea adecuado el ingreso de datos
    if espacio_disponible(mapa, fila, columna):# si el espacio esta libre se ingresa el vehiculo
        mapa[fila][columna] = 'O'# se usa para marcar el espacio como ocupado
        hora_entrada = time.time()# se usa para saber la hora de entrada del vehiculo
        registro_vehiculos[placa] = {# se usa para guardar el vehiculo en el registro
            'posicion': (fila, columna),
            'tiempo_permanencia_min': tiempo_permanencia_min,
            'hora_entrada': hora_entrada
        }
        print(f"Vehículo {placa} ingresó en la posición ({fila}, {columna}).")# se usa para mostrar que el vehiculo se ingreso correctamente
    else:
        print(f"La posición ({fila}, {columna}) está ocupada.")# se usa para devolfer el kmensaje de que esta ocupada

def retirar_vehiculo(mapa, placa):# se usa para retirar el vehiculo del parqueadero
    if placa in registro_vehiculos:
        fila, columna = registro_vehiculos[placa]['posicion']# se usa para saber la posicion del vehiculo
        mapa[fila][columna] = 'E'# se usa para marcar el espacio como libre
        del registro_vehiculos[placa]# se usa para eliminar el vehiculo del registro
        print(f"Vehículo {placa} ha sido retirado del parqueadero.")
    else:
        print("Vehículo no encontrado.")

def verificar_tiempos(mapa):# se usa para verificar si el vehiculo ha excedido el tiempo de permanencia
    tiempo_actual = time.time()# se usa para saber la hora actual
    placas_para_retirar = []# se usa para guardar las placas de los vehiculos que han excedido el tiempo
    for placa, info in registro_vehiculos.items():# se usa para recorrer el registro de vehiculos
        tiempo_permanencia_real = (tiempo_actual - info['hora_entrada']) / 60  # en minutos
        if tiempo_permanencia_real > info['tiempo_permanencia_min']:# se usa para saber si el vehiculo ha excedido el tiempo de permanencia
            print(f"Vehículo {placa} excedió el tiempo permitido de {info['tiempo_permanencia_min']} minutos.")# se usa para mostrar el mensaje de que ha excedido el tiempo
            print(f"Llamada ficticia al propietario del vehículo {placa} para retiro inmediato.")# se usa para mostrar el mensaje de que se llamo al propietario
            placas_para_retirar.append(placa)
    for placa in placas_para_retirar:
        retirar_vehiculo(mapa, placa)

def calcular_costo(placa):# se usa para calcular el costo del vehiculo
    if placa in registro_vehiculos:
        tiempo_entrada = registro_vehiculos[placa]['hora_entrada']
        tiempo_permanencia = time.time() - tiempo_entrada
        horas = tiempo_permanencia / 3600
        costo = horas * 2  # tarifa $2 por hora
        return costo
    else:
        print("Vehículo no encontrado para calcular costo.")
        return 0

def main():
    mapa_parqueadero = crear_mapa()
    while True:
        mostrar_mapa(mapa_parqueadero)
        print("Opciones:")
        print("1. Ingresar vehículo")
        print("2. Verificar y retirar vehículos que excedieron tiempo")
        print("3. Calcular costo y retirar vehículo")
        print("4. Salir")
        opcion = input("Seleccione una opción: ")

        if opcion == '1':
            placa = input("Ingrese placa del vehículo: ").upper()
            try:
                fila = int(input("Ingrese fila (0-7) donde desea parquear: "))
                columna = int(input("Ingrese columna (0-7) donde desea parquear: "))
                if not espacio_disponible(mapa_parqueadero, fila, columna):
                    print(f"Posición ({fila}, {columna}) está ocupada, intente otra posición.\n")
                    continue
                tiempo_permanencia_min = int(input("Ingrese tiempo estimado de permanencia en minutos: "))
                ingresar_vehiculo(mapa_parqueadero, placa, fila, columna, tiempo_permanencia_min)
            except ValueError:
                print("Entrada inválida. Intente de nuevo.\n")
        elif opcion == '2':
            verificar_tiempos(mapa_parqueadero)
        elif opcion == '3':
            placa = input("Ingrese placa del vehículo para calcular costo y retirar: ").upper()
            costo = calcular_costo(placa)
            if costo > 0:
                print(f"Costo a pagar para el vehículo {placa}: ${costo:.2f}")
                retirar_vehiculo(mapa_parqueadero, placa)
            print()
        elif opcion == '4':
            print("Saliendo del sistema de parqueadero.")
            break
        else:
            print("Opción inválida. Intente nuevamente.\n")

if __name__ == '__main__':
    main()

