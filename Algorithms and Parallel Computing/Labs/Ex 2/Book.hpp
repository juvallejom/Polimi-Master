
#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>


class Book {
private:
    std::string book_id;
    std::string author;
    std::string title;
    unsigned pages = 0;
    bool available;
public:

    Book(const std::string& id, const std::string& author, const std::string& title);
    Book(const std::string& id, const std::string& author, const std::string& title, unsigned pages);

    // Getter //
    std::string get_id() const;
    std::string get_author() const;
    std::string get_title() const;
    unsigned get_pages() const;
    bool get_availability() const;

    // Setter //


    // Methods //
    void set_availability(); // reviasr esto. Solo cambio de 
    

    
};

#endif
