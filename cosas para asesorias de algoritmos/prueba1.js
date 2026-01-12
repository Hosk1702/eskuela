const { Console } = require('console');
const { normalize } = require('path');
const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin, output: process.stdout
});

class player {
    constructor(name, score) {
        this.name = name;
        this.score = score;
    }
}

let lista_jugadores = [];

function main(){
    let nombre = "";
    let score = 0;
    console.log("***ORDENADOR DE PUNTAJES DEL TORNEO***.");
    rl.question( "\nIngresa el nombre del jugador: ",(input) => {
        nombre = input;
        obtener_puntaje(score,nombre);
    });

    
};

function obtener_puntaje(score,nombre){
    rl.question( "\nIngresa el puntaje del jugador: ",(input) => {
    score = parseInt(input);
    if (score > 1000) {
        console.warn('\nEl puntaje no puede ser mayor a 1000')
        obtener_puntaje(score,nombre);
    }
    finalizar(nombre, score);
    });
}

function finalizar(nombre,score){
    console.log("\nDesea ingresar otro jugador? (si/no)");
    let respuesta = "";
    rl.question("", (input) => {
        respuesta = input;
        let j = new player(nombre, score);
        lista_jugadores.push(j);
        
        if(respuesta.toLowerCase() === "si"){
            main();
        }else{
            ordenar();
        }
    });
}

function ordenar(){
    for(let i = 0 ; i < (lista_jugadores.length); i++){
        console.table(lista_jugadores[i]);
    }
    let prom = promediar();
    console.log(`\nEl puntaje promedio del torneo es: ${prom}`);
    rl.close();
}

function promediar(){
    let prom
    for(let i = 0 ; i < (lista_jugadores.length); i++){
prom += lista_jugadores[i].score;
    }
    return prom/lista_jugadores.length;
}



main();