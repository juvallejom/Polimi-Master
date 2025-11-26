//
// Created by abednego on 05/11/25.
//
#ifndef CONFERENCE_HPP
#define CONFERENCE_HPP

#include "Event.hpp"

/**
 * Class representing a full-day conference with multiple tracks
 * Duration: Full day (480 minutes = 8 hours)
 * Price: Fixed rate
 * Supports multiple concurrent attendees (streaming/hybrid)
 */
class Conference : public Event {
private:
    std::string track_name;
    int session_count;
    int max_concurrent_attendees;
    int current_attendees;
    double fixed_price;

public:
    Conference(const std::string& id, const std::string& title,
               const std::string& organizer, std::time_t date,
               const std::string& track, int sessions,
               int max_concurrent, double price);

    virtual ~Conference() = default;

    virtual double get_price() const override;
    virtual bool can_register() const override;
    virtual std::string get_description() const override;
    virtual std::string get_type() const override;

    // Override virtual methods for special behavior
    virtual void on_registration() override;
    virtual void on_cancellation() override;

    // Getters
    std::string get_track_name() const;
    int get_session_count() const;
    int get_current_attendees() const;
    int get_max_concurrent_attendees() const;

    // Attendee management
    void increment_attendees();
    void decrement_attendees();
};

#endif // CONFERENCE_HPP
