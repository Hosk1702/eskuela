const myArray:(number|string)[] = [1,2,3,4,'5'];

const myArray2 = structuredClone(myArray);

myArray.push(2);
myArray2.push('2');

console.log(myArray,myArray2);