# Explicacion de conceptos usados en el codigo
## Innovaviones incluidas
En este proyecto se trabajaron cuatro innoaviones principales
la primera de ellas es incluir la tabla de tipos, esto para poder dar realismo al tipo de batalla pokemon ya que en la realidad se usan disitntas efectividades segun de que tipo sea el ataque y de que toipo sea el pokemon que reciba el ataque, esto se considera necesario ya que permite tener un mayor analisis en cuanto a los ataque que va a alanzar el jugador ademas de tener mas afinidad a la realidad del juego. Esta implementacion se llevo a cabo por medio de funciones if en las cuales el retorno es un multiplicador de daño el cual afecte segun el tipo del pokemon, como se muestra en el siguiente ejemplo:

if (attackType == FIRE) {

if (defenseType == GRASS || defenseType == STEEL) return 2.0;

if (defenseType == WATER || defenseType == FIRE || defenseType == DRAGON) return 0.5;

Otra innovacion incluida en este proyecto es la inclucion de los tipos pokemon los cuales son asignados a los pokemon incluidos en las elecciones para poder tener la efectividad de la tabla de tipos, ademas de esta innovacion tambien se incluyeron 6 pokemones ( Umbreon, Garchomb, Rayquaza, Metagross, Sceptile y Charizard) cada uno de ellos con ataques diferentes los cuales en funcion de la tabla de tipos hacen mas daño o menos daño, esto dependiendo de la clasificacion de tres tipos, eficas donde el multiplicador es por 1.0, en el caso de que sea poco eficas se multiplicara el daño base del ataque por 0.5 y si es supereficaz se multiplica por 2.0, en cuanto a la batalla se muestra una batalla con cambios en cuanlquier momento al pokemon que este en batalla por el segundo pokemon del equipo, estos dos pokemones se eligen al principio de la battalla con un menu interactivo. El daño a medida que la batalla va pasando se muestra despues de cada ataque por lo cual se tiene la informacion de la batalla demas de cuanto daño hace cada uno de los pokemones.
## Librerias incluidas
## Iostream
Permite la entrada y salida estándar.
## String
Proporciona la clase std::string para manipular cadenas de texto.
## Vector
Permite el uso de la clase std::vector, que es una estructura de datos dinámica para almacenar colecciones de elementos.
## Enum: Definición de tipo a cadena
Las enumeraciones (enum) se utilizan para definir un conjunto de constantes con nombre. Esto mejora la legibilidad del código y permite trabajar con valores simbólicos en lugar de números mágicos, ademas la enumeración Type en la linea 7 define los diferentes tipos de Pokémon. Cada tipo se representa como un valor entero, lo que permite una fácil comparación y uso en el código.
## Función toString
La función toString se utiliza para convertir un valor de tipo enumerado en una cadena de texto. Esto es útil para mostrar información al usuario o para depuración. Para ser mas entendible y aplicado al codigo La función toString toma un valor de tipo TipoPokemon y devuelve su representación en forma de cadena. Utiliza una declaración switch para determinar qué cadena devolver.
## Bool
bool es un tipo de dato que puede tener uno de dos valores: true (verdadero) o false (falso). Se utiliza para representar condiciones lógicas y controlar el flujo del programa, como verificar si un Pokémon está vivo o si una acción es válida.    
## Struct
struct es una palabra clave que se utiliza para definir una estructura de datos. Una estructura puede contener diferentes tipos de datos agrupados bajo un mismo nombre, lo que permite crear tipos de datos compuestos que representan entidades más complejas, como un ataque de Pokémon.    
## Función typeEffectiveness
Esta función calcula la efectividad de un ataque basado en el tipo del ataque y el tipo de defensa. Devuelve un valor que indica si el ataque es efectivo, poco efectivo o no efectivo.   
## Estructura Attack
La estructura Attack define un ataque de Pokémon, que incluye su nombre, tipo y poder. Esto permite crear objetos que representan ataques específicos.   
## Switch
switch es una declaración de control de flujo que permite seleccionar una de varias opciones basadas en el valor de una variable. Es una alternativa a múltiples declaraciones if y se utiliza para ejecutar diferentes bloques de código según el valor de la variable evaluada.    
## class
class es una palabra clave que se utiliza para definir una clase en programación orientada a objetos. Una clase es un modelo que encapsula datos y funciones que operan sobre esos datos, permitiendo crear objetos que representan entidades del mundo real, como un Pokémon.    
## Void
void es un tipo de retorno que indica que una función no devuelve ningún valor. Se utiliza para funciones que realizan acciones, como mostrar información o modificar el estado de un objeto, sin necesidad de retornar un resultado.    
## &
El símbolo & se utiliza en C++ para declarar referencias. Una referencia es un alias para una variable existente, lo que permite acceder a la variable original sin crear una copia. Esto es útil para pasar objetos a funciones sin incurrir en el costo de copia.   
## ||
El operador || es un operador lógico que representa la disyunción (OR). Se utiliza para combinar dos condiciones booleanas y devuelve true si al menos una de las condiciones es verdadera. Es útil en expresiones condicionales para evaluar múltiples criterios. 
# Atk.type
atk.type se refiere al atributo type de un objeto Attack. Este atributo indica el tipo del ataque, que puede ser uno de los tipos enumerados definidos en el programa. Se utiliza para determinar la efectividad del ataque en función del tipo del Pokémon defensor.    
## Opponent.type
opponent.type se refiere al atributo type de un objeto Pokemon que representa al oponente. Este atributo indica el tipo del Pokémon oponente, que se utiliza para calcular la efectividad de los ataques que recibe.   
## Static_cast
static_cast es un operador de conversión de tipo en C++. Se utiliza para convertir un tipo de dato a otro de manera segura y explícita. Es útil cuando se necesita cambiar el tipo de una variable, como convertir un valor de punto flotante a un entero.    
## DisplayPokemonOptions
displayPokemonOptions es una función que muestra las opciones de Pokémon disponibles para que el jugador seleccione. Presenta información sobre cada Pokémon, como su nombre y tipo, facilitando la elección del jugador.    
## Vector
vector es una clase de la biblioteca estándar de C++ que proporciona una estructura de datos dinámica para almacenar colecciones de elementos. Permite agregar, eliminar y acceder a elementos de manera eficiente, y su tamaño puede cambiar dinámicamente durante la ejecución del programa.   
## swap
swap es una función que intercambia los valores de dos variables. En el contexto de estructuras de datos, se utiliza para cambiar la posición de elementos o para alternar entre dos objetos, como en el caso de cambiar el turno entre dos equipos de Pokémon.    










