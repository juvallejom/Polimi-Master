    //
// Created by abednego on 05/11/25.
//
#include "Attendee.hpp"
#include <iostream>

Attendee::Attendee(const std::string& id, const std::string& name,
                   const std::string& email, double budget, int max_events)
    : attendee_id(id), name(name), email(email),
      budget(budget), spent(0.0), max_events_limit(max_events),
      vip_access(false) {
}

std::string Attendee::get_attendee_id() const {
    return attendee_id;
}

std::string Attendee::get_name() const {
    return name;
}

std::string Attendee::get_email() const {
    return email;
}

double Attendee::get_budget() const {
    return budget;
}

double Attendee::get_spent() const {
    return spent;
}

double Attendee::get_remaining() const {
    return budget - spent;
}

int Attendee::get_max_event_limit() const {
    return max_events_limit;
}

int Attendee::get_current_event_count() const {
    return registered_events.size();
}

bool Attendee::has_vip_access() const {
    return vip_access;
}

void Attendee::grant_vip_access() {
    vip_access = true;
}

void Attendee::revoke_vip_access() {
    vip_access = false;
}

const std::vector<std::shared_ptr<Event>>& Attendee::get_registered_events() const {
    return registered_events;
}

bool Attendee::can_register_more() const {
    return get_current_event_count() < max_events_limit;
}

bool Attendee::can_afford(std::shared_ptr<Event> event) const {
    return get_remaining() >= event->get_price();
}

// TODO: Implement this method
bool Attendee::register_for_event(std::shared_ptr<Event> event) {
    bool existing_conflict = false;
    for(const auto& e : registered_events){
        if(event->conflicts_with(*e)) existing_conflict=true;
    }
    if(can_register_more()&& can_afford(event)&&
    (!event->requires_prerequisite()||has_vip_access())&&!existing_conflict){
        registered_events.push_back(event);
        spent = spent+event->get_price();
        event-> on_registration();
        return true;
    }
    else return false; // Replace this
}

// TODO: Implement this method
bool Attendee::cancel_registration(const std::string& event_id) {
    for (auto it=registered_events.begin();it!=registered_events.end();++it){
        if((*it)->get_id()==event_id){
            spent = spent-(*it)->get_price();
            (*it)->on_cancellation();
            registered_events.erase(it);
            return true;

        }
    }
    return false; // Replace this
}

void Attendee::print_attendee_info() const {
    std::cout << "Attendee ID: " << attendee_id << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Budget: €" << budget << std::endl;
    std::cout << "Spent: €" << spent << std::endl;
    std::cout << "Remaining: €" << get_remaining() << std::endl;
    std::cout << "Registered events: " << registered_events.size()
              << "/" << max_events_limit << std::endl;
    std::cout << "VIP Access: "
              << (vip_access ? "Yes" : "No") << std::endl;
}

void Attendee::print_registered_events() const {
    std::cout << "Registered events for " << name << ":" << std::endl;
    if (registered_events.empty()) {
        std::cout << "  No events registered" << std::endl;
    } else {
        for (const std::shared_ptr<Event>& event : registered_events) {
            std::cout << "  - " << event->get_description() << std::endl;
        }
    }
}
