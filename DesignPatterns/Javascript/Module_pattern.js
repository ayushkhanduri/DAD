//There are several different ways of implementing modules , he i am using "Object literal notation"

var myModule = {
	name: "Animation Module",

	animationSpeed: 100, // setting up default value

	config: function(animationSpeed , animationSet){
		var CONSTANT= 200; // this is private to this function
		this.animationSpeed = animationSpeed;
		this.animationSet = animationSet;
	},

	//custom made events that can be called whenever an animation occurs
	events: {
		animationStart: function(){
			console.log("Animation Start");
		},
		animationEnd: function(){
			console.log("Animation End");
		}
	},


	slideUp: function(){
		this.events.animationStart();
		console.log("Slide up animation logic");
		this.events.animationEnd();
	}
}

myModule.config(500, ["slideUp"]);
myModule.slideUp();

console.log(myModule);