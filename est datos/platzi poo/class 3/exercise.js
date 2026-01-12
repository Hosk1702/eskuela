class Banda {
    constructor({
        name,
        generos = []
    }){
        this.name = name;
        this.generos = generos;
        this.integrantes = []
    }

    AddMember(NewMember){

        for(let i = 0; i < (this.integrantes.length); i++){
            if(this.integrantes[i].instrument === NewMember.instrument){
                console.error(`Error al agregar el miembro ya existe un miembro con el instrumento ${NewMember.instrument}`)
                return;
            }
        }
        this.integrantes.push(NewMember);
    }
}

class Member {
    constructor({
        name,
        instrument
    }){
        this.name = name;
        this.instrument = instrument;
    }
}

const data = {
    name: 'La panzonita de aguascalientesssnnn',
    generos: ['Banda', 'Pop', 'Rock']
}

const banda = new Banda(data)
banda.AddMember(
    new Member({name: 'Pedro', instrument: 'Guitarra'})
)
banda.AddMember(new Member({name: 'Pablo', instrument: 'Acordeon'}))
   
banda.AddMember(new Member({name: 'paul', instrument: 'Acordeon'}))
console.log(banda)