
#include "Event.h"

Event::Event()
{
    this->time = 0;
    this->length = 0;
}

Event::Event(const int& t, const int& l, const EvenType& tp)
{
    this->time = t;
    this->length = l;
    this->type = tp;
}

int Event::GetTime() const
{
    return this->time;
}

int Event::GetLength() const
{
    return this->length;
}

EvenType Event::GetType()const
{
    return this->type;
}

void Event::SetTime(const int& t)
{
    this->time = t;
}

void Event::SetLength(const int& l)
{
    this->length = l;
}

 void Event::SetType (const EventType& tp)
 {
    this->type = tp;
 }

ostream& operator << (ostream& outs, const Event& e)
 {
    if(e.type == arrival)
        outs << "Arrival Event ";
    else
        outs << "Departure Event ";
    outs << e.time;
    outs << e.length;
    return outs;
 }
