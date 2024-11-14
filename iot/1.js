class student {
    constructor(name, rollNumber){
        this.name = name;
        this.rollNumber = rollNumber;
    }
    displayDetails(){
        console.log(`Name: $(this.name)`);
        console.log(`Roll Number: ${this.rollNumber}`);
    }

}
const student1 = new student('Alice','1234');
student1.displayDetails();