let Publisher = (function(){ // publishes articles , generic template
    
    function Publisher(){
        this._listOfSubscriber = {}; // this will contain the list of subscribers
    }

    //adding subscribers to the _listofsubscribers
    Publisher.prototype.subscribe = function(fn=[],event){
        event = event || "random event";
        fn = (fn.constructor !== Array) ? [fn] : fn;
        if(this._listOfSubscriber[event] === undefined){
            this._listOfSubscriber[event] = [];
        }
        this._listOfSubscriber[event].push(...fn);
    }

    //unsubscribing  a subscriber
    Publisher.prototype.unsubscribe = function(fn,event){
        this._listOfSubscriber[event] = this._listOfSubscriber[event].filter(function(item){
            if(item !== fn)
                return item;
        })
    }

    //publishing an event
    Publisher.prototype.publish = function(event,message=""){
        var subscribers = this._listOfSubscriber[event] || [];
        subscribers.forEach((subscriber)=>{
            subscriber(event + " : " + message);
        })
    }
    

    return Publisher;
})();

let TvAgency = {
    //triggers publish
    reviews: [],
    broadcastShow: function(show){
        this.publish(show, " is being broadcasted !");
    },
    getFeedBack: function(message){
        alert("Someone tweeted about the show");
        this.reviews.push(message);
        this.reviews.forEach(function(review){
            console.log(review);
        });
    }
}

//make any object into a publisher
let makePublisher = function(obj){
    Publisher.call(obj);
    obj.__proto__ = Object.create(Publisher.prototype);  
}

//make TvAgency a publisher
makePublisher(TvAgency);

// these are the subcribers
let Joe = {
    watching: function(msg) {
        console.log(msg);
    },
    tweetAboutShow: function(show,emotion){
        this.publish("got",show+ " " +emotion);
    }
}

//now joe can also publish
makePublisher(Joe);

//subscribe an array to TvAgency
TvAgency.subscribe([Joe.watching],"got");
//TvAgency.unsubscribe(joe,"got");
TvAgency.broadcastShow("got");

//Tv agency has subscribed to joe incase he tweets something
Joe.subscribe(TvAgency.getFeedBack.bind(TvAgency),"got");

Joe.tweetAboutShow("Game of thrones","suck");