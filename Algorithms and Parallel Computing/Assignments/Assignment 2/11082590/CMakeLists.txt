cmake_minimum_required(VERSION 3.10)
project(EventManagementSystem)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add all source files
add_executable(event_system
    main.cpp
    Event.cpp
    Workshop.cpp
    Conference.cpp
    VIPWorkshop.cpp
    Attendee.cpp
    EventManager.cpp
)

# Optional: Add compiler warnings
if(MSVC)
    target_compile_options(event_system PRIVATE /W4)
else()
    target_compile_options(event_system PRIVATE -Wall -Wextra -pedantic)
endif()
