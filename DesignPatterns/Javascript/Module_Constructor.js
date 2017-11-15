var myModule = (function(){ // creating a new context 
	var privateVar1 = "Some value" , privateVar2 = "Some value 2";
	var _self ;// using self to attach variables to constructor because if the attach a variable in a private function
	//the context of the function will change ;

	function privateFunction(){
		_self.privateFuncVar = "some public value attached to the context of the contructor function " + privateVar1 +  privateVar2;
		console.log("private function call");
	}

	function constructorFunction(passedValue){
		_self = this;
		this.constVar = "Constructor function var"||passedValue;
		console.log("Constructor function call");
		privateFunction();
	}

	return constructorFunction;

})();

myModule.prototype.protoFunction1= function(){
	return "this is a prototype function , you can attach other functions too ! ";
}

var obj = new myModule("Some passed value");
console.log(obj.protoFunction1());

//below will drop errors
// console.log(obj.privateFunction()); 
// console.log(obj.privateVar2);
// console.log(obj.privateVar2);
