
#pragma once 


typedef enum etype { arrival, departure } EventType;


// Desc:  Represents a simulation event
class Event {
    private:
        int time;
        int length;
        EventType type;
    public:
        // default Constructor
        Event();

        // Non-default Constructor
        Event(const int& t, const int& l, const EventType& tp);

        // getter of time 
        int GetTime () const;

        // getter of length
        int GetLength () const;

        // getter of type
        EventType GetType () const;

        // Setter of Time
        void SetTime (const int& t);

        // Setter of Length
        void SetLength (const int& l);

        // Setter of Type
        void SetType (const EventType& tp);

        // Overload << operator
        friend ostream& operator << (ostream& outs, const Event& e);  

        // Desc:  Comparators
        bool operator<(const Event &r) const { return /* complete this */ ; };
        bool operator>(const Event &r) const { return /* complete this */ ; };
        bool operator<=(const Event &r) const { return /* complete this */ ; };
        bool operator>=(const Event &r) const { return /* complete this */ ; };


}; // Event

