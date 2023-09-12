#include <iostream>
#include <vector>
#include <string>

struct bookT
{
    std::string title;
    std::string authors[5];
    std::string catalogNumber;
    std::string subjectHeadings[5];
    std::string publisher;
    int year;
    bool isCirculating;
};

struct libraryT
{
    std::vector<bookT> books;

    void searchBySubject(std::string subject)
    {
        for (const bookT &book : books)
        {
            for (const std::string &heading : book.subjectHeadings)
            {
                if (heading == subject)
                {
                    std::cout << "Title: " << book.title << ", Author: " << book.authors[0] << ", Catalog Number: " << book.catalogNumber << std::endl;
                    break;
                }
            }
        }
    }

    void displayAllBooks()
    {
        std::cout << "All Books:" << std::endl;
        for (const bookT &book : books)
        {
            std::cout << "Title: " << book.title << ", Author: " << book.authors[0] << ", Catalog Number: " << book.catalogNumber << std::endl;
        }
    }
};

int main()
{
    libraryT libdata;
    libdata.books.push_back({"Book1", {"Author1"}, "12345", {"Subject1", "Subject2"}, "Publisher1", 2021, true});
    libdata.books.push_back({"Book2", {"Author2"}, "67890", {"Subject3", "Subject4"}, "Publisher2", 2022, false});
    int choice;
    std::string subject;
    std::string title;
    std::string authors[5];
    std::string catalogNumber;
    std::string subjectHeadings[5];
    std::string publisher;
    int year;
    bool isCirculating;
    bookT newBook;
    while (true)
    {
        std::cout << "\nMenu:\n1. Add a new book\n2. Search by subject\n3. Display all books\n4. Quit\nEnter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Enter book imformation: \n";
            std::cin >> newBook.title >> newBook.authors[0] >> newBook.catalogNumber >> newBook.subjectHeadings[0] >> newBook.publisher >> newBook.year >> newBook.isCirculating;
            libdata.books.push_back(newBook);

        case 2:
            std::cout << "Enter subject to search: ";
            std::cin >> subject;
            libdata.searchBySubject(subject);
            break;
        case 3:
            libdata.displayAllBooks();
            break;
        case 4:
            return 0;
        }
    }

    return 0;
}
