// se pone para explicarnos el codigo a nosotrs mismos :)
#include <iostream>
#include <string>
#include <vector> // esta libreria se usa para usar vectores y poder guardar los ataques de los pokémon

using namespace std;
enum Type { // en este caso enum se usa para definir los tipos de pokémon pero no se cuentan como un tipo de variable clara sino es una lista de sin tipos de variables
    NORMAL,
    FIRE,
    WATER,
    GRASS,
    ELECTRIC,
    DRAGON,
    DARK,
    STEEL,
    FLYING,
    GROUND,
    NONE
};

string typeToString(Type t) { // esta función se usa para convertir el tipo de pokémon a un string para que se pueda imprimir y se trabaja con la t para identificar el tipo de pokémon
    switch (t) {
        case NORMAL: return "Normal";
        case FIRE: return "Fuego";
        case WATER: return "Agua";
        case GRASS: return "Planta";
        case ELECTRIC: return "Eléctrico";
        case DRAGON: return "Dragón";
        case DARK: return "Siniestro";
        case STEEL: return "Acero";
        case FLYING: return "Volador";
        case GROUND: return "Tierra";
        default: return "Desconocido";
    }
}

double typeEffectiveness(Type attackType, Type defenseType) { // se declara la función para calcular la efectividad del ataque y defensa
    if (attackType == NONE || defenseType == NONE) return 1.0;// si el ataque o defensa no tiene tipo o no se menciona se devuelve 1.0 ya que seria neutro, en el caso de que sea 2.0 es pq es efectivo y 0.5 es pq no es efectivo
// || se usa para saber si el ataque o defensa no tiene tipo o no se menciona y para añadir una condicion mas a la funcion
    if (attackType == FIRE) {
        if (defenseType == GRASS || defenseType == STEEL) return 2.0;
        if (defenseType == WATER || defenseType == FIRE || defenseType == DRAGON) return 0.5;
    } else if (attackType == WATER) {
        if (defenseType == FIRE || defenseType == GROUND) return 2.0;
        if (defenseType == WATER || defenseType == GRASS || defenseType == DRAGON) return 0.5;
    } else if (attackType == GRASS) {
        if (defenseType == WATER || defenseType == GROUND) return 2.0;
        if (defenseType == FIRE || defenseType == GRASS || defenseType == DRAGON || defenseType == STEEL) return 0.5;
    } else if (attackType == ELECTRIC) {
        if (defenseType == WATER || defenseType == FLYING) return 2.0;
        if (defenseType == GRASS || defenseType == ELECTRIC || defenseType == DRAGON) return 0.5;
        if (defenseType == GROUND) return 0.0;
    } else if (attackType == DRAGON) {
        if (defenseType == DRAGON) return 2.0;
        if (defenseType == STEEL) return 0.5;
    } else if (attackType == DARK) {
        if (defenseType == DARK) return 0.5;
        return 1.0;
    } else if (attackType == STEEL) {
        return 1.0;
    } else if (attackType == FLYING) {
        if (defenseType == GRASS) return 2.0;
        if (defenseType == ELECTRIC || defenseType == STEEL) return 0.5;
    } else if (attackType == GROUND) {
        if (defenseType == FIRE || defenseType == ELECTRIC || defenseType == STEEL) return 2.0;
        if (defenseType == GRASS) return 0.5;
        if (defenseType == FLYING) return 0.0;
    }

    return 1.0;
}

struct Attack { // struct es una funcion que se usa para definir una estructura de datos, en este caso se usa para definir los ataques de los pokémon pero siempre so distintos tipos de variables y se unej por medio de etsa funcion
    string name;
    Type type;
    int power;
    Attack(string n, Type t, int p) : name(n), type(t), power(p) {}
};

class Pokemon { //se usa class para definir una clase, en este caso se usa para definir los pokémon y sus atributos, se usa como un mlde para crear obje tos de pokémon
public:
    string name;//nombre pokémon
    Type type; //tipo pokémon
    int health; //vida actual
    int maxHealth; //vida máxima
    vector<Attack> attacks; //ataques disponibles

    Pokemon(string n, Type t, int h, vector<Attack> a) // el string n es el nombre del pokémon, el tipo t es el tipo de pokémon, la h es la vida actual y la maxHealth es la vida máxima y los ataques son los ataques disponibles
        : name(n), type(t), health(h), maxHealth(h), attacks(a) {}

    bool isAlive() const { // se usa para saber si el pokémon esta vivo o no por medio de el bool el cual sirve para ller datos mas no para modificarlos
        cout << name << " tiene " << health << "/" << maxHealth << " HP." << endl;
        if (health == 0) {
            cout << name << " ha sido debilitado!" << endl;
        }
        return health > 0;
    }

    void attack(Pokemon &opponent, int attackIndex) { // se usa para atacar a otro pokémon, el primer argumento es el pokémon al que se va a atacar y el segundo es el ataque que se va a usar
        Attack &atk = attacks[attackIndex];// se usa el & para que no se haga una copia del ataque sino que se use el ataque original ademas de usar el attackIndex para saber que ataque se va a usar
        double effectiveness = typeEffectiveness(atk.type, opponent.type); // se usa la funcion de efectividad para saber si el ataque es efectivo o no por medio de la tabla de tipos que se hizo antes
        int damage = static_cast<int>(atk.power * effectiveness);// en este caso el estatic_cast se usa para convertir el valor de la potencia del ataque a un entero para que no haya problemas de tipo de dato
        if (damage < 0) damage = 0;

        opponent.health -= damage; // se le resta el daño al pokémon oponente
        if (opponent.health < 0) opponent.health = 0; // si la vida del oponente es menor a 0 se pone en 0

        cout << name << " usa " << atk.name << " (Tipo " << typeToString(atk.type)// se usa la funcion de tipo a string para que se imprima el tipo del ataque 
             << ") y hace " << damage << " de daño a " << opponent.name << "." << endl; // se imprime el ataque que se uso y el daño que hizo
        if (effectiveness == 0.0) // se usa para saber si el ataque no le hizo nada al oponente osea que es inmune
            cout << "No afecta a " << opponent.name << "!" << endl;
        else if (effectiveness > 1.0) // se usa para saber si el ataque le hizo mucho daño al oponente
            cout << "¡Es súper efectivo!" << endl;
        else if (effectiveness < 1.0) // se usa para saber si el ataque le hizo poco daño al oponente o que es poco efectivo
            cout << "No es muy efectivo..." << endl;
    }

    void displayStatus() const { // se usa para mostrar el estado del pokémon, en este caso se imprime el nombre del pokémon, su tipo y su vida actual
        cout << name << " (Tipo " << typeToString(type) << ") HP: " << health << "/" << maxHealth << endl; // se usa la funcion de tipo a string para que se imprima el tipo del pokémon
    }
};

class Team { // se usa para definir el equipo de pokémon, en este caso se usa para definir el equipo del jugador y sus atributos
public:
    vector<Pokemon> pokemons; // se usa para definir los pokémon del equipo
    int activeIndex;// se usa para definir el índice del pokémon activo

    Team(const vector<Pokemon> &poks) : pokemons(poks), activeIndex(0) {}// se usa para inicializar el equipo de pokémon y el índice del pokémon activo

    Pokemon& activePokemon() {// se usa para obtener el pokémon activo del equipo
        return pokemons[activeIndex];// se usa el índice del pokémon activo para obtener el pokémon activo
    }

    bool hasAlivePokemon() const {// se usa para saber si el equipo tiene pokémon vivos
        for (const auto &p : pokemons) {// se usa el for para recorrer el vector de pokémon
            if (p.isAlive()) return true;// se usa la funcion de isAlive para saber si el pokémon esta vivo el p. es el pokémon que se esta revisando
        }
        return false;
    }

    void displayTeamStatus() const {// se usa para mostrar el estado del equipo de pokémon
        for (int i = 0; i < (int)pokemons.size(); i++) { 
            cout << (i == activeIndex ? "> " : "  ") << (i + 1) << ". ";
            pokemons[i].displayStatus();// se usa la funcion de displayStatus para mostrar el estado del pokémon y ver si esta vivo o no
        }
    }

    bool switchPokemon(int newIndex) { // se usa para cambiar el pokémon activo del equipo 
        if (newIndex < 0 || newIndex >= (int)pokemons.size()) {
            cout << "Índice inválido." << endl;// se usa para saber si el índice es valido o no y si tiene mas de 2 pokémon o solo uno vivo
            return false;
        }
        if (newIndex == activeIndex) {
            cout << "Ese Pokémon ya está en batalla." << endl; // se usa para saber si el pokémon ya esta en batalla o no
            return false;
        }
        if (!pokemons[newIndex].isAlive()) {// se usa para saber si el pokémon esta vivo o no en el caso de que no se pueda cambiar y ademas para saber si el pokémon que se quiere cambiar es el que esta activo
            cout << "No puedes cambiar a un Pokémon debilitado." << endl;
            return false;
        }
        activeIndex = newIndex;
        cout << "Cambio a " << pokemons[activeIndex].name << "!" << endl;// se muestra el cambio de pokémon activo
        return true;
    }
};

void displayAttackMenu(const Pokemon &pokemon) { // se usa para mostrar el menu de ataques del pokémon activo
    cout << "Turno de " << pokemon.name << endl;// se imprime el turno del pokémon activo
    for (int i = 0; i < (int)pokemon.attacks.size(); i++) {
        cout << i + 1 << ". " << pokemon.attacks[i].name
             << " (Tipo: " << typeToString(pokemon.attacks[i].type)// se usa la funcion de tipo a string para que se imprima el tipo del ataque
             << ", Poder: " << pokemon.attacks[i].power << ")" << endl;// se imprime el ataque que se va a usar y su tipo y poder
    }
    cout << pokemon.attacks.size() + 1 << ". Cambiar Pokémon" << endl;// se imprime la opcion de cambiar de pokémon
    cout << pokemon.attacks.size() + 2 << ". Salir" << endl;// se imprime la opcion de salir por medio de un menu interactivo con los numeros 5 y 6
}

void displayPokemonOptions(const vector<Pokemon> &pokemons) { // se usa para mostrar las opciones de pokémon disponibles para seleccionar
    for (int i = 0; i < (int)pokemons.size(); i++) { // se usa el for para recorrer el vector de pokémon
        cout << i + 1 << ". " << pokemons[i].name << " (Tipo " << typeToString(pokemons[i].type) // se usa la funcion de tipo a string para que se imprima el tipo del pokémon
             << ", HP: " << pokemons[i].health << ")" << endl; // se imprime el nombre del pokémon, su tipo y su vida actual
    }
}

int main() {
    // Lista completa de Pokémons para seleccionar
    vector<Pokemon> allPokemons = {
        Pokemon("Umbreon", DARK, 130,
                {Attack("Dark Pulse", DARK, 30), Attack("Faint Attack", DARK, 25),// en cada uno se definen los ataques de cada pokémon y su tipo y poder
                 Attack("Swift", NORMAL, 20), Attack("Confuse Ray", NONE, 0)}),
        Pokemon("Charizard", FIRE, 120,
                {Attack("Flamethrower", FIRE, 40), Attack("Dragon Claw", DRAGON, 35),
                 Attack("Air Slash", FLYING, 30), Attack("Slash", NORMAL, 25)}),
        Pokemon("Metagross", STEEL, 150,
                {Attack("Meteor Mash", STEEL, 40), Attack("Zen Headbutt", NONE, 30),
                 Attack("Earthquake", GROUND, 35), Attack("Hammer Arm", NONE, 30)}),
        Pokemon("Rayquaza", DRAGON, 140,
                {Attack("Dragon Ascent", FLYING, 45), Attack("Dragon Claw", DRAGON, 40),
                 Attack("Extreme Speed", NORMAL, 35), Attack("Air Slash", FLYING, 30)}),
        Pokemon("Garchomp", DRAGON, 140,
                {Attack("Earthquake", GROUND, 40), Attack("Dragon Claw", DRAGON, 35),
                 Attack("Crunch", DARK, 30), Attack("Stone Edge", NONE, 35)}),
        Pokemon("Sceptile", GRASS, 115,
                {Attack("Leaf Blade", GRASS, 40), Attack("X-Scissor", NONE, 35),
                 Attack("Dragon Claw", DRAGON, 30), Attack("Double Edge", NORMAL, 40)})
    };

    cout << "Selecciona 2 Pokémon para el Equipo del Jugador 1:" << endl;
    vector<Pokemon> team1Poks;
    for (int i = 0; i < 2; i++) {
        displayPokemonOptions(allPokemons);
        int choice;// se usa para guardar la opcion que elige el jugador
        while (true) {// se usa el while para que el jugador pueda elegir un pokémon y si no es valido se le pide que elija otro
            cout << "Opción para Pokémon " << i + 1 << ": ";
            cin >> choice;
            if (choice >= 1 && choice <= (int)allPokemons.size()) { // se usa el if para saber si la opcion es valida o no y si es menor a 1 o mayor al tamaño del vector de pokémon
                team1Poks.push_back(allPokemons[choice - 1]);
                break;
            }
            cout << "Opción no válida, intenta de nuevo." << endl;
        }
    }
    Team team1(team1Poks); // se crea el equipo del jugador 1 con los pokémon seleccionados

    cout << "\nSelecciona 2 Pokémon para el Equipo del Jugador 2:" << endl;// se imprime el mensaje para que el jugador 2 elija sus pokémon
    vector<Pokemon> team2Poks;
    for (int i = 0; i < 2; i++) {
        displayPokemonOptions(allPokemons);// se usa la funcion de displayPokemonOptions para mostrar las opciones de pokémon disponibles para seleccionar
        int choice;
        while (true) {
            cout << "Opción para Pokémon " << i + 1 << ": ";
            cin >> choice;// se guarda la opcion que elige el jugador
            if (choice >= 1 && choice <= (int)allPokemons.size()) {// se usa el if para saber si la opcion es valida o no y si es menor a 1 o mayor al tamaño del vector de pokémon
                team2Poks.push_back(allPokemons[choice - 1]);
                break;
            }
            cout << "Opción no válida, intenta de nuevo." << endl;
        }
    }
    Team team2(team2Poks);

    cout << "\n¡Comienza la batalla!\n" << endl;// se imprime el mensaje de que comienza la batalla

    Team *attackerTeam = &team1;// se usa el puntero para que el jugador 1 sea el atacante
    Team *defenderTeam = &team2;// se usa el puntero para que el jugador 2 sea el defensor

    while (team1.hasAlivePokemon() && team2.hasAlivePokemon()) {// se usa el while para que la batalla continue mientras los dos equipos tengan pokémon vivos
        cout << "Equipo del jugador ACTIVO:" << endl;
        attackerTeam->displayTeamStatus();
        cout << "Equipo del jugador ENEMIGO:" << endl;
        defenderTeam->displayTeamStatus();// se usa la funcion de displayTeamStatus para mostrar el estado del equipo de pokémon
        cout << endl;

        displayAttackMenu(attackerTeam->activePokemon());
        int action;
        cout << "Elige acción: "; // se imprime el mensaje para que el jugador elija su accion
        cin >> action;

        int atkSize = (int)attackerTeam->activePokemon().attacks.size();// se guarda el tamaño del vector de ataques del pokémon activo

        if (action >= 1 && action <= atkSize) {// se usa el if para saber si la accion es valida o no y si es menor a 1 o mayor al tamaño del vector de ataques
            attackerTeam->activePokemon().attack(defenderTeam->activePokemon(), action - 1);// se usa la funcion de attack para atacar al pokémon oponente y se le pasa el índice del ataque que se va a usar

            if (!defenderTeam->activePokemon().isAlive()) {// se usa la funcion de isAlive para saber si el pokémon oponente esta vivo o no
                cout << defenderTeam->activePokemon().name << " ha sido debilitado!" << endl;// se imprime el mensaje de que el pokémon oponente ha sido debilitado
                // Intentar cambiar automáticamente a otro Pokémon vivo en defensa
                bool switched = false;// se usa el bool para saber si se cambio de pokémon o no
                for (int i = 0; i < (int)defenderTeam->pokemons.size(); i++) {// se usa el for para recorrer el vector de pokémon
                    if (defenderTeam->pokemons[i].isAlive()) {
                        defenderTeam->switchPokemon(i);
                        switched = true;
                        break;
                    }
                }
                if (!switched) {// si no se cambio de pokémon se imprime el mensaje de que no hay pokémon vivos
                    // No quedan Pokémon, gana atacante
                    cout << "¡" << attackerTeam->activePokemon().name << " y su equipo ganan la batalla!" << endl;// se imprime el mensaje de que el equipo del jugador 1 gana la batalla
                    break;
                }
            }

            // Cambiar turno
            swap(attackerTeam, defenderTeam);// se usa el swap para cambiar de turno entre los dos equipos

        } else if (action == atkSize + 1) { // Cambiar Pokémon
            cout << "Pokémons disponibles para cambio:" << endl;
            attackerTeam->displayTeamStatus();
            cout << "Elige el número del Pokémon a cambiar (o 0 para cancelar): ";// se imprime el mensaje para que el jugador elija su pokémon para cambiar
            int changeChoice;
            cin >> changeChoice;
            if (changeChoice == 0) {
                continue; // cancelar cambio
            }
            if (!attackerTeam->switchPokemon(changeChoice - 1)) {// se usa la funcion de switchPokemon para cambiar de pokémon y se le pasa el índice del pokémon que se va a cambiar
                cout << "Cambio inválido, intenta otro turno." << endl;
            } else {
                // Cambiar turno
                swap(attackerTeam, defenderTeam);
            }
        } else if (action == atkSize + 2) {
            cout << "Saliendo de la batalla." << endl;
            break;
        } else {
            cout << "Opción no válida, intenta de nuevo." << endl;
        }
        cout << endl;
    }

    if(!team1.hasAlivePokemon() && !team2.hasAlivePokemon()){
        cout << "La batalla terminó en empate." << endl;
    } else if(!team1.hasAlivePokemon()){
        cout << "El equipo del jugador 2 gana la batalla!" << endl;
    } else if(!team2.hasAlivePokemon()){
        cout << "El equipo del jugador 1 gana la batalla!" << endl;
    }

    return 0;
}
