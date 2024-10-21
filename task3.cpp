#include <iostream>
#include <string>

using namespace std;

class Book
{
private:
	string title;
	string author;
	int pages;

public:
	Book(const string& t, const string& a, int p) : title(t), author(a), pages(p) {}

	void display() const
	{
		cout << "Book: " << title << ", Author: " << author << ", Pages: " << pages << endl;
	}

	string getTitle() const 
	{
		return title;
	}

	int getPages() const
	{
		return pages;
	}
};

class Newspaper 
{
private:
	string name;
	string date;
	string edition;

public:
	Newspaper(const string& n, const string& d, const string& e) : name(n), date(d), edition(e) {}

	void display() const
	{
		cout << "Newspaper: " << name << ", Date: " << date << ", Edition: " << edition << endl;
	}

	string getTitle() const
	{
		return name;
	}

	string getEdition() const
	{
		return edition;
	}
};

class Library 
{
private:
	Book* books[3];
	Newspaper* newspapers[3];
	int bookCount;
	int newspaperCount;

public:
	Library() : bookCount(0), newspaperCount(0) {}

	~Library() 
	{
		for (int i = 0; i < bookCount; ++i)
		{
			delete books[i];
		}
		for (int i = 0; i < newspaperCount; ++i)
		{
			delete newspapers[i];
		}
	}

	void addBook(const Book& book)
	{
		if (bookCount < 3) 
		{
			books[bookCount++] = new Book(book);
		}
		else
		{
			cout << "Library is full! Cannot add more books." << endl;
		}
	}

	void addNewspaper(const Newspaper& newspaper) 
	{
		if (newspaperCount < 3) 
		{
			newspapers[newspaperCount++] = new Newspaper(newspaper);
		}
		else 
		{
			cout << "Library is full! Cannot add more newspapers." << endl;
		}
	}

	void displayCollection() const
	{
		cout << "Books:\n";
		for (int i = 0; i < bookCount; ++i) 
		{
			books[i]->display();
		}
		cout << "Newspapers:\n";
		for (int i = 0; i < newspaperCount; ++i)
		{
			newspapers[i]->display();
		}
	}

	void sortBooksByPages()
	{
		for (int i = 0; i < bookCount - 1; ++i) 
		{
			for (int j = i + 1; j < bookCount; ++j) 
			{
				if (books[i]->getPages() > books[j]->getPages())
				{
					swap(books[i], books[j]);
				}
			}
		}
	}

	void sortNewspapersByEdition() 
	{
		for (int i = 0; i < newspaperCount - 1; ++i) 
		{
			for (int j = i + 1; j < newspaperCount; ++j) 
			{
				if (newspapers[i]->getEdition() > newspapers[j]->getEdition()) 
				{
					swap(newspapers[i], newspapers[j]);
				}
			}
		}
	}

	Book* searchBookByTitle(const string& title) 
	{
		for (int i = 0; i < bookCount; ++i) 
		{
			if (books[i]->getTitle() == title) 
			{
				return books[i];
			}
		}
		return nullptr;
	}

	Newspaper* searchNewspaperByName(const string& name) 
	{
		for (int i = 0; i < newspaperCount; ++i) 
		{
			if (newspapers[i]->getTitle() == name)
			{
				return newspapers[i];
			}
		}
		return nullptr;
	}
};

int main() {
	Library library;

	for (int i = 0; i < 2; ++i) 
	{
		string title, author;
		int pages;

		cout << "Enter details for Book " << (i + 1) << ":\n";
		cout << "Enter the Title: ";
		cin.ignore();
		cin >> title;
		cout << "Enter the Author: ";
		cin >> author;
		cout << "Enter the number of Pages: ";
		cin >> pages;

		library.addBook(Book(title, author, pages));
	}

	for (int i = 0; i < 2; ++i) 
	{
		string name, date, edition;

		cout << "Enter details for Newspaper " << (i + 1) << ":\n";
		cout << "Enter the Name: ";
		getline(cin, name);
		cout << "Enter the Date: ";
		getline(cin, date);
		cout << "Enter the Edition: ";
		getline(cin, edition);

		library.addNewspaper(Newspaper(name, date, edition));
	}

	cout << "\nBefore Sorting:\n";
	library.displayCollection();

	library.sortBooksByPages();
	library.sortNewspapersByEdition();

	cout << "\nAfter Sorting:\n";
	library.displayCollection();

	string searchTitle;
	cout << "\nEnter a book title to search: ";
	cin.ignore();  
	getline(cin, searchTitle);
	Book* foundBook = library.searchBookByTitle(searchTitle);
	if (foundBook) 
	{
		cout << "\nFound Book:\n";
		foundBook->display();
	}
	else 
	{
		cout << "\nBook not found.\n";
	}

	string searchName;
	cout << "\nEnter a newspaper name to search: ";
	getline(cin, searchName);
	Newspaper* foundNewspaper = library.searchNewspaperByName(searchName);
	if (foundNewspaper) 
	{
		cout << "\nFound Newspaper:\n";
		foundNewspaper->display();
	}
	else
	{
		cout << "\nNewspaper not found.\n";
	}

	return 0;
}