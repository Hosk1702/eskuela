const Ash = {
    name: "Ash Ketchum",
    age: 10,
    pokedex: 120,
    team: [
        'Pikachu',
        'Bulbasaur',
        'Charizard',
    ],
    AddTeamMember(pokemon){
        this.team.push(pokemon);
    }
};

function trainer(name,age,team){
    this.name = name,
    this.age = age,
    this.team = team
}

trainer.prototype.AddTeamMember = function(pokemon){
    this.team.push(pokemon);
}

const gary = new trainer(
    'gary',
    10,
    ['Charmander','Pidgey']
);

gary.AddTeamMember('Abra');

console.table(gary);
console.table(Ash);