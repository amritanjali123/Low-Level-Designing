#include <bits/stdc++.h>
using namespace std;
// this map will reperesent the list of available book and also give expeceted booking date for
// those book which already booked.
map<int, string> book_history;
map<int, book> Book_list;
int user_count, book_count;
class book_details
{
    string name;
    int book_number;
    int library_num;
    int charge;
};
class date {
    int date;
    int month;
    int year;
};
class address {
    string landmark;
    int pincode;
};

class Library {
    string lib_name;
    address lib_add;
    int library_number;
public:
    Library(string name, address add, int num)
    {
        lib_name = name;
        lib_add = add;
        library_number = num;
    }

};

class admin : public Library {
    vector<book> book_of_this_lib;
    string admin_name;
    address admin_add;
public:
    Library(lib_name, lib_add, lib_num) : admin(string name, address add)
    {
        admin_name = name;
        admin_add = add;
    }

    void add_book(string name, int charge)
    {
        book_details = book;
        book.this->name = name;
        book.id = book_count++;
        book.library_num = library_number;
        book.this->charge = charge;
        //here I am updateing the status of book
        book_history[book.id] = "Available";

        // this will contain book list of all the library here book is maped with book id
        Book_list[book.id] = book;

        // this will contain book of only this library associat with admin
        book_of_this_lib.pb(book.id);
    }
};

class  user_data {
    string name;
    string add;
    int id;

    user_data(string name, string add)
    {
        this->name = name;
        this->add = add;
        id = user_count++;
    }
    //this map will contains the status of book that user had taken
// 1 will represents book is taken and 0 represents book is submited ;
    map<book, pair<pair<date, date>, bool>> statue;
public:
    string get_book(book_details book, date d2 )
    {
        if (book_history.find(book) == book_history.end())
        {

            return "book is not available";
        }
        if (book_history[book.id] != "Available")
        {
            //this will return after which date you can get this book
            return "You can get this book after" + book_history[book.id];
        }
        // this will be a API that will give the cureent date
        date d1 = get_today_date();

        status[book] = {{d1, d2}, 1};

        //here I am updateing the status of book by expected date after which it will be available

        book_history[book.id] = to_string(d2.day) + "/" + to_string(d2.month) + "/" + to_string(d2.year);

        return "successful";
    }
    void return_book(book_details book)
    {
        book_history[book] = "Available";
        status[book.id].second = 0;
    }
};

// by calling this fun user can get all the available book user can take

vector<book> Available_book()
{
    vector search_result;
    for (auto it : book_history)
    {
        if (it->second == "Available")
        {
            book_details b1 = Book_list[it->first];
            search_result.push_back(b1) ;
        }

    }
    // this will represent all the book that is available
    return search_result;
}
// by calling this function user can cet all the book that will avaliable in future
// this contans book and future date

map<book, string> Future_book()
{
    map<book, string> search_result;
    for (auto it : book_history)
    {
        if (it->second != "Available")
        {
            book_details b1 = Book_list[it->first];
            search_result[b1] = it->second;
        }
    }
    // this will represent all the book
    return search_result;
}

int32_t main()
{
    user_count = 0;
    book_count = 0;

    //multiple library can register them self in this library management system
    //here admin1 and admin 2 are different library
    admin  adm1("central_lib", {"abs", 843105}, 1231, "ram", {"axc", 364382});
    admin  adm2("central_lib", {"abs", 843105}, 1231, "ram", {"axc", 364382});
    adm1.add_book("abc", 100);

    user_register user1("abc", "adc");
    // user can get access of book from all the library
    //this function return list of all the book that is currently available for booking;
    vector<book >= Available_book();
    // this fun will give all the book and date after which user can get this book;
    map<book, string >= Future_book();
    /*further we can add featers like user can only get list of perticular department
    like computer Science or user can sort the book by fee etc */

    // by this function user can take any book and after that status of book will be updated

    string = user1.get_book(book, d1, d2);

}
