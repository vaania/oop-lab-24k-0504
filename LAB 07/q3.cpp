#include "iostream"
using namespace std;

class Ticket{
    public:
    int TicketID;
    string passengerName;
    int price;
    string date;
    string destination;
    Ticket(int id, string name, int p, string d, string dest): TicketID(id), passengerName(name), price(p), date(d), destination(dest){}
    
    virtual void reserve(){
        cout<<"\nTicket reserved for"<<passengerName<<endl;
    }
    
    virtual void cancel(){
        cout<<"\nTicket cancelled for"<<passengerName<<endl;
    }
    
    virtual void displayTicketInfo(){
        cout<<"\nTicket ID: "<<TicketID<<"\nPassenger Name: "<<passengerName<<"\nPrice: $"<<price<<"\nDate: "<<date<<"\nDestination: "<<destination<<endl;
    }
};

class FlightTicket : public Ticket{
    public:
    string airlineName;
    int flightNumber;
    string seatClass;
    FlightTicket(int id, string name, int p, string d, string dest, string airline, int flightNum, string seat): Ticket(id, name, p, d, dest), airlineName(airline), flightNumber(flightNum), seatClass(seat){}
    
    void displayTicketInfo()override{
        Ticket::displayTicketInfo();
        cout<<"Airline Name: "<<airlineName<<"\nFlight Number: "<<flightNumber<<"\nSeat Class: "<<seatClass<<endl;
    }
};
static int x=0;
class TrainTicket : public Ticket{
    public:
    int trainNumber;
    string coachType;
    string departureTime;
    TrainTicket(int id, string name, int p, string d, string dest, int trainNum, string coach, string dt): Ticket(id, name, p, d, dest), trainNumber(trainNum), coachType(coach), departureTime(dt){}
    
    void reserve()override{
        x++;
        cout<<"Seat "<<x<<" reserved for "<<passengerName<<endl;
    }
};

class BusTicket : public Ticket{
    public:
    string busCompany;
    int seatNumber;
    BusTicket(int id, string name, int p, string d, string dest, string busComp, int seat): Ticket(id, name, p, d, dest), busCompany(busComp), seatNumber(seat){}
    
    void cancel()override{
        cout<<"Ticket cancelled. Refund issued"<<endl;
    }
};

class ConcertTicket : public Ticket{
    public:
    string artistName;
    string venue;
    string seatType;
    ConcertTicket(int id, string name, int p, string d, string dest, string artist, string venue, string seat): Ticket(id, name, p, d, dest), artistName(artist), venue(venue), seatType(seat){}
    
    void displayTicketInfo() override{
        Ticket::displayTicketInfo();
        cout<<"Artist Name: "<<artistName<<"\nVenue: "<<venue<<"\nSeat Type: "<<seatType<<endl;
    }
};

int main(){
    FlightTicket f(101, "Shehzad Ali", 20000, "2025-12-24", "Turkey", "AirBlue", 246, "Business");
    TrainTicket t(102, "Fatima Azhar", 4000, "2025-06-20", "Rawalpindi", 1031, "AC Sleeper", "11 AM");
    BusTicket b(103, "Vaania Ahmed", 5000, "2025-04-29", "Karachi", "Faisal Movers", 2);
    ConcertTicket c(104, "Abeer Fatima", 6000, "2025-05-30", "Karachi", "Atif Aslam", "Mashion Bazaar", "VIP");
    f.reserve();
    t.reserve();
    b.reserve();
    c.reserve();

    f.displayTicketInfo();
    t.displayTicketInfo();
    b.displayTicketInfo();
    c.displayTicketInfo();

    f.cancel();
    t.cancel();
    return 0;
}