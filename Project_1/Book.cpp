#include "Book.hpp"

    // write and document all methods in this file.
    //the following setter anf getter functions us standard return and assignment methods
    Book::Book()
    {

    }

    Book::~Book()
    {

    }

    Book::Book(const Book& rhs)
    {
        title_ = rhs.title_;
        author_ = rhs.author_;
        ISBN_ = rhs.ISBN_;
        icon_ = new int[80];
        std::copy(rhs.icon_, rhs.icon_ + 80, icon_);
        price_ = rhs.price_;
        keywords_ = rhs.keywords_;
        blurb_ = rhs.blurb_;
    }


    Book& Book::operator=(const Book& rhs)
    {
        if (this != &rhs) {
            title_ = rhs.title_;
            author_ = rhs.author_;
            icon_ = new int[80];
            std::copy(rhs.icon_, rhs.icon_ + 80, icon_);
            price_ = rhs.price_;
            keywords_ = rhs.keywords_;
            blurb_ = rhs.blurb_;
        }
        return *this;
    }

    //copy constructor
    Book::Book(Book&& rhs)
    {
        title_ = std::move(rhs.title_);
        author_ = std::move(rhs.author_);
        ISBN_ = rhs.ISBN_;
        icon_ = rhs.icon_;
        rhs.icon_ = nullptr;
        price_ = rhs.price_;
        keywords_ = std::move(rhs.keywords_);
        blurb_ = std::move(rhs.blurb_);
    }
    
    //assignment operator
    Book& Book::operator=(Book&& rhs)
    {
         if (this != &rhs) {
            title_ = std::move(rhs.title_);
            author_ = std::move(rhs.author_);
            ISBN_ = rhs.ISBN_;
            icon_ = rhs.icon_;
            rhs.icon_ = nullptr;
            price_ = rhs.price_;
            keywords_ = std::move(rhs.keywords_);
            blurb_ = std::move(rhs.blurb_);
        }
        return *this;
    }

    const std::string& Book::getTitle() const
    {
        return title_;
    }

    void Book::setTitle(const std::string& title)
    {
        title_ = title;
    }

    const std::string& Book::getAuthor() const
    {
        return author_;
    }

    void Book::setAuthor(const std::string& author)
    {
        author_ = author;
    }

    long long int Book::getISBN() const
    {
        return ISBN_;
    }

    void Book::setISBN(long long int ISBN)
    {
        ISBN_ = ISBN;
    }

    const int* Book::getIcon() const
    {
        return (icon_);
    }

    void Book::setIcon(int* icon)
    {
        delete[] icon_;
        icon_ = new int[80];
        std::copy(icon, icon + 80, icon_);
    }

    float Book::getPrice() const
    {
        return price_;
    }

    void Book::setPrice(float price)
    {
        price_ = price;
    }

    const std::vector<std::string>& Book::getKeywords() const
    {
        return keywords_;
    }

    void Book::setKeywords(const std::vector<std::string>& keywords)
    {
        keywords_ = keywords;
    }

    const std::string& Book::getBlurb() const
    {
        return blurb_;
    }

    void Book::setBlurb(const std::string& blurb)
    {
        blurb_ = blurb;
    }

    //takes no input, prints out requested data as per specifications 
    void Book::print() const
    {
        std::cout << "Title: " << title_ << std::endl;
        std::cout << "Author: " << author_ << std::endl;
        std::cout << "ISBN: " << ISBN_ << std::endl;
        std::cout << "Icon: ";
            for (int i = 0; i < 80; ++i) {
                std::cout << icon_[i];
                if (i < 79){
                    std::cout << " ";
                }
            }
        std::cout << std::endl;
        //setting to two decimal places
        std::cout << "Price: $" << std::fixed << std::setprecision(2) << price_ << std::endl;
        std::cout << "Keywords: ";
            for (int i = 0; i < keywords_.size(); i++) {
                std::cout << keywords_[i];
                if (i < keywords_.size() - 1){
                    std::cout << ", ";
                }
            }
        std::cout << std::endl;
        std::cout << "Blurb: " << blurb_ << std::endl;
        std::cout << std::endl;
    }