//
// Created by abednego on 05/11/25.
//
#include "Workshop.hpp"
#include <sstream>

Workshop::Workshop(const std::string& id, const std::string& title,
                   const std::string& organizer, std::time_t date,
                   int duration, int capacity,
                   const std::string& topic, const std::string& difficulty,
                   const std::string& materials)
    : Event(id, title, organizer, date, duration, capacity),
      topic(topic), difficulty_level(difficulty),
      required_materials(materials), current_registrations(0) {
}

std::string Workshop::get_topic() const {
    return topic;
}

std::string Workshop::get_difficulty_level() const {
    return difficulty_level;
}

std::string Workshop::get_required_materials() const {
    return required_materials;
}

int Workshop::get_current_registrations() const {
    return current_registrations;
}

void Workshop::increment_registrations() {
    current_registrations++;
    if (current_registrations >= max_capacity) {
        set_full(true);
    }
}

void Workshop::decrement_registrations() {
    if (current_registrations > 0) {
        current_registrations--;
        set_full(false);
    }
}

// TODO: Implement this method
double Workshop::get_price() const {
    return 2*Event::get_duration();
}

// TODO: Implement this method
bool Workshop::can_register() const {
    if (Workshop::get_current_registrations() < Event::max_capacity) return true;
    else return false;
}

std::string Workshop::get_description() const {
    std::ostringstream oss;
    oss << "Workshop: " << title << " by " << organizer
        << ", Topic: " << topic << ", Level: " << difficulty_level
        << ", Duration: " << duration_minutes << " min"
        << ", Price: €" << get_price()
        << ", Spots: " << current_registrations << "/" << max_capacity;
    return oss.str();
}


std::string Workshop::get_type() const {
    return "Workshop";
}

void Workshop::on_registration() {
    increment_registrations();
}

void Workshop::on_cancellation() {
    decrement_registrations();
}
