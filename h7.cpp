#include <string>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

class Robot_part{
	public:
		Robot_part(string part_name, int model_number, double cost, string description, string image_filename, double head_power, double loco_max_power, 
				  int battery_comp, int max_arms, double arm_max_power, double bat_power, double max_energy)
			: name(part_name), number(model_number), price(cost), descript(description), file(image_filename), h_pow(head_power), loco_pow(loco_max_power),
				bat_com(battery_comp), max_arm(max_arms), arm_pow(arm_max_power), bat_pow(bat_power), energy(max_energy)   {}
	
		Robot_part() : name("unknown"), number(0), price(0.00), descript("unknown"), file("unknown"), h_pow(0), loco_pow(0), bat_com(0),
						max_arm(0), arm_pow(0), bat_pow(0), energy(0) {}
	
	string get_name();
	string get_descript();
	string get_file();
	int get_number();
	double get_price();
	string head_to_string();
	
	private:
		string name;
		string descript;
		string file;
		int number;
		double price;
		double h_pow;
		double loco_pow;
		int bat_com;
		int max_arm;
		double arm_pow;
		double bat_pow;
		double energy;
	
};

string Robot_part::get_name() {return name;}
string Robot_part::get_descript() {return descript;}
string Robot_part::get_file() {return file;}
int Robot_part::get_number() {return number;}
double Robot_part::get_price() {return price;}

string Robot_part::head_to_string(){
	string part = "part name: " + name +"\n"+ "part number: " + std::to_string(number) +"\n" + "price: " + std::to_string(price) +"\n"+ 
	 "description: " + descript +"\n"+ "filename: " + file +"\n"+ "Head power: " + std::to_string(h_pow) +"\n" /*+ "locomotor power:"+ 
	std::to_string(loco_pow) + std::to_string(bat_com) + std::to_string(max_arm) + std::to_string(arm_pow) +
	std::to_string(bat_pow) + std::to_string(energy)*/;
	return part;
}


/*class Head{
	public:
		Head(double h_power, Robot_part& Headpart) :  power(h_power), Headpart(Headpart)  { }
	
		string to_string();
	
	private:
		double power; 
		Robot_part& Headpart;
		
};

 */

// /////////////////////////////////////
//            L I B R A R Y
// /////////////////////////////////////

class Library {
  public:
    void add_part(Robot_part part);
	void easter_egg();
	int number_of_models();

    string hed_to_string(int part_index);

  private:
    vector<Robot_part> parts;

};

void Library::add_part(Robot_part part) {
  parts.push_back(part);
}

string Library::hed_to_string(int part_index) {
  return parts[part_index].head_to_string();
}

void Library::easter_egg() {


}

int Library::number_of_models() {
  return parts.size();
}

// /////////////////////////////////////
//              V I E W
// /////////////////////////////////////

class View {
	public:
	
	View(Library& lib) : library(lib) { }
    string get_menu();
    string get_model_list();

	
	private:
	Library& library;
}; 

string View::get_menu() {
    string menu = R"(
===============================
       Robot Parts Shop
===============================

Robots
------------
(1) Create Part
(2) Create Model
(3) Print Model

(0) Exit 
)";
    return menu;
}

string View::get_model_list() {
  string list = R"(
----------------------------
	   List of Models
----------------------------
)";
  for (int i=0; i<library.number_of_models(); ++i) {
    list += std::to_string(i) + ") " + library.hed_to_string(i) + '\n';
  } 
  return list;
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
    int get_int(string prompt);
	double get_double(string prompt);
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

int Controller::get_int(string prompt) {
  int result;
    cout << prompt;
    cin >> result;
    cin.ignore(); // consume \n

  return result;
}

double Controller::get_double(string prompt) {
  double result;
  while(true) {
    cout << prompt;
    cin >> result;
    cin.ignore(); // consume \n
    if (0 <= result) break;
    cout << "Please enter a double greater than 0 " << endl;
  }
  return result;
}

void Controller::execute_cmd(int cmd) {
  if (cmd == 1) { // Add part
    string part_name, description, filename;
    int number, type, bat_com, max_arm;
	double cost, h_pow, loco_pow, arm_pow, bat_pow, energy;

	type = get_int("1: Head \n2: locomotor\n3: torso\n4: Battery\n5: Arm\nPart Type:");
	  
    cout << "Part Name? ";
    getline(cin, part_name);

    cout << "Description? ";
    getline(cin, description);

    cout << "Image filename? ";
    getline(cin, filename);

    number = get_int("Part number? ");

    cost = get_double("Cost? ");
	  
	if(type == 1){
		
		h_pow = get_double("Head Power? ");
		
		Robot_part part(part_name, number, cost, description, filename, h_pow, 0, 0, 0, 0, 0, 0);
		
		library.add_part(part);
	}

 } else if (cmd == 3) { // List all models
    cout << view.get_model_list();
  }
}

int main() {
  Library library;
  View view{library};
  Controller controller(library, view);
  controller.cli();
	/*
	Robot_part part("test part", 1100001, 4.20,  "this is a test part", "testpart.file"); 
	Head head(2.50, part);
	cout << head.to_string(); */
}