function Vehicles(vName,topSpeed,automatic){
	this.vName = vName || "";
	this.topSpeed = topSpeed || 50;
	this.automatic = automatic || false;
}

Vehicles.prototype.describeVehicle = function(){
	return "The vehicle " + this.name + " has a top speed of " + this.topSpeed + 
	((this.automatic) ? " and is automatic." : " and is not automatic ");
}

function Car(cName,vName,topSpeed,automatic){
	Vehicles.call(this,vName,topSpeed,automatic);
	this.cName = cName;
}

Car.prototype = Object.create(Vehicles.prototype);
//Car.prototype = new Vehicles(vName, topSpeed, automatic); //this would also work but would create data_items in the lower prototype chain
Car.prototype.constructor = Car;

Car.prototype.describeCar = function(){
	return this.cName;
}

var x = new Car("Verna" ,"Toyot", 200, true);

console.log(x);