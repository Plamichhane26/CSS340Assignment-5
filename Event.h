#ifndef EVENT_H
	#define EVENT_H

	#include <string>
	#include <iostream>

	class Event {
		private:
			std::string name;
			std::string description;
			double rating;
			int soldTicketsCount;

		public:
			Event();
			Event(const std::string& name, const std::string& description, double rating, int soldTicketsCount);
			~Event();

			// Getters for member data fields
			std::string getName() const;
			std::string getDescription() const;
			double getRating() const;
			int getSoldTicketsCount() const;

			// Setters for member data fields
			void setName(const std::string& newName);
			void setDescription(const std::string& newDescription);
			void setRating(double newRating);
			void setSoldTicketsCount(int newSoldTicketsCount);

			// Sell an event
			void sell(int quantity);

			// == operator overload
			bool operator==(const Event& otherEvent) const;

			// Friend function to overload << operator
			friend std::ostream& operator<<(std::ostream& os, const Event& event);
	};

#endif 
