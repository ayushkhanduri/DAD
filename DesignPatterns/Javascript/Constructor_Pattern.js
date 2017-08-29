function Vehicles(name,topSpeed,automatic){
	this.name = name || "";
	this.topSpeed = topSpeed || 50;
	this.automatic = automatic || false;
}

Vehicles.prototype.describeVehicle = function(){
	return "The vehicle " + this.name + " has a top speed of " + this.topSpeed + 
	((this.automatic) ? " and is automatic." : " and is not automatic ");
}

var x = new Vehicles("Toyot", 200, true);

console.log(x);