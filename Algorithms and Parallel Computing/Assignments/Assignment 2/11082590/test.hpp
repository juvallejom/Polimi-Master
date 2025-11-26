//
// Created by abednego on 05/11/25.
//
#ifndef TEST_HPP
#define TEST_HPP

#include "Event.hpp"
#include "Workshop.hpp"
#include "Conference.hpp"
#include "VIPWorkshop.hpp"
#include "Attendee.hpp"
#include "EventManager.hpp"
#include <iostream>
#include <memory>
#include <cassert>

/**
 * Test 1: Event Type Fundamentals (Workshop, Conference, VIP Workshop)
 */
void test1() {
    std::cout << "\n========== TEST 1: Event Type Fundamentals ==========" << std::endl;

    std::time_t event_date = std::time(nullptr) + 86400;

    // Part A: Workshop
    std::cout << "\n--- Part A: Workshop (90 min) ---" << std::endl;
    std::shared_ptr<Workshop> workshop = std::make_shared<Workshop>(
        "W001", "C++ Advanced Techniques", "Dr. Smith",
        event_date, 90, 25,
        "Modern C++", "Advanced", "Laptop, IDE"
    );

    std::cout << "Workshop.get_price() = " << workshop->get_price() << std::endl;
    std::cout << "Expected = 180" << std::endl;
    std::cout << "Workshop.get_type() = " << workshop->get_type() << std::endl;
    std::cout << "Expected = Workshop" << std::endl;
    std::cout << "Workshop.can_register() = " << (workshop->can_register() ? "Yes" : "No") << std::endl;
    std::cout << "Expected = Yes" << std::endl;

    // Part B: VIP Workshop
    std::cout << "\n--- Part B: VIP Workshop (120 min) ---" << std::endl;
    std::shared_ptr<VIPWorkshop> vip_workshop = std::make_shared<VIPWorkshop>(
        "VW001", "Executive Leadership", "Prof. Johnson",
        event_date, 120, 10,
        "Leadership", "Expert", "Case studies",
        "1-on-1 coaching", "Gourmet"
    );

    
    std::cout << "VIPWorkshop.get_type() : " << vip_workshop->get_type() << std::endl;
    std::cout << "Expected : VIP Workshop" << std::endl;
    std::cout << "VIPWorkshop.can_register() (before access) : " << (vip_workshop->can_register() ? "Yes" : "No") << std::endl;
    std::cout << "Expected : No" << std::endl;

    vip_workshop->grant_access();

    std::cout << "VIPWorkshop.can_register() (after access) : " << (vip_workshop->can_register() ? "Yes" : "No") << std::endl;
    std::cout << "Expected : Yes" << std::endl;

    std::cout << "VIPWorkshop.get_price() = " << vip_workshop->get_price() << std::endl;
    std::cout << "Expected = 600" << std::endl;
}

/**
 * Test 2: Attendee Registration and Budget Management
 */
void test2() {
    std::cout << "\n========== TEST 2: Attendee Registration ==========" << std::endl;

    std::shared_ptr<Attendee> attendee = std::make_shared<Attendee>(
        "A001", "Alice Brown", "alice@email.com", 500.0, 3
    );

    std::time_t event_date = std::time(nullptr) + 86400;
    std::shared_ptr<Workshop> workshop = std::make_shared<Workshop>(
        "W002", "Python for Data Science", "Dr. Lee",
        event_date, 60, 20,
        "Data Science", "Beginner", "Laptop"
    );

    std::cout << "\nInitial state (budget=500, max_events=3):" << std::endl;
    std::cout << "Attendee.can_register_more() : " << (attendee->can_register_more() ? "Yes" : "No") << std::endl;
    std::cout << "Expected : Yes" << std::endl;
    std::cout << "Attendee.can_afford(workshop) : " << (attendee->can_afford(workshop) ? "Yes" : "No") << std::endl;
    std::cout << "Expected : Yes" << std::endl;

    std::cout << "\nRegistering for workshop (60 min)..." << std::endl;
    bool success = attendee->register_for_event(workshop);
    std::cout << "Attendee.register_for_event() = " << (success ? "Yes" : "No") << std::endl;
    std::cout << "Expected = Yes" << std::endl;
    std::cout << "Attendee.get_spent() = " << attendee->get_spent() << std::endl;
    std::cout << "Expected = 120" << std::endl;
    std::cout << "Attendee.get_remaining() = " << attendee->get_remaining() << std::endl;
    std::cout << "Expected = 380" << std::endl;
    attendee->print_registered_events ();
}

/**
 * Test 3: EventManager Basic Operations
 */
void test3() {
    std::cout << "\n========== TEST 3: EventManager Basic Operations ==========" << std::endl;

    EventManager manager("TechConf 2025");

    std::time_t event_date = std::time(nullptr) + 86400;
    std::shared_ptr<Workshop> workshop = std::make_shared<Workshop>(
        "W003", "Docker Fundamentals", "John Doe",
        event_date, 90, 30,
        "DevOps", "Intermediate", "Docker installed"
    );
    manager.add_event(workshop);

    std::shared_ptr<Conference> conference = std::make_shared<Conference>(
        "C002", "Cloud Computing Conference", "CloudTech",
        event_date, "Cloud Native", 6, 150, 249.99
    );
    manager.add_event(conference);

    std::shared_ptr<Attendee> attendee = std::make_shared<Attendee>(
        "A002", "Bob Smith", "bob@email.com", 600.0, 5
    );
    manager.register_attendee(attendee);

    std::cout << "\nRegistering attendee for workshop (90 min)..." << std::endl;
    bool success = manager.register_attendee_for_event("A002", "W003");
    std::cout << "EventManager.register_attendee_for_event() = " << (success ? "Yes" : "No") << std::endl;
    std::cout << "Expected = Yes" << std::endl;
    //attendee->print_registered_events();

    std::cout << "\nEventManager.get_total_registrations() = " << manager.get_total_registrations() << std::endl;
    std::cout << "Expected = 1" << std::endl;
    std::cout << "EventManager.get_total_revenue() = " << manager.get_total_revenue() << std::endl;
    std::cout << "Expected = 180" << std::endl;
    //manager.print_statistics();
}

/**
 * Test 4: Filter Functionality
 */
void test4() {
    std::cout << "\n========== TEST 4: Filter Functionality ==========" << std::endl;

    EventManager manager("Multi-Event Platform");

    std::time_t event_date = std::time(nullptr) + 86400;

    manager.add_event(std::make_shared<Workshop>(
        "W004", "Python Advanced", "Dr. Chen",
        event_date, 120, 25, "Python", "Advanced", "Laptop"
    ));

    manager.add_event(std::make_shared<Workshop>(
        "W005", "JavaScript Basics", "Jane Doe",
        event_date, 60, 30, "JavaScript", "Beginner", "None"
    ));

    manager.add_event(std::make_shared<Conference>(
        "C003", "Python Summit", "DataCorp",
        event_date, "Data Science", 8, 200, 399.99
    ));

    std::vector<std::shared_ptr<Event>> affordable = manager.filter_by_price_range(100.0, 300.0);
    std::cout << "EventManager.filter_by_price_range(100-300) = " << affordable.size() << std::endl;
    std::cout << "Expected = 2" << std::endl;

}

/**
 * Test 5: Registration Cancellation and Refund
 */
void test5() {
    std::cout << "\n========== TEST 5: Cancellation and Refund ==========" << std::endl;

    EventManager manager("Event Platform");

    std::time_t event_date = std::time(nullptr) + 86400;
    std::shared_ptr<Workshop> workshop = std::make_shared<Workshop>(
        "W006", "Git Version Control", "Mike Johnson",
        event_date, 90, 20, "Git", "Beginner", "Laptop"
    );
    std::shared_ptr<Workshop> workshop2 = std::make_shared<Workshop>(
        "W010", "Git Version22222 Control", "Mike 222Johnson",
        event_date+7200, 90, 20, "Git", "Beginner", "Laptop"
    );
    manager.add_event(workshop);
    manager.add_event(workshop2);

    std::shared_ptr<Attendee> attendee = std::make_shared<Attendee>(
        "A003", "Carol White", "carol@email.com", 400.0, 2
    );

    
    manager.register_attendee(attendee);

    std::cout << "\nRegistering for workshop (90 min)..." << std::endl;
    manager.register_attendee_for_event("A003", "W006");
    std::cout << "After registration:" << std::endl;
    std::cout << "Attendee.get_spent() : " << attendee->get_spent() << std::endl;
    std::cout << "Expected : 180" << std::endl;
    std::cout << "Attendee.get_current_event_count() : " << attendee->get_current_event_count() << std::endl;
    std::cout << "Expected : 1" << std::endl;
    //attendee->print_registered_events();
    //manager.print_statistics();

    std::cout << "\nCancelling registration..." << std::endl;
    bool cancel_success = manager.cancel_event_registration("A003", "W006");
    std::cout << "EventManager.cancel_event_registration() = " << (cancel_success ? "Yes" : "No") << std::endl;
    std::cout << "Expected = Yes" << std::endl;
    std::cout << "Attendee.get_spent() = " << attendee->get_spent() << std::endl;
    std::cout << "Expected = 0" << std::endl;
    std::cout << "Attendee.get_current_event_count() = " << attendee->get_current_event_count() << std::endl;
    std::cout << "Expected = 0" << std::endl;
    //attendee->print_registered_events();
    //manager.print_statistics();
}

/**
 * Test 6: Time Conflict Detection and Prevention
 */
void test6() {
    std::cout << "\n========== TEST 6: Time Conflict Detection ==========" << std::endl;

    EventManager manager("Conflict Detection System");

    std::time_t base_time = std::time(nullptr);
    std::tm* time_info = std::localtime(&base_time);
    time_info->tm_hour = 12;
    time_info->tm_min = 0;
    time_info->tm_sec = 0;
    std::time_t noon = std::mktime(time_info);

    // Event 1: 12:00-14:00 (120 min)
    std::shared_ptr<Workshop> event1 = std::make_shared<Workshop>(
        "W100", "Morning Workshop", "Tech Team",
        noon, 120, 20, "Programming", "Intermediate", "Laptop"
    );

    // Event 2: 14:00-15:30 (90 min) - No conflict
    std::shared_ptr<Workshop> event2 = std::make_shared<Workshop>(
        "W101", "Afternoon Workshop", "Design Team",
        noon + 7200, 90, 15, "Design", "Beginner", "Sketchpad"
    );

    // Event 3: 13:00-14:30 (90 min) - CONFLICTS with Event 1
    std::shared_ptr<Conference> event3 = std::make_shared<Conference>(
        "C100", "Overlap Conference", "Admin",
        noon + 3600, "Technology", 10, 200, 150.0
    );

    // Event 4: 13:30-15:00 (90 min) - CONFLICTS with Event 1 and 3
    std::shared_ptr<Workshop> event4 = std::make_shared<Workshop>(
        "W102", "Multi-Conflict Workshop", "Product Team",
        noon + 5400, 90, 25, "Product", "Advanced", "None"
    );

    manager.add_event(event1);
    manager.add_event(event2);
    manager.add_event(event3);
    manager.add_event(event4);

    std::cout << "\n--- Testing get_end_time() ---" << std::endl;
    std::time_t end1 = event1->get_end_time();
    std::cout << "Event.get_end_time() duration : " << (end1 - noon) / 60 << std::endl;
    std::cout << "Expected : 120" << std::endl;

    std::cout << "\n--- Testing conflicts_with() ---" << std::endl;
    std::cout << "Event1.conflicts_with(Event2) = " << (event1->conflicts_with(*event2) ? "Yes" : "No") << std::endl;
    std::cout << "Expected = No" << std::endl;
    std::cout << "Event1.conflicts_with(Event3) = " << (event1->conflicts_with(*event3) ? "Yes" : "No") << std::endl;
    std::cout << "Expected = Yes" << std::endl;
    std::cout << "Event3.conflicts_with(Event4) = " << (event3->conflicts_with(*event4) ? "Yes" : "No") << std::endl;
    std::cout << "Expected = Yes" << std::endl;

    std::cout << "\n--- Testing find_conflicting_events() ---" << std::endl;
    std::vector<std::pair<std::shared_ptr<Event>, std::shared_ptr<Event>>> conflicts = manager.find_conflicting_events();
    std::cout << "EventManager.find_conflicting_events() = " << conflicts.size() << std::endl;
    std::cout << "Expected = 5" << std::endl;

    std::cout << "\n--- Testing conflict prevention in registration ---" << std::endl;
    std::shared_ptr<Attendee> attendee1 = std::make_shared<Attendee>("A100", "John Doe", "john@test.com", 1000.0, 5);
    manager.register_attendee(attendee1);
    manager.register_attendee_for_event("A100", "W100");

    bool can_reg2 = manager.can_register_without_conflict("A100", "W101");
    std::cout << "EventManager.can_register_without_conflict(Event2) = " << (can_reg2 ? "Yes" : "No") << std::endl;
    std::cout << "Expected = Yes" << std::endl;

    bool reg2 = manager.register_attendee_for_event("A100", "W101");
    std::cout << "EventManager.register_attendee_for_event(Event2) = " << (reg2 ? "Yes" : "No") << std::endl;
    std::cout << "Expected = Yes" << std::endl;
    std::cout << "Event count = " << attendee1->get_current_event_count() << std::endl;
    std::cout << "Expected = 2" << std::endl;

    bool can_reg3 = manager.can_register_without_conflict("A100", "C100");
    std::cout << "\nEventManager.can_register_without_conflict(Event3-conflict) = " << (can_reg3 ? "Yes" : "No") << std::endl;
    std::cout << "Expected = No" << std::endl;

    bool reg3 = manager.register_attendee_for_event("A100", "C100");
    std::cout << "EventManager.register_attendee_for_event(Event3-conflict) = " << (reg3 ? "Yes" : "No") << std::endl;
    std::cout << "Expected = No" << std::endl;
    std::cout << "Event count = " << attendee1->get_current_event_count() << std::endl;
    std::cout << "Expected = 2" << std::endl;
}

#endif // TEST_HPP
