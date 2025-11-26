//
// Created by abednego on 05/11/25.
//
#include "VIPWorkshop.hpp"
#include <sstream>

VIPWorkshop::VIPWorkshop(const std::string& id, const std::string& title,
                         const std::string& organizer, std::time_t date,
                         int duration, int capacity,
                         const std::string& topic, const std::string& difficulty,
                         const std::string& materials,
                         const std::string& benefits, const std::string& catering)
    : Workshop(id, title, organizer, date, duration, capacity, topic, difficulty, materials),
      exclusive_benefits(benefits), catering_level(catering),
      vip_access_required(true) {
}

bool VIPWorkshop::requires_vip_access() const {
    return vip_access_required;
}

void VIPWorkshop::grant_access() {
    vip_access_required = false;
}

void VIPWorkshop::revoke_access() {
    vip_access_required = true;
}

std::string VIPWorkshop::get_exclusive_benefits() const {
    return exclusive_benefits;
}

std::string VIPWorkshop::get_catering_level() const {
    return catering_level;
}

// TODO: Implement this method
double VIPWorkshop::get_price() const {
    return Workshop::get_price()*2.5;
}

// TODO: Implement this method
bool VIPWorkshop::can_register() const {
    if (!Event::is_full_status() && !VIPWorkshop::requires_vip_access()) return true;
    else return false;
}

std::string VIPWorkshop::get_description() const {
    std::ostringstream oss;
    oss << "VIP Workshop: " << title << " by " << organizer
        << ", Topic: " << topic << ", Level: " << difficulty_level
        << ", Duration: " << duration_minutes << " min"
        << ", Price: €" << get_price()
        << ", Benefits: " << exclusive_benefits
        << ", Catering: " << catering_level
        << ", Spots: " << current_registrations << "/" << max_capacity;
    return oss.str();
}

std::string VIPWorkshop::get_type() const {

    return "VIP Workshop";
}

bool VIPWorkshop::requires_prerequisite() const {
    return vip_access_required;
}
