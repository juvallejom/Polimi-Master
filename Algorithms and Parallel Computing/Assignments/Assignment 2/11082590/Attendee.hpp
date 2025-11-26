//
// Created by abednego on 05/11/25.
//
#ifndef ATTENDEE_HPP
#define ATTENDEE_HPP

#include "Event.hpp"
#include <vector>
#include <memory>

/**
 * Class representing an event attendee
 * Can register for multiple events
 * Has a budget limit and VIP status
 */
class Attendee {
private:
    std::string attendee_id;
    std::string name;
    std::string email;
    double budget;
    double spent;
    int max_events_limit;
    std::vector<std::shared_ptr<Event>> registered_events;
    bool vip_access;

public:
    Attendee(const std::string& id, const std::string& name,
             const std::string& email, double budget, int max_events = 5);

    // Getters
    std::string get_attendee_id() const;
    std::string get_name() const;
    std::string get_email() const;
    double get_budget() const;
    double get_spent() const;
    double get_remaining() const;
    int get_max_event_limit() const;
    int get_current_event_count() const;
    bool has_vip_access() const;
    const std::vector<std::shared_ptr<Event>>& get_registered_events() const;

    // VIP access management
    void grant_vip_access();
    void revoke_vip_access();

    bool can_register_more() const;
    bool can_afford(std::shared_ptr<Event> event) const;

    // Display methods
    void print_attendee_info() const;
    void print_registered_events() const;

    // TODO: Implement these methods
    bool register_for_event(std::shared_ptr<Event> event);
    bool cancel_registration(const std::string& event_id);
};

#endif // ATTENDEE_HPP
