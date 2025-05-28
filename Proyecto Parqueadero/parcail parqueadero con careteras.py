import time

def crear_mapa():
    mapa = [
        ['I','#','E','E','E','E','E','E'],
        ['#','#','#','#','#','#','#','#'],
        ['E','#','E','E','E','E','E','#'],
        ['E','#','#','#','#','#','#','#'],
        ['E','#','E','E','E','E','E','#'],
        ['E','#','#','#','#','#','#','#'],
        ['E','#','E','E','E','E','E','#'],
        ['E','#','#','#','#','#','#','S'],
    ]
    return mapa

registro_vehiculos = {}

def mostrar_mapa(mapa, registro, ruta=None):
    print("Mapa del Parqueadero - Vehículos con V + placa (2 últimos caracteres)")
    for i, fila in enumerate(mapa):
        linea = ''
        for j, celda in enumerate(fila):
            coord = (i,j)
            en_ruta = ruta and coord in ruta
            marcar_ruta = '_' if en_ruta else ' '
            if celda == '#':
                linea += '·' + marcar_ruta + ' '
            elif celda == 'I':
                linea += 'I' + marcar_ruta + ' '
            elif celda == 'S':
                linea += 'S' + marcar_ruta + ' '
            elif celda == 'E':
                ocupado = False
                vehiculo_letras = ''
                for placa, info in registro.items():
                    if info['posicion'] == coord:
                        ocupado = True
                        vehiculo_letras = placa[-2:]
                        break
                if ocupado:
                    linea += 'V'+vehiculo_letras + marcar_ruta + ' '
                else:
                    linea += 'E' + marcar_ruta + ' '
            else:
                linea += celda + marcar_ruta + ' '
        print(linea)
    print()

def espacio_disponible(mapa, fila, columna):
    if fila < 0 or fila >= len(mapa) or columna < 0 or columna >= len(mapa[0]):
        print("Posición fuera del parqueadero.")
        return False
    if mapa[fila][columna] == 'E':
        for info in registro_vehiculos.values():
            if info['posicion'] == (fila,columna):
                return False
        return True
    else:
        return False

def ingresar_vehiculo(mapa, placa, fila, columna, tiempo_permanencia_min):
    if espacio_disponible(mapa, fila, columna):
        hora_entrada = time.time()
        registro_vehiculos[placa] = {
            'posicion': (fila,columna),
            'tiempo_permanencia_min': tiempo_permanencia_min,
            'hora_entrada': hora_entrada
        }
        print(f"Vehículo {placa} ingresó en ({fila},{columna})")
    else:
        print(f"La posición ({fila},{columna}) está ocupada o inválida.")

def retirar_vehiculo(placa):
    if placa in registro_vehiculos:
        del registro_vehiculos[placa]
        print(f"Vehículo {placa} retirado.")
    else:
        print("Vehículo no encontrado.")

def calcular_costo(placa):
    if placa in registro_vehiculos:
        info = registro_vehiculos[placa]
        tiempo_entrada = info['hora_entrada']
        tiempo_permanencia = time.time() - tiempo_entrada
        horas = tiempo_permanencia / 3600
        costo = horas * 2
        return costo
    else:
        print("Vehículo no encontrado para calcular costo.")
        return 0

def verificar_tiempos(mapa):
    tiempo_actual = time.time()
    placas_para_retirar = []
    for placa, info in registro_vehiculos.items():
        tiempo_real_min = (tiempo_actual - info['hora_entrada'])/60
        if tiempo_real_min > info['tiempo_permanencia_min']:
            print(f"Vehículo {placa} excedió tiempo permitido ({info['tiempo_permanencia_min']} min).")
            print(f"Llamada simulada al propietario para retiro inmediato.")
            placas_para_retirar.append(placa)
    for placa in placas_para_retirar:
        retirar_vehiculo(placa)
    if not placas_para_retirar:
        print("Ningún vehículo excedió su tiempo.")
    input("Presione Enter para continuar...")

def generar_ruta(mapa, destino):
    fila_dest, col_dest = destino
    ruta = []
    for c in range(1, col_dest if col_dest % 2 == 1 else col_dest - 1):
        ruta.append((0, c))
    for f in range(1, fila_dest + 1):
        ruta.append((f, col_dest - 1 if col_dest % 2 == 1 else col_dest + 1))
    ruta.append(destino)
    return ruta

def main():
    mapa = crear_mapa()
    while True:
        mostrar_mapa(mapa, registro_vehiculos)
        print("Opciones:")
        print("1. Ingresar vehículo")
        print("2. Verificar tiempos y retirar excedidos")
        print("3. Calcular costo, mostrar ruta y retirar vehículo")
        print("4. Salir")
        opcion = input("Seleccione opción: ")

        if opcion == '1':
            placa = input("Ingrese placa: ").upper()
            try:
                fila = int(input("Fila (0-7): "))
                col = int(input("Columna (0-7): "))
                tiempo_perm = int(input("Tiempo estimado de permanencia en minutos: "))
                if not espacio_disponible(mapa, fila, col):
                    print("Posición ocupada o inválida.")
                    time.sleep(1.5)
                    continue
                ingresar_vehiculo(mapa, placa, fila, col, tiempo_perm)
            except:
                print("Entrada inválida.")
            time.sleep(1.5)

        elif opcion == '2':
            verificar_tiempos(mapa)

        elif opcion == '3':
            placa = input("Ingrese placa para calcular costo, mostrar ruta y retirar: ").upper()
            if placa in registro_vehiculos:
                costo = calcular_costo(placa)
                print(f"Costo a pagar para {placa}: ${costo:.2f}")
                ruta = generar_ruta(mapa, registro_vehiculos[placa]['posicion'])
                mostrar_mapa(mapa, registro_vehiculos, ruta)
                input("Presione Enter para retirar...")
                retirar_vehiculo(placa)
            else:
                print("Placa no encontrada.")
            time.sleep(2)

        elif opcion == '4':
            print("Gracias por usar el sistema.")
            break

        else:
            print("Opción inválida.")
            time.sleep(1.5)

if __name__ == '__main__':
    main()
