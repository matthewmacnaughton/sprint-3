#include <string>
#include <iostream>
#include <vector>
#include <exception>

using namespace std;

// /////////////////////////////////////
//    A G E   G E N R E   M E D I A
// /////////////////////////////////////

class Age {
  public:
    Age(int val) : value(val) { }

    static const int children = 0;
    static const int teen = 1;
    static const int adult = 2;
    static const int restricted = 3;

    static const int num_ages = 4;

    string to_string() {
      switch(value) {
        case(children):return "children";
        case(teen):return "teen";
        case(adult):return "adult";
        case(restricted):return "restricted";
        default: return "UNKNOWN";
      }
    }
  private:
    int value;
};

class Genre {
  public:
    Genre(int val) : value(val) { }

    static const int fiction = 0;
    static const int nonfiction = 1;
    static const int selfhelp = 2;
    static const int performance = 3;

    static const int num_genres = 4;

    string to_string() {
      switch(value) {
        case(fiction):return "fiction";
        case(nonfiction):return "nonfiction";
        case(selfhelp):return "selfhelp";
        case(performance):return "performance";
        default: return "UNKNOWN";
      }
    }
  private:
    int value;
};

class Media {
  public:
    Media(int val) : value(val) { }

    static const int book = 0;
    static const int periodical = 1;
    static const int newspaper = 2;
    static const int audio = 3;
    static const int video = 4;

    static const int num_media = 5;

    string to_string() {
      switch(value) {
        case(book):return "book";
        case(periodical):return "periodical";
        case(newspaper):return "newspaper";
        case(audio):return "audio";
        case(video):return "video";
        default: return "UNKNOWN";
      }
    }
  private:
    int value;
};

// /////////////////////////////////////
//            P A T R O N
// /////////////////////////////////////

class Patron {
  public:
    Patron(string patron_name, string patron_phone_number)
      : name(patron_name), number(patron_phone_number) {}
    Patron() : name("unknown"), number("unknown") {}

    string to_string();

    string get_patron_name();
    string get_patron_phone_number();

  private:
    string name;
    string number;
};

string Patron::to_string() {return name + " (" + number + ")";}
string Patron::get_patron_name() {return name;}
string Patron::get_patron_phone_number() {return number;}

// /////////////////////////////////////
//        P U B L I C A T I O N 
// /////////////////////////////////////
class Publication {
  public:
    Publication(string p_title,
                string p_author,
                string p_copyright,
                Genre p_genre,
                Media p_media,
                Age p_target_age,
                string p_isbn) :

                title(p_title),
                author(p_author),
                copyright(p_copyright),
                genre(p_genre),
                media(p_media),
                target_age(p_target_age),
                isbn(p_isbn),
                patron(Patron()),
                checked_out(false) { }

    bool is_checked_out();

    void check_out(Patron patron);
    void check_in();

    string to_string();

    // Thrown on check_in if publication isn't checked out
    //   or on cheeck_out if publication is already checked out
    class Invalid_transaction : public exception { };

  private:
    string title;
    string author;
    string copyright;
    Genre genre;
    Media media;
    Age target_age;
    string isbn;
    Patron patron;
    bool checked_out;
};

bool Publication::is_checked_out() {return checked_out;}
void Publication::check_out(Patron p_patron) {
  if (checked_out) {
    throw Invalid_transaction();
  } else {
    patron = p_patron;
    checked_out = true;
  }
}

void Publication::check_in() {
  if (checked_out) {
    checked_out = false;
  } else {
    throw Invalid_transaction();
  }
}

string Publication::to_string() {
  string pub = "\"" + title + "\"" + " by " + author + ", " + copyright +
    " (" + target_age.to_string() + " " + genre.to_string() + " "
        + media.to_string() + ") " + "ISBN: " + isbn;
  if (checked_out) {
     pub += "\nChecked out to " + patron.get_patron_name() +
            " (" + patron.get_patron_phone_number() + ")";
  }
  return pub;
}
 
// /////////////////////////////////////
//            L I B R A R Y
// /////////////////////////////////////

class Library {
  public:
    void add_publication(Publication pub);
    void add_patron(Patron pat);

    void check_out(int publication_index, int patron_index);
    void check_in(int publication_index);

    string publication_to_string(int publication_index);
    string patron_to_string(int patron_index);

    int number_of_publications();
    int number_of_patrons();

    void easter_egg();
  private:
    vector<Publication> publications;
    vector<Patron> patrons;
};

void Library::add_publication(Publication pub) {
  publications.push_back(pub);
}

void Library::add_patron(Patron pat) {
  patrons.push_back(pat);
}

void Library::check_out(int publication_index, int patron_index) {
  publications[publication_index].check_out(patrons[patron_index]);
}

void Library::check_in(int publication_index) {
  publications[publication_index].check_in();
}

string Library::publication_to_string(int publication_index) {
  return publications[publication_index].to_string();
}

 

int Library::number_of_publications() {
  return publications.size();
}

int Library::number_of_patrons() {
  return patrons.size();
}

void Library::easter_egg() {
  add_publication(Publication("The Firm", "John Grisham", "1991",
       Genre::fiction, Media::book, Age::adult, "0440245923"));
  add_publication(Publication("Foundation", "Isaac Asimov", "1942",
        Genre::fiction, Media::book, Age::adult, "0385177259"));
  add_publication(Publication("Foundation and Empire", "Isaac Asimov", "1943",
        Genre::fiction, Media::book, Age::adult, "0385177259"));
  add_publication(Publication("Second Foundation", "Isaac Asimov", "1944",
        Genre::fiction, Media::book, Age::adult, "0385177259"));
  add_publication(Publication("War of the Worlds", "Jeff Wayne", "1977",
        Genre::performance, Media::audio, Age::teen, "9780711969148"));
  add_publication(Publication("Willy Wonka and the Chocolate Factory", "Roald Dahl", "1971",
        Genre::performance, Media::video, Age::children, "0142410314"));
  add_patron(Patron("Larry", "817-555-1111"));
  add_patron(Patron("Curly", "817-555-2222"));
  add_patron(Patron("Moe", "817-555-3333"));
}

// /////////////////////////////////////
//              V I E W
// /////////////////////////////////////

class View {
  public:
    View(Library& lib) : library(lib) { }
    string get_menu();
    string get_publication_list();
    string get_patron_list();
    string get_age_list();
    string get_genre_list();
    string get_media_list();
    string get_help();
  private:
    Library& library;
};

string View::get_menu() {
    string menu = R"(
===============================
C1325 Library Management System
===============================

Publications
------------
(1) Add publication
(2) List all publications
(3) Check out publication
(4) Check in publication

Patrons
-------
(5) Add patron
(6) List all patrons

Utility
-------
(9) Help
(0) Exit 
)";
    return menu;
}

string View::get_publication_list() {
  string list = R"(
----------------------------
List of Library Publications
----------------------------
)";
  for (int i=0; i<library.number_of_publications(); ++i) {
    list += std::to_string(i) + ") " + library.publication_to_string(i) + '\n';
  }
  return list;
}

string View::get_patron_list() {
  string list = R"(
-----------------------
List of Beloved Patrons
-----------------------
)";
  for (int i=0; i<library.number_of_patrons(); ++i) {
    list += std::to_string(i) + ") " + library.patron_to_string(i) + '\n';
  }
  return list;
}

string View::get_genre_list() {
  string list = "";
  for (int i = 0; i < Genre::num_genres; ++i)
    list += "  " + std::to_string(i) + ") " + Genre(i).to_string() + '\n';
  return list;
}

string View::get_media_list() {
  string list = "";
  for (int i = 0; i < Media::num_media; ++i)
    list += "  " + std::to_string(i) + ") " + Media(i).to_string() + '\n';
  return list;
}

string View::get_age_list() {
  string list = "";
  for (int i = 0; i < Age::num_ages; ++i)
    list += "  " + std::to_string(i) + ") " + Age(i).to_string() + '\n';
  return list;
}

string View::get_help() {
  return "Try harder.";
}


// /////////////////////////////////////
//          C O N T R O L L E R
// /////////////////////////////////////

class Controller {
  public:
    Controller (Library& lib, View& view) : library(lib), view(view) { }
    void cli();
    void execute_cmd(int cmd);
  private:
    int get_int(string prompt, int max_int);
    Library& library;
    View& view;
};

void Controller::cli() {
  int cmd = -1;
  while (cmd != 0) {
    cout << view.get_menu() << endl;
    cout << "Command? ";
    cin >> cmd;
    cin.ignore(); // consume \n
    execute_cmd(cmd);
  }
}

int Controller::get_int(string prompt, int max_int) {
  int result;
  while(true) {
    cout << prompt;
    cin >> result;
    cin.ignore(); // consume \n
    if (0 <= result && result <= max_int) break;
    cout << "Please enter an integer between 0 and " << max_int << endl;
  }
  return result;
}

void Controller::execute_cmd(int cmd) {
  if (cmd == 1) { // Add publication
    string title, author, copyright, isbn;
    int genre, media, age;

    cout << "Title? ";
    getline(cin, title);

    cout << "Author? ";
    getline(cin, author);

    cout << "Copyright date? ";
    getline(cin, copyright);

    cout << view.get_genre_list();
    genre = get_int("Genre number? ", Genre::num_genres - 1);

    cout << view.get_media_list();
    media = get_int("Media number? ", Media::num_media - 1);

    cout << view.get_age_list();
    age = get_int("Age number? ", Age::num_ages - 1);

    cout << "ISBN? ";
    getline(cin, isbn);

    library.add_publication(Publication(title, author, copyright, genre, media, age, isbn));

 } else if (cmd == 2) { // List all publications
    cout << view.get_publication_list();

 } else if (cmd == 3) { // Check out publication
    int pub, pat;

    cout << view.get_publication_list();
    pub = get_int("Publication number? ", library.number_of_publications() - 1);

    cout << view.get_patron_list();
    pat = get_int("Patron number? ", library.number_of_patrons() - 1);

    try {
      library.check_out(pub, pat);
    } catch (Publication::Invalid_transaction e) {
      cerr << "##### That publication is not available for check out" << endl;
    }

 } else if (cmd == 4) { // Check in publication
    int pub;
    cout << view.get_publication_list();
    pub = get_int("Publication number? ", library.number_of_publications() - 1);

    try {
      library.check_in(pub);
    } catch (Publication::Invalid_transaction e) {
       cerr << "##### That publication is not available for check in" << endl;
    }

 } else if (cmd == 5) { // Add patron
    string name, number;

    cout << "Name? ";
    getline(cin, name);
    cout << "Phone number? ";
    getline(cin, number);
    library.add_patron(Patron(name, number));

 } else if (cmd == 6) { // List all patrons
    cout << view.get_patron_list();

 } else if (cmd == 9) { // Help
    cout << view.get_help();
 } else if (cmd == 0) { // Exit
 } else if (cmd == 99) { // Easter Egg
   library.easter_egg();
 } else {
   cerr << "**** Invalid command - type 9 for help" << endl << endl;
 }
}

// /////////////////////////////////////
//               M A I N
// /////////////////////////////////////

int main() {
  Library library;
  View view{library};
  Controller controller(library, view);
  controller.cli();
}

