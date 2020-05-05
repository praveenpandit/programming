class LinkedlistNode {
    constructor(data) {
        this.data = data
        this.next = null
    }
}

const head = Symbol('head')

class Linklist {
    constructor() {
        this[head] = null
    }

    add(data) {
        const newNode = new LinkedlistNode(data)
        if (this[head] === null) {
            this[head] = newNode
        } else {
            let current = this[head]
            while (current.next !== null) {
                current = current.next
            }
            current.next = newNode
        }
    }
    // display() {
    //     let current = this[head]
    //     var result = ''
    //     while (current !== null) {
    //         result += current.data + '->'
    //         current = current.next
    //     }
    //     console.log(result + 'NULL')
    // }
    // * value() {
    //     let current = this[head]
    //     while (current !== null) {
    //         yield current.data
    //         current = current.next
    //     }
    // }
    *[Symbol.iterator]() {
        // return this.value()
        let current = this[head]
        while (current !== null) {
            yield current.data
            current = current.next
        }
    }
}

const list = new Linklist
const list1 = new Linklist

list.add('yellow')
list.add(100)
// for (const data of list) {
//     console.log(data)
// }
const array = [...list]
const array1 = [...list1]
console.log(array)
console.log(array1)
// list.display()