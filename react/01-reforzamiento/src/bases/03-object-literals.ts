interface Person {
    firstName: string;
    lastName: string;
    age: number;
    address: Address;
}

interface Address {
    city: string;
    zipCode: string;
}


const ironman : Person  = {
    firstName: 'Marco',
    lastName: 'Velazquez',
    age: 45,
    address:{
        city: 'New York',
        zipCode: '10239'
    }
}

const spiderman : Person = {
    firstName: "",
    lastName: "",
    age: 0,
    address:{
        city: "",
        zipCode: ""
    }
}

//spread
//const spiderman = {...ironman};//lo que hacen los ... es decirle que
                                // todas las propiedades de ironman pasen a spiderman
                                //sin apuntar al mismo espacio en memoria

const laMole = structuredClone(ironman);
//Lo que hace es pasar todas las referencias y permitir
//romper las de todos los niveles en vez de spread que solo
//rompe la del primer nivel. esto permite modificar objetos dentro
//dentro de objetos sin que se vea afectado el objeto original
spiderman.firstName = 'Peter';
spiderman.lastName = 'Parker';
spiderman.age = 22;

laMole.address.city = 'ahome';
laMole.address.zipCode = '19203';

console.log(ironman, spiderman, laMole);