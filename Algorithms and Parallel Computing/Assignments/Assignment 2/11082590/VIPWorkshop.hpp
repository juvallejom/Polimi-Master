//
// Created by abednego on 05/11/25.
//
#ifndef VIPWORKSHOP_HPP
#define VIPWORKSHOP_HPP

#include "Workshop.hpp"

/**
 * Class representing an exclusive VIP workshop
 * Features:
 * - Higher price (2.5x base workshop price)
 * - Requires VIP membership
 * - Exclusive perks (catering, materials, certification)
 * - Very limited capacity (max 10 people)
 */
class VIPWorkshop : public Workshop {
private:
    std::string exclusive_benefits;
    std::string catering_level;  // "Premium", "Luxury", "Gourmet"
    bool vip_access_required;

public:
    VIPWorkshop(const std::string& id, const std::string& title,
                const std::string& organizer, std::time_t date,
                int duration, int capacity,
                const std::string& topic, const std::string& difficulty,
                const std::string& materials,
                const std::string& benefits, const std::string& catering);

    virtual ~VIPWorkshop() = default;

    virtual std::string get_description() const override;
    virtual std::string get_type() const override;


    // TODO: Implement these methods
    virtual double get_price() const override;
    virtual bool can_register() const override;
    
    // Override virtual method for prerequisite check
    virtual bool requires_prerequisite() const override;

    // Special methods for VIP workshops
    bool requires_vip_access() const;
    void grant_access();
    void revoke_access();

    // Getters
    std::string get_exclusive_benefits() const;
    std::string get_catering_level() const;
};

#endif // VIPWORKSHOP_HPP
