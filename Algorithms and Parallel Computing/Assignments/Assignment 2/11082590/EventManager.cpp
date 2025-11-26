//
// Created by abednego on 05/11/25.
//
#include "EventManager.hpp"
#include "VIPWorkshop.hpp"
#include "Conference.hpp"
#include <iostream>
#include <algorithm>
#include <cctype>

EventManager::EventManager(const std::string& name) : manager_name(name) {
}

void EventManager::add_event(std::shared_ptr<Event> event) {
    catalog.push_back(event);
}

std::shared_ptr<Event> EventManager::find_event_by_id(const std::string& id) {
    for (std::shared_ptr<Event>& event : catalog) {
        if (event->get_id() == id) {
            return event;
        }
    }
    return nullptr;
}

void EventManager::register_attendee(std::shared_ptr<Attendee> attendee) {
    attendees.push_back(attendee);
}

std::shared_ptr<Attendee> EventManager::find_attendee_by_id(const std::string& attendee_id) const {
    for (const std::shared_ptr<Attendee>& attendee : attendees) {
        if (attendee->get_attendee_id() == attendee_id) {
            return attendee;
        }
    }
    return nullptr;
}

int EventManager::get_total_events() const {
    return catalog.size();
}

int EventManager::get_available_events_count() const {
    int count = 0;
    for (const std::shared_ptr<Event>& event : catalog) {
        if (event->is_available()) {
            count++;
        }
    }
    return count;
}

double EventManager::get_total_revenue() const {
    double revenue = 0.0;
    for (const std::shared_ptr<Attendee>& attendee : attendees) {
        revenue += attendee->get_spent();
    }
    return revenue;
}

int EventManager::get_total_registrations() const {
    int count = 0;
    for (const std::shared_ptr<Attendee>& attendee : attendees) {
        count += attendee->get_current_event_count();
    }
    return count;
}

// TODO: Implement this method
// Register an attendee for an event following the registration flow
bool EventManager::register_attendee_for_event(const std::string& attendee_id,
                                             const std::string& event_id) {
    for(auto it =attendees.begin();it!=attendees.end();++it){
        if((*it)->get_attendee_id()==attendee_id){
            for(auto it_event = catalog.begin();it_event!=catalog.end();++it_event){
                if((*it_event)->get_id()==event_id && (*it_event)->can_register()){
                    return (*it)->register_for_event((*it_event));
                    
                }
            }
        }
    }
    // STUDENT CODE HERE
    return false; // Replace this
}

// TODO: Implement this method
// Cancel the registration to an event following the registration flow
bool EventManager::cancel_event_registration(const std::string& attendee_id,
                                            const std::string& event_id) {
    for(auto it =attendees.begin();it!=attendees.end();++it){
        if((*it)->get_attendee_id()==attendee_id){
            for(auto it_event = catalog.begin();it_event!=catalog.end();++it_event){
                if((*it_event)->get_id()==event_id ){
                    (*it)->cancel_registration((*it_event)->get_id());
                    return true;
                }
            }
        }
    }
    // STUDENT CODE HERE
    return false; // Replace this
                                                
}

// TODO: Implement this method
std::vector<std::shared_ptr<Event>> EventManager::filter_by_price_range(double min_price, double max_price) {
    std::vector<std::shared_ptr<Event>> filtered;
    for (auto it = catalog.begin();it!=catalog.end();++it){
        if((*it)->get_price()<=max_price && (*it)->get_price()>=min_price) filtered.push_back(*it);
    }

    // STUDENT CODE HERE
    return filtered; // Replace implementation
}


// TODO: Implement this method
bool EventManager::can_register_without_conflict(const std::string& attendee_id,
                                                const std::string& event_id) {
    bool conflict_existence;
    for (auto actual_event_it = catalog.begin();actual_event_it!=catalog.end();++actual_event_it){
        if((*actual_event_it)->get_id()==event_id){
            for( auto it = attendees.begin();it!=attendees.end();++it){
                if((*it)->get_attendee_id()==attendee_id){
                auto event = (*it)->get_registered_events();
                for ( auto event_it = event.begin();event_it!=event.end();++event_it){
                    if((*actual_event_it)->conflicts_with(**event_it)) return false;
                }    
                }
            }
        }

    }
    // STUDENT CODE HERE
    return true; // Replace this
}


//Find all pairs of conflicting events in the catalog
std::vector<std::pair<std::shared_ptr<Event>, std::shared_ptr<Event>>>
EventManager::find_conflicting_events() {
    std::vector<std::pair<std::shared_ptr<Event>, std::shared_ptr<Event>>> conflicts;

    // Compare each event with every other event
    for (size_t i = 0; i < catalog.size(); i++) {
        for (size_t j = i + 1; j < catalog.size(); j++) {
            // Check if events conflict
            if (catalog[i]->conflicts_with(*catalog[j])) {
                conflicts.push_back(std::make_pair(catalog[i], catalog[j]));
            }
        }
    }

    return conflicts;
}

void EventManager::print_catalog() const {
    std::cout << "\n=== " << manager_name << " - Event Catalog ===" << std::endl;
    std::cout << "Total events: " << catalog.size() << std::endl << std::endl;

    for (const std::shared_ptr<Event>& event : catalog) {
        std::cout << event->get_description() << std::endl;
        std::cout << "  Status: "
                  << (event->is_available() ? "Available" : "Full/Closed")
                  << std::endl << std::endl;
    }
}

void EventManager::print_available_events() const {
    std::cout << "\n=== Available Events ===" << std::endl;
    for (const std::shared_ptr<Event>& event : catalog) {
        if (event->is_available()) {
            std::cout << "- " << event->get_description() << std::endl;
        }
    }
    std::cout << std::endl;
}

void EventManager::print_attendees() const {
    std::cout << "\n=== Registered Attendees ===" << std::endl;
    for (const std::shared_ptr<Attendee>& attendee : attendees) {
        attendee->print_attendee_info();
        std::cout << std::endl;
    }
}

void EventManager::print_statistics() const {
    std::cout << "\n=== " << manager_name << " - Statistics ===" << std::endl;
    std::cout << "Total events: " << get_total_events() << std::endl;
    std::cout << "Available events: " << get_available_events_count() << std::endl;
    std::cout << "Total registrations: " << get_total_registrations() << std::endl;
    std::cout << "Total revenue: €" << get_total_revenue() << std::endl;
    std::cout << "Registered attendees: " << attendees.size() << std::endl;
    std::cout << std::endl;
}
