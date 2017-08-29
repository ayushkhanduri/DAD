class Parent {
	constructor(pName){
		this.pName = pName;
	}

	screamParentName(){
		console.log(this.pName);
	}
}

class Son extends Parent {

	constructor(sName,pName){
		super(pName);
		this.sName = sName;
	}

	screamSonName() {
		console.log(this.sName);
	}
}

let x = new Son("ayush", "hp");
console.log(x);