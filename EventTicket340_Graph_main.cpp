#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include "Graph.h"
#include "LinkedBagDS/LinkedBag.h"
#include "Event.h"

using namespace std;
int main() {
	// Create a list of Events
	// Add 10 distinct events to the vector
	// TO DO 

	 vector<Event> events;
    events.push_back(Event("Rock Concert", "Live rock music night", 4.6, 0));
    events.push_back(Event("Food Festival", "Street food and local vendors", 4.4, 0));
    events.push_back(Event("Tech Meetup", "Networking for developers", 4.3, 0));
    events.push_back(Event("Comedy Show", "Stand-up comedy lineup", 4.5, 0));
    events.push_back(Event("Art Expo", "Modern art exhibition", 4.2, 0));
    events.push_back(Event("Soccer Match", "Local derby match", 4.7, 0));
    events.push_back(Event("Movie Premiere", "New blockbuster release", 4.1, 0));
    events.push_back(Event("Charity Show", "Fundraising dinner event", 4.0, 0));
    events.push_back(Event("Coding Workshop", "Hands-on C++ workshop", 4.8, 0));
    events.push_back(Event("Book Fair", "Books, authors, and signings", 4.3, 0));

	// Initialize a graph with n vertices (where n is the number of events) 
	//	 Indicate whether it is directed or undirected 
	// TO DO 
bool directed = false;
Graph<int> eventGraph((int)events.size(), directed);
srand((unsigned)time(nullptr));
    auto randWeight = []() -> int { return 1 + (rand() % 10); }; // 1..10

	// Add 15-20 edges (eventA, eventB, weight)
	// TO DO 
	eventGraph.addEdge(0, 1, randWeight());
    eventGraph.addEdge(0, 3, randWeight());
    eventGraph.addEdge(0, 5, randWeight());
    eventGraph.addEdge(1, 2, randWeight());
    eventGraph.addEdge(1, 6, randWeight());
    eventGraph.addEdge(1, 9, randWeight());
    eventGraph.addEdge(2, 3, randWeight());
    eventGraph.addEdge(2, 8, randWeight());
    eventGraph.addEdge(3, 6, randWeight());
    eventGraph.addEdge(3, 4, randWeight());
    eventGraph.addEdge(4, 7, randWeight());
    eventGraph.addEdge(4, 9, randWeight());
    eventGraph.addEdge(5, 6, randWeight());
    eventGraph.addEdge(5, 8, randWeight());
    eventGraph.addEdge(6, 7, randWeight());
    eventGraph.addEdge(7, 9, randWeight());
    eventGraph.addEdge(8, 9, randWeight());
    eventGraph.addEdge(2, 5, randWeight()); // total = 18 edges


	// Print the adjacency list
	cout << "=== Adjacency List ===" << endl;
	eventGraph.printGraph();

	// Depth First traversal should print event information not just indices
	 cout << "\n=== Depth First Traversal (start = 0) ===" << endl;
	int start = 0;
	
	// Call DFT 
	eventGraph.DFT(start, events);
	


	bool found = false;
	// Depth First search
	string eventName1 = "Soccer Match";
found = eventGraph.DFS(eventName1, events); // Call it
if(found) {
    cout << eventName1 << " found!" << endl;
}
	string eventName2 = "skateboarding"; //replace with an event name that DOES NOT exist 
	 
	// Call DFS 
	// TO DO:
	found = eventGraph.DFS(eventName2, events);
	if(found){
	}else{
		cout << eventName2 << " has not been found in the graph!" << endl;
	}

	return 0;
}
