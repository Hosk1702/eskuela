class trainer {
    constructor ({
        name,
        age,
        team = [],
        pokedex = 0
    }){
        this.name = name;
        this.age = age;
        this.team = team;
        this.pokedex = pokedex;
    }

    AddTeamMember(pokemon){
        this.team.push(pokemon);
    }
};

const ash = new trainer({
    name : 'Ash',
    team: ['charmander', 'squirtle'],
    pokedex: 151,
    age: 10
});

console.log(ash);

ash.AddTeamMember('Pikachu');

console.log(ash);