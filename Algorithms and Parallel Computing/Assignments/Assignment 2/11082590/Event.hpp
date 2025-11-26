//
// Created by abednego on 05/11/25.
//
#ifndef EVENT_HPP
#define EVENT_HPP

#include <string>
#include <ctime>

/**
 * Abstract base class representing a generic event
 * All events have: id, title, organizer, date, duration, capacity
 */
class Event {
protected:
    std::string id;
    std::string title;
    std::string organizer;
    std::time_t date;
    int duration_minutes;
    int max_capacity;
    bool is_full;

public:
    Event(const std::string& id, const std::string& title,
          const std::string& organizer, std::time_t date,
          int duration, int capacity);

    virtual ~Event() = default;

    // Getters
    std::string get_id() const;
    std::string get_title() const;
    std::string get_organizer() const;
    std::time_t get_date() const;
    int get_duration() const;
    int get_max_capacity() const;
    bool is_full_status() const;

    // Setters
    void set_full(bool full);

    // Pure virtual methods - must be implemented by derived classes
    virtual double get_price() const = 0;
    virtual bool can_register() const = 0;
    virtual std::string get_description() const = 0;
    virtual std::string get_type() const = 0;

    virtual bool is_available() const;

    // Virtual methods for special behavior
    virtual void on_registration() {}  // Called when someone registers
    virtual void on_cancellation() {}  // Called when registration is cancelled
    virtual bool requires_prerequisite() const { return false; }  // Special access needed


    std::time_t get_end_time() const;

    // TODO: Implement this method
    // Check if this event conflicts with another event
    bool conflicts_with(const Event& other) const;
};

#endif // EVENT_HPP
