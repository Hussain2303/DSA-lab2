#include <iostream>
#include <string>

using namespace std;

// Abstract Base Class
class Media {
public:
	virtual void display() const = 0; // Pure virtual function
	virtual ~Media() {} // Virtual destructor
};

// Book Class
class Book : public Media {
private:
	string title;
	string author;
	int pages;

public:
	Book(const string& t, const string& a, int p) : title(t), author(a), pages(p) {}

	void display() const override {
		cout << "Book Title: " << title << ", Author: " << author << ", Pages: " << pages << endl;
	}

	int getPages() const {
		return pages;
	}

	string getTitle() const {
		return title;
	}
};

// Newspaper Class
class Newspaper : public Media {
private:
	string name;
	string date;
	string edition;

public:
	Newspaper(const string& n, const string& d, const string& e) : name(n), date(d), edition(e) {}

	void display() const override {
		cout << "Newspaper Name: " << name << ", Date: " << date << ", Edition: " << edition << endl;
	}

	string getEdition() const {
		return edition;
	}

	string getName() const {
		return name;
	}
};

// Library Class
class Library {
private:
	Media* collection[100]; // Fixed-size array for collection
	int count;

public:
	Library() : count(0) {}

	~Library() {
		for (int i = 0; i < count; ++i) {
			delete collection[i]; // Clean up memory
		}
	}

	void addBook(const Book& book) {
		if (count < 100) {
			collection[count++] = new Book(book); // Store dynamically
		}
		else {
			cout << "Library is full!" << endl;
		}
	}

	void addNewspaper(const Newspaper& newspaper) {
		if (count < 100) {
			collection[count++] = new Newspaper(newspaper); // Store dynamically
		}
		else {
			cout << "Library is full!" << endl;
		}
	}

	void displayCollection() const {
		for (int i = 0; i < count; ++i) {
			collection[i]->display();
		}
	}

	void sortBooksByPages() {
		for (int i = 0; i < count; ++i) {
			for (int j = i + 1; j < count; ++j) {
				Book* bookA = dynamic_cast<Book*>(collection[i]);
				Book* bookB = dynamic_cast<Book*>(collection[j]);
				if (bookA && bookB && bookA->getPages() > bookB->getPages()) {
					// Swap
					Media* temp = collection[i];
					collection[i] = collection[j];
					collection[j] = temp;
				}
			}
		}
	}

	void sortNewspapersByEdition() {
		for (int i = 0; i < count; ++i) {
			for (int j = i + 1; j < count; ++j) {
				Newspaper* newspaperA = dynamic_cast<Newspaper*>(collection[i]);
				Newspaper* newspaperB = dynamic_cast<Newspaper*>(collection[j]);
				if (newspaperA && newspaperB && newspaperA->getEdition() > newspaperB->getEdition()) {
					// Swap
					Media* temp = collection[i];
					collection[i] = collection[j];
					collection[j] = temp;
				}
			}
		}
	}

	Book* searchBookByTitle(const string& title) const {
		for (int i = 0; i < count; ++i) {
			Book* book = dynamic_cast<Book*>(collection[i]);
			if (book && book->getTitle() == title) {
				return book;
			}
		}
		return nullptr; // Not found
	}

	Newspaper* searchNewspaperByName(const string& name) const {
		for (int i = 0; i < count; ++i) {
			Newspaper* newspaper = dynamic_cast<Newspaper*>(collection[i]);
			if (newspaper && newspaper->getName() == name) {
				return newspaper;
			}
		}
		return nullptr; // Not found
	}
};

// Main function
int main() {
	// Create book objects
	Book book1("The Catcher in the Rye", "J.D. Salinger", 277);
	Book book2("To Kill a Mockingbird", "Harper Lee", 324);

	// Create newspaper objects
	Newspaper newspaper1("Washington Post", "2024-10-13", "Morning Edition");
	Newspaper newspaper2("The Times", "2024-10-12", "Weekend Edition");

	// Create a library object
	Library library;

	// Add books and newspapers to the library
	library.addBook(book1);
	library.addBook(book2);
	library.addNewspaper(newspaper1);
	library.addNewspaper(newspaper2);

	// Display the entire collection
	cout << "Before Sorting:\n";
	library.displayCollection();

	// Sort books by pages and newspapers by edition
	library.sortBooksByPages();
	library.sortNewspapersByEdition();

	cout << "\nAfter Sorting:\n";
	library.displayCollection();

	// Search for a book by title
	Book* foundBook = library.searchBookByTitle("The Catcher in the Rye");
	if (foundBook) {
		cout << "\nFound Book:\n";
		foundBook->display();
	}
	else {
		cout << "\nBook not found.\n";
	}

	// Search for a newspaper by name
	Newspaper* foundNewspaper = library.searchNewspaperByName("The Times");
	if (foundNewspaper) {
		cout << "\nFound Newspaper:\n";
		foundNewspaper->display();
	}
	else {
		cout << "\nNewspaper not found.\n";
	}

	return 0;
}
