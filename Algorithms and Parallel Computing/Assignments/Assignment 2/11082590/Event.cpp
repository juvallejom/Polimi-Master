//
// Created by abednego on 05/11/25.
//
#include "Event.hpp"

Event::Event(const std::string& id, const std::string& title,
             const std::string& organizer, std::time_t date,
             int duration, int capacity)
    : id(id), title(title), organizer(organizer),
      date(date), duration_minutes(duration), max_capacity(capacity),
      is_full(false) {
}

std::string Event::get_id() const {
    return id;
}

std::string Event::get_title() const {
    return title;
}

std::string Event::get_organizer() const {
    return organizer;
}

std::time_t Event::get_date() const {
    return date;
}

int Event::get_duration() const {
    return duration_minutes;
}

int Event::get_max_capacity() const {
    return max_capacity;
}

bool Event::is_full_status() const {
    return is_full;
}

void Event::set_full(bool full) {
    is_full = full;
}

bool Event::is_available() const {
    return can_register();
}


std::time_t Event::get_end_time() const {
    return date + (duration_minutes * 60);
}

// TODO: Implement this method
// Check if this event conflicts with another event
// Two events conflict if their time ranges overlap
bool Event::conflicts_with(const Event& other) const {
    if((get_date()<other.get_duration()*60 + other.get_date())&&(other.get_date()<get_date()+get_duration()*60)) return true;
    else return false; // 
}
