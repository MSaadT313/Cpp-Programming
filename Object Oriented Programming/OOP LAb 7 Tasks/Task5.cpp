#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Media {
protected:
    string title, publicationDate, uniqueID, publisher;
    bool isCheckedOut;
public:
    Media(string t, string pd, string id, string pub) : title(t), publicationDate(pd), uniqueID(id), publisher(pub), isCheckedOut(false) {}
    virtual void displayInfo() {
        cout << "Title: " << title << "\nPublication Date: " << publicationDate << "\nID: " << uniqueID << "\nPublisher: " << publisher << endl;
    }
    virtual void checkOut() {
        if (!isCheckedOut) {
            isCheckedOut = true;
            cout << title << " checked out successfully.\n";
        } else {
            cout << title << " is already checked out.\n";
        }
    }
    virtual void returnItem() {
        if (isCheckedOut) {
            isCheckedOut = false;
            cout << title << " returned successfully.\n";
        } else {
            cout << title << " was not checked out.\n";
        }
    }
    string getTitle() const { return title; }
    string getPublicationDate() const { return publicationDate; }
    virtual ~Media() {}
};

class Book : public Media {
    string author, ISBN;
    int numberOfPages;
public:
    Book(string t, string pd, string id, string pub, string a, string isbn, int pages)
        : Media(t, pd, id, pub), author(a), ISBN(isbn), numberOfPages(pages) {}
    void displayInfo() override {
        Media::displayInfo();
        cout << "Author: " << author << "\nISBN: " << ISBN << "\nPages: " << numberOfPages << endl;
    }
    string getAuthor() const { return author; }
};

class DVD : public Media {
    string director;
    int duration;
    string rating;
public:
    DVD(string t, string pd, string id, string pub, string d, int dur, string r)
        : Media(t, pd, id, pub), director(d), duration(dur), rating(r) {}
    void displayInfo() override {
        Media::displayInfo();
        cout << "Director: " << director << "\nDuration: " << duration << " min\nRating: " << rating << endl;
    }
};

class CD : public Media {
    string artist, genre;
    int numberOfTracks;
public:
    CD(string t, string pd, string id, string pub, string a, int tracks, string g)
        : Media(t, pd, id, pub), artist(a), numberOfTracks(tracks), genre(g) {}
    void displayInfo() override {
        Media::displayInfo();
        cout << "Artist: " << artist << "\nTracks: " << numberOfTracks << "\nGenre: " << genre << endl;
    }
};

class Magazine : public Media {
    int issueNumber;
public:
    Magazine(string t, string pd, string id, string pub, int issue)
        : Media(t, pd, id, pub), issueNumber(issue) {}
    void displayInfo() override {
        Media::displayInfo();
        cout << "Issue Number: " << issueNumber << endl;
    }
};

class Library {
    vector<Media*> items;
public:
    void addMedia(Media* m) {
        items.push_back(m);
    }
    void search(string title) {
        for (auto item : items)
            if (item->getTitle() == title) item->displayInfo();
    }
    void searchByAuthor(string author) {
        for (auto item : items) {
            Book* b = dynamic_cast<Book*>(item);
            if (b && b->getAuthor() == author) b->displayInfo();
        }
    }
    void searchByPublicationDate(string date) {
        for (auto item : items)
            if (item->getPublicationDate() == date) item->displayInfo();
    }
    ~Library() {
        for (auto item : items) delete item;
    }
};

int main() {
    Library lib;
    lib.addMedia(new Book("1984", "1949", "B001", "Secker & Warburg", "George Orwell", "123456789", 328));
    lib.addMedia(new DVD("Inception", "2010", "D001", "Warner Bros", "Christopher Nolan", 148, "PG-13"));
    lib.addMedia(new CD("Thriller", "1982", "C001", "Epic", "Michael Jackson", 9, "Pop"));
    lib.addMedia(new Magazine("National Geographic", "2023", "M001", "NatGeo", 1204));

    lib.search("Inception");
    lib.searchByAuthor("George Orwell");
    lib.searchByPublicationDate("1982");

    return 0;
}
