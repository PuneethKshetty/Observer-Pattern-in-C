
//Points :
// Observer pattern move from pull(Have you changed) to push(When you done with changes) architecture

// 1. All observers needs to register to the subject(observable)
// 2. One to many relationships or dependancy between objects (If subject changes state all of its dependants are notified they update automatically) 
// 3. -> has a 
// closed arrow - is a

// Subject -> Interface (Iobservable) (1)-------->(Many(*)) Observer -> Interface (IObserver)
// add(Iobserver)	-> registering					
// remove(Iobserver)
// notify() -> by calling update

// Concrete Observable implements Iobservable(Subject) -> implement add(Iobservable),remove(Iobservable),notify()  |  getState()
// Concrete Observer implements Iobserver(Observer) -> implement update()

// Concrete observer has a (->) reference to concrete Observable ->allows access

// Implementation
// Interface Iobservable
// add(),remove(),notify()

// Interface Iobserver
// update()

// class WeatherStation : Iobservable{
// add method(Iobserver O)
// {
// 	this.observer.add(o);
// }
// notify()  { [foreach[Iobserver o in this.obersvers){
// o.update();
// }
// }

// int getState(){
// return this.state;
// }
// }

// class PhoneDisplay:Iobserver{
// 	weatherStation station //instances
// 	phonedisplay(WeatherStation station) //constructor
// 	{
// 		this.station = station;
// 	}

// 	void update()
// 	{
// 	   this.station.getState(); (above instANCE)
// 	}

// }
