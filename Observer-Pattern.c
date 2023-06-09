
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


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SUBSCRIBERS 10

typedef struct Subs{
    char name[20]; // has a name
    void (*update)(); // update
} Subs;   // This is the observer

typedef struct Channel{
    Subs Subscriber;
    int num_subscribers;
    void (*subscribe)(); //subscribe
    void (*unsubscribe)(); //unsub
    void (*upload)(); //upload a vid more like notify
} Channel; // This is the subject

typedef struct concreteSubs{ // concrete observer with base
    Subs b;
}concreteSubs;

void concretesub_update()
{
    printf("received a message......."); // receives text if subject has uploaded something works like an update to subscriber
}

typedef struct concreteChannel{  //concrete subject with base
    Channel b;
}concreteChannel;

void concretechannel_subscribe()
{
    printf("Subscribed to the channel\n"); //check if subscribed to channel
}

void concretechannel_unsubscribe()
{
    printf("UnSubscribed from the channel, Please subscribe!\n");  //check if unsub
}

void concretechannel_upload(Channel* c)
{
    if(concretechannel_subscribe)
    {
       concretesub_update();
       printf("New video is uploading soon!!");
    }
}

int main()
{
    concreteChannel channel;
    concreteSubs sub1;
    concreteSubs sub2;
    channel.b.subscribe = &concretechannel_subscribe;
    channel.b.unsubscribe = &concretechannel_unsubscribe;
    channel.b.upload = &concretechannel_upload;
    
    int t;
    scanf("%d",&t);
    switch(t % 2)
    {
        // case 0 : concretechannel_subscribe();
        //          concretesub_update();
        //          concretechannel_upload();
        case 0:  printf("%c",sub1);
                 channel.b.subscribe();
                 channel.b.upload();
                 break;
        case 1 : channel.b.unsubscribe();
                 break;
        default: exit(1);
    }    
    return 0;
}









