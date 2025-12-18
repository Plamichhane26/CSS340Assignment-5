#include "Event.h"

// Constructor
Event::Event(){}

Event::Event(const std::string& name, const std::string& description, double rating, int soldTicketsCount)
    : name(name), description(description), rating(rating), soldTicketsCount(soldTicketsCount) {}

Event::~Event(){}

// Getters for member data fields
std::string Event::getName() const {
    return name;
}

std::string Event::getDescription() const {
    return description;
}

double Event::getRating() const {
    return rating;
}

int Event::getSoldTicketsCount() const {
    return soldTicketsCount;
}

// Setters for member data fields
void Event::setName(const std::string& newName) {
    name = newName;
}

void Event::setDescription(const std::string& newDescription) {
    description = newDescription;
}

void Event::setRating(double newRating) {
    rating = newRating;
}

void Event::setSoldTicketsCount(int newSoldTicketsCount) {
    soldTicketsCount = newSoldTicketsCount;
}

// Member function
void Event::sell(int quantity) {
    soldTicketsCount += quantity;
}

// == operator overload
bool Event::operator==(const Event& otherEvent) const {
	return Event::name == otherEvent.name;
}

// Overloaded << operator
std::ostream& operator<<(std::ostream& os, const Event& event) {
    os << "Event Name: " << event.name << "\n"
       << "Description: " << event.description << "\n"
       << "Rating: " << event.rating << "\n"
       << "Number of Sold Tickets: " << event.soldTicketsCount << "\n";
    return os;
}
