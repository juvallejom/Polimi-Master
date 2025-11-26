//
// Created by abednego on 05/11/25.
//
#include "Conference.hpp"
#include <sstream>

Conference::Conference(const std::string& id, const std::string& title,
                       const std::string& organizer, std::time_t date,
                       const std::string& track, int sessions,
                       int max_concurrent, double price)
    : Event(id, title, organizer, date, 480, max_concurrent),
      track_name(track), session_count(sessions),
      max_concurrent_attendees(max_concurrent),
      current_attendees(0), fixed_price(price) {
}

std::string Conference::get_track_name() const {
    return track_name;
}

int Conference::get_session_count() const {
    return session_count;
}

int Conference::get_current_attendees() const {
    return current_attendees;
}

int Conference::get_max_concurrent_attendees() const {
    return max_concurrent_attendees;
}

void Conference::increment_attendees() {
    current_attendees++;
}

void Conference::decrement_attendees() {
    if (current_attendees > 0) {
        current_attendees--;
    }
}


double Conference::get_price() const {
    return fixed_price;
}

bool Conference::can_register() const {
    return current_attendees < max_concurrent_attendees;
}

std::string Conference::get_description() const {
    std::ostringstream oss;
    oss << "Conference: " << title << " by " << organizer
        << ", Track: " << track_name << ", Sessions: " << session_count
        << ", Duration: " << duration_minutes << " min"
        << ", Price: €" << fixed_price
        << ", Attendees: " << current_attendees << "/" << max_concurrent_attendees;
    return oss.str();
}


std::string Conference::get_type() const {

    return "Conference";
}

void Conference::on_registration() {
    increment_attendees();
}

void Conference::on_cancellation() {
    decrement_attendees();
}
