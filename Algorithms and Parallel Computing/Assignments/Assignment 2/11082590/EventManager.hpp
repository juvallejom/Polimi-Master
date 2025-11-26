//
// Created by abednego on 05/11/25.
//
#ifndef EVENTMANAGER_HPP
#define EVENTMANAGER_HPP

#include "Event.hpp"
#include "Attendee.hpp"
#include <vector>
#include <memory>

/**
 * Main class for managing events and attendees
 * Handles registrations, cancellations, and searches
 */
class EventManager {
private:
    std::string manager_name;
    std::vector<std::shared_ptr<Event>> catalog;
    std::vector<std::shared_ptr<Attendee>> attendees;

public:
    EventManager(const std::string& name);

    // Event management
    void add_event(std::shared_ptr<Event> event);
    std::shared_ptr<Event> find_event_by_id(const std::string& id);

    // Attendee management
    void register_attendee(std::shared_ptr<Attendee> attendee);
    std::shared_ptr<Attendee> find_attendee_by_id(const std::string& attendee_id) const;

    // Statistics
    int get_total_events() const;
    int get_available_events_count() const;
    double get_total_revenue() const;
    int get_total_registrations() const;

    std::vector<std::pair<std::shared_ptr<Event>, std::shared_ptr<Event>>>
    find_conflicting_events();

    // TODO: Implement these methods
    bool register_attendee_for_event(const std::string& attendee_id,
                                   const std::string& event_id);
    bool cancel_event_registration(const std::string& attendee_id,
                                  const std::string& event_id);

    bool can_register_without_conflict(const std::string& attendee_id,
        const std::string& event_id);

    std::vector<std::shared_ptr<Event>> filter_by_price_range(double min_price, double max_price);
    

    // Display methods
    void print_catalog() const;
    void print_available_events() const;
    void print_attendees() const;
    void print_statistics() const;
};

#endif // EVENTMANAGER_HPP
