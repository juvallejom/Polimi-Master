#include "Book.hpp"

Book::Book(const std::string& id, 
    const std::string& author, const std::string& title)
    :book_id(id),author(author),title(title),available(true){

    }

Book::Book(const std::string& id, 
    const std::string& author, const std::string& title, unsigned pages)
    :book_id(id),author(author),title(title),available(true),pages(pages){

    }

std::string Book::get_id() const {
    return book_id;
}

std::string Book::get_author() const {
    return author;
}

std::string Book::get_title() const {
    return title;
}

unsigned Book::get_pages() const {
    return pages;
}

bool Book::get_availability() const {
    return available;
}
