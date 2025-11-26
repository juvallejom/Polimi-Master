//
// Created by abednego on 05/11/25.
//
#ifndef WORKSHOP_HPP
#define WORKSHOP_HPP

#include "Event.hpp"

/**
 * Class representing a hands-on workshop
 * Duration: 30-90 minutes
 * Price: €2 per minute
 * Limited capacity (typically 20-30 people)
 */
class Workshop : public Event {
protected:
    std::string topic;
    std::string difficulty_level;  // "Beginner", "Intermediate", "Advanced"
    std::string required_materials;
    int current_registrations;

public:
    Workshop(const std::string& id, const std::string& title,
             const std::string& organizer, std::time_t date,
             int duration, int capacity,
             const std::string& topic, const std::string& difficulty,
             const std::string& materials);

    virtual ~Workshop() = default;

    virtual std::string get_description() const override;
    virtual std::string get_type() const override;

    // TODO: Implement these methods
    virtual double get_price() const override;
    virtual bool can_register() const override;

    // Virtual methods for registration handling
    virtual void on_registration() override;
    virtual void on_cancellation() override;

    // Getters
    std::string get_topic() const;
    std::string get_difficulty_level() const;
    std::string get_required_materials() const;
    int get_current_registrations() const;

    // Registration tracking
    void increment_registrations();
    void decrement_registrations();
};

#endif // WORKSHOP_HPP
