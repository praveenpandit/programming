class Animal {
    constructor(name) {
        this.name = name;
        this.speed = 0;
    }
    run(speed) {
        this.speed = speed;
        console.log(`${this.name} runs with speed ${this.speed}.`);
    }
    stop() {
        this.speed = 0;
        console.log(`${this.name} stands still.`);
    }
}
class Rabbit extends Animal {
    hide() {
        console.log(`${this.name} hides!`);
    }
}
let animal = new Rabbit("My animal");
animal.hide()