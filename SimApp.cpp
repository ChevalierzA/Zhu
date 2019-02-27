
#include "Queue.h"
#include "Event.h"
#include "PriorityQueue.h"
#include "EmptyDataCollectionException.h"

#include <iostream>
bool tellerAvaliable = true;
int currentTime = 0;
int departureTime = 0;

using namespace std;
template <class T>
void processArrival(Event& e, PriorityQueue<T>& eventQ, Queue<T>& bankLine)
{
	eventQ.dequeue();
	Event customer(e.GetTime(),e.GetLength(),e.GetType());
	if (bankLine.isEmpty() && tellerAvaliable)
	{
		departureTime = currentTime + e.GetLength();
		Event newDep(departureTime, 0, departure);
		eventQ.enqueue(newDep);
		tellerAvaliable = false;
	}
	else
		bankLine.enqueue(customer);
}
template <class T>
void processDeparture(Event& e, PriorityQueue<T>& eventQ, Queue<T>& bankLine)
{
	eventQ.dequeue();
	if (!bankLine.isEmpty())
	{
		Event customer = bankLine.peek();
		bankLine.dequeue();
		departureTime = currentTime + customer.GetLength();
		Event newDep(departureTime, 0, departure);
		eventQ.enqueue(newDep);
	}
	else
		tellerAvaliable = true;
}

int main () {
	Queue<Event> bankLine;
	PriorityQueue<Event> priorityQ;

	while (!EOF)
	{
		int aT, tT; //int arrival time and transaction time.
		cin >> aT >> tT;
		Event newAr(aT, tT, arrival);
		priorityQ.enqueue(newAr);
	}
	while (!priorityQ.isEmpty())
	{
		Event newEvent = priorityQ.peek();
		currentTime = newEvent.GetTime();
		if (newEvent.GetType() == arrival)
			processArrival(newEvent, priorityQ, bankLine);
		else
			processDeparture(newEvent, priorityQ, bankLine);
	}

	return 0;
} // main

