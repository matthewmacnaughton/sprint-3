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
	string loco_to_string();
	string torso_to_string();
	string battery_to_string();
	string arm_to_string();
	
	private:
		string name, descript, file;
		int number, bat_com, max_arm;
		double price, h_pow, loco_pow, arm_pow, bat_pow, energy;
	
};

string Robot_part::get_name() {return name;}
string Robot_part::get_descript() {return descript;}
string Robot_part::get_file() {return file;}
int Robot_part::get_number() {return number;}
double Robot_part::get_price() {return price;}

string Robot_part::head_to_string(){
	string part = "Part Name: " + name +"\n"+ "Part #: " + std::to_string(number) +"\n" + "Price: " + std::to_string(price) +"\n"+ 
	 "Description: " + descript +"\n"+ "Filename: " + file +"\n"+ "Head Power: " + std::to_string(h_pow) +"\n";
	return part;}

string Robot_part::loco_to_string(){
	string part = "Part Name: " + name +"\n"+ "Part #: " + std::to_string(number) +"\n" + "Price: " + std::to_string(price) +"\n"+ 
	 "Description: " + descript +"\n"+ "Filename: " + file +"\n"+ "Locomotor Power: " + std::to_string(loco_pow) +"\n";
	return part;}

string Robot_part::torso_to_string(){
	string part = "Part Name: " + name +"\n"+ "Part #: " + std::to_string(number) +"\n" + "Price: " + std::to_string(price) +"\n"+ 
	 "Description: " + descript +"\n"+ "Filename: " + file +"\n"+ "Battery Compartments: " + std::to_string(bat_com) +"\n"
		+ "Max arms for torso: " + std::to_string(max_arm) +"\n";
	return part;}

string Robot_part::battery_to_string(){
	string part = "Part Name: " + name +"\n"+ "Part #: " + std::to_string(number) +"\n" + "Price: " + std::to_string(price) +"\n"+ 
	 "Description: " + descript +"\n"+ "Filename: " + file +"\n"+ "Avalible Power: " + std::to_string(bat_pow) +"\n" 
		+ "Max Energy: " + std::to_string(energy) +"\n";
	return part;}

string Robot_part::arm_to_string(){
	string part = "Part Name: " + name +"\n"+ "Part #: " + std::to_string(number) +"\n" + "Price: " + std::to_string(price) +"\n"+ 
	 "Description: " + descript +"\n"+ "Filename: " + file +"\n"+ "Max Arm Power " + std::to_string(arm_pow) +"\n";
	return part;}

class model{
	public:
		model(string model_name, int model_num, Robot_part head, Robot_part loco, Robot_part torso, Robot_part battery, Robot_part arm) 
			: model_name(model_name), model_num(model_num), head(head), loco(loco), torso(torso), battery(battery), arm(arm) {}
		
		string to_string();
		string list();
	
		double cost(); // add get_price for all parts
	
		/*	double max_speed(); // max_energy / (loco_max_pwr + head_pwr) 
		double max_battery_life(); max_energy / ((pwr_avalible * bat_comps) - (head_pwr + loco_maxpwr + (arm_max_pwr * max_arms))) 
	*/
	private:
		string model_name;
		int model_num;
		Robot_part head;
		Robot_part loco;
		Robot_part torso;
		Robot_part battery;
		Robot_part arm;
	
};

string model::to_string(){
	string model = "\nModel Name: " + model_name +"\n"+ "Model #: " + std::to_string(model_num) +"\n ----------\n    HEAD\n ----------\n"
		+ head.head_to_string() + " ---------\n LOCOMOTOR\n ---------\n" + loco.loco_to_string() + " ---------\n   TORSO\n ---------\n"
		+ torso.torso_to_string() + " ---------\n  BATTERY\n ---------\n" + battery.battery_to_string() + " ---------\n    ARM\n ---------\n" 
		+ arm.arm_to_string();
	return model;
}

string model::list(){
	string model = model_name;
	return model;
}

double model::cost(){
	double cost = head.get_price() + loco.get_price() + torso.get_price() + battery.get_price() + arm.get_price();
	return cost;
}

class customer{
	public:
		customer(string name, int cust_num, string phone, string email) :  name(name), cust_num(cust_num), phone(phone), email(email) {}
	
		string to_string();
	
		customer(istream& in) {	
			in >> name >> phone >> email >> cust_num;}
	
		//void save(ostream& out) { out << name << ' ' phone << ' ' << email << ' ' << cust_name << ' '; }
		
	private:
		string name, phone, email;
		int cust_num;
};

string customer::to_string(){
	string info = "ID: " + std::to_string(cust_num) + ", " + name + ", Phone #:" + phone + ", Email: " + email;
	return info;
}


/*void customer::save (ostream& out){
	out << obj.name << ' ';
	out << obj.phone << ' ';
	out << obj.email << ' ';
	out << obj.cust_name << endl; 
	return out;
} */

class associate{
	public:
		associate(string name, int emp_num) :  name(name), emp_num(emp_num) {}
	
		string to_string();
	
	private:
		string name;
		int emp_num;
};

string associate::to_string(){
	string info = "ID: " + std::to_string(emp_num) + ", " + name;
	return info;
}

class order{
	public:
		order(string order_name, string date, customer cust, associate ass, model mod, int status) 
			: order_name(order_name), date(date), cust(cust), ass(ass), mod(mod), status(status) {}
		
		double cost();
		
		string to_string();
	
	private:
		string order_name, date;
		int status;
		customer cust;
		associate ass;
		model mod;
	
};

double order::cost(){
	double cost = mod.cost();
	return cost;
}

string order::to_string(){
	string order = "\nOrder Name: " + order_name +"\n"+ "Date: " + date + "\nCustomer: " + cust.to_string() + "\nAssociate: " + ass.to_string()
		+ "\nModel: " + mod.list() + "\nStatus: " + std::to_string(status);
	return order;
}

// /////////////////////////////////////
//            L I B R A R Y
// /////////////////////////////////////

class Library {
  public:
    void add_head(Robot_part head);
	void add_loco(Robot_part loco);
	void add_torso(Robot_part torso);
	void add_battery(Robot_part battery);
	void add_arm(Robot_part arm);
	
	void add_model(string mod_name, int mod_num, int head_sel, int loco_sel, int torso_sel, int battery_sel, int arm_sel);
	void add_order(string order_name, string date, int cust_sel, int ass_sel, int model_sel, int status); //*******ORDER*********
	
	void add_customer(customer cust);
	void add_associate(associate ass);
	
	int number_of_heads();
	int number_of_locos();
	int number_of_torsos();
	int number_of_batterys();
	int number_of_arms();
	int number_of_models();
	
	int number_of_orders(); //*******ORDER*********
	
	int number_of_custs();
	int number_of_asss();
	
    string hed_to_string(int head_index);
	string loco_to_string(int loco_index);
	string torso_to_string(int torso_index);
	string battery_to_string(int battery_index);
	string arm_to_string(int arm_index);
	
	string model_to_string(int model_index);
	string model_list_to_string(int model_index);
	double model_cost(int nodel_index);
	
	string order_to_string(int order_index); //*******ORDER*********
	
	string cust_to_string(int cust_index);
	string ass_to_string(int ass_index);
	
	void save_shop();
	void load_shop();

  private:
    vector<Robot_part> heads;
	vector<Robot_part> locos;
	vector<Robot_part> torsos;
	vector<Robot_part> batterys;
	vector<Robot_part> arms;
	
	vector<model> models;
	vector<order> orders; //*******ORDER*********
	
	vector<customer> customers;
	vector<associate> associates;

};

/*void Library::save_shop(){
	ost << "#customer" << endl;
	for(int i=0, i<customers.size(), i++)
		customers[i]->save(ost);
	
} */

void Library::add_head(Robot_part head) {
	heads.push_back(head);}
void Library::add_loco(Robot_part loco) {
	locos.push_back(loco);}
void Library::add_torso(Robot_part torso) {
	torsos.push_back(torso);}
void Library::add_battery(Robot_part battery) {
	batterys.push_back(battery);}
void Library::add_arm(Robot_part arm) {
	arms.push_back(arm);}

void Library::add_model(string mod_name, int mod_num, int head_sel, int loco_sel, int torso_sel, int battery_sel, int arm_sel) {
	model mod(mod_name, mod_num, heads[head_sel], locos[loco_sel], torsos[torso_sel], batterys[battery_sel], arms[arm_sel]);
	models.push_back(mod);}

void Library::add_order(string order_name, string date, int cust_sel, int ass_sel, int model_sel, int status) { //*******ORDER*********
	order ord(order_name, date, customers[cust_sel], associates[ass_sel], models[model_sel], status);
	orders.push_back(ord);}

string Library::hed_to_string(int head_index) {
	return heads[head_index].head_to_string();}
string Library::loco_to_string(int loco_index) {
	return locos[loco_index].loco_to_string();}
string Library::torso_to_string(int torso_index) {
	return torsos[torso_index].torso_to_string();}
string Library::battery_to_string(int battery_index) {
	return batterys[battery_index].battery_to_string();}
string Library::arm_to_string(int arm_index) {
	return arms[arm_index].arm_to_string();}

string Library::model_to_string(int model_index) {
	return models[model_index].to_string();}
string Library::model_list_to_string(int model_index) {
	return models[model_index].list();}
double Library::model_cost(int model_index) {
	return models[model_index].cost();}

string Library::order_to_string(int order_index) { //*******ORDER*********
	return orders[order_index].to_string();}

void Library::add_customer(customer cust) {
	customers.push_back(cust);}
void Library::add_associate(associate ass) {
	associates.push_back(ass);}

string Library::cust_to_string(int cust_index) {
	return customers[cust_index].to_string();}
string Library::ass_to_string(int ass_index) {
	return associates[ass_index].to_string();}

int Library::number_of_heads() {
	return heads.size();}
int Library::number_of_locos() {
	return locos.size();}
int Library::number_of_torsos() {
	return torsos.size();}
int Library::number_of_batterys() {
	return batterys.size();}
int Library::number_of_arms() {
	return arms.size();}

int Library::number_of_models() {
	return models.size();}

int Library::number_of_orders() { //*******ORDER*********
	return orders.size();}

int Library::number_of_custs() {
	return customers.size();}
int Library::number_of_asss() {
	return associates.size();}



// /////////////////////////////////////
//              V I E W
// /////////////////////////////////////

class View {
	public:
		View(Library& lib) : library(lib) { }
		string get_menu();
	
		string get_head_list();
		string get_loco_list();
		string get_torso_list();
		string get_battery_list();
		string get_arm_list();

		string get_model_list();
		string model_details(int mod_sel);
	
		string get_order_list(); //*******ORDER*********
		string order_confirm(int mod_sel, int quantity);
	
		string get_cust();
		string get_ass();

	private:
	Library& library;
}; 

string View::get_menu() {
    string menu = R"(
===============================
       Robot Parts Shop
===============================

(1) Create Part
(2) Create Model

(3) Add Customer
(4) Add Sales Associate

(5) Order a Robot

(6) Save
(7) Load

(8) List Models
(9) List Orders
(10) List Locomotors

(11) List Customers
(12) List Associates

(0) Exit 
)";
    return menu;}

string View::get_head_list() {
  string list = R"(
---------------------------
       List of Heads
---------------------------
)";
  for (int i=0; i<library.number_of_heads(); ++i) {
    list += "Head " + std::to_string(i) + ") \n" + library.hed_to_string(i) + '\n';
  } 
  return list;}

string View::get_loco_list() {
  string list = R"(
----------------------------
     List of Locomotors
----------------------------
)";
  for (int i=0; i<library.number_of_locos(); ++i) {
    list += "Locomotor " + std::to_string(i) + ") \n" + library.loco_to_string(i) + '\n';
  } 
  return list;}

string View::get_torso_list() {
  string list = R"(
----------------------------
     List of Torsos
----------------------------
)";
  for (int i=0; i<library.number_of_torsos(); ++i) {
    list += "Torso " + std::to_string(i) + ") \n" + library.torso_to_string(i) + '\n';
  } 
  return list;}

string View::get_battery_list() {
  string list = R"(
----------------------------
     List of Batteries
----------------------------
)";
  for (int i=0; i<library.number_of_batterys(); ++i) {
    list += "Battery " + std::to_string(i) + ") \n" + library.battery_to_string(i) + '\n';
  } 
  return list;}

string View::get_arm_list() {
  string list = R"(
----------------------------
     List of Arms
----------------------------
)";
  for (int i=0; i<library.number_of_arms(); ++i) {
    list += "Arm " + std::to_string(i) + ") \n" + library.arm_to_string(i) + '\n';
  } 
  return list;}

string View::get_model_list() {
  string list = R"(
----------------------------
       List of Models
----------------------------
)";
  for (int i=0; i<library.number_of_models(); ++i) {
    list += "Model " + std::to_string(i) + ") " + library.model_list_to_string(i) + "- $" + std::to_string(library.model_cost(i)) + '\n';
  } 
  return list;}

string View::get_order_list() {  //*******ORDER*********
  string list = R"(
----------------------------
       List of Orders
----------------------------
)";
  for (int i=0; i<library.number_of_orders(); ++i) {
    list += "\nOrder " + std::to_string(i) + ") " + library.order_to_string(i) + '\n';
  } 
  return list;}

string View::order_confirm(int mod_sel, int quantity){
	string confirm;
	double mod_cost = library.model_cost(mod_sel) * quantity;
	confirm = "\nThank you for your purchase, total is: " + std::to_string(mod_cost) + '\n';
	return confirm;
}

string View::model_details(int mod_sel) {
	string list;

	list = library.model_to_string(mod_sel) + '\n';
  
  return list;}

string View::get_cust() {
  string list = R"(
---------------------------
     List of Customers
---------------------------
)";
  for (int i=0; i<library.number_of_custs(); ++i) {
    list += "Customer " + std::to_string(i) + ") " + library.cust_to_string(i) + '\n';
  } 
  return list;}

string View::get_ass() {
  string list = R"(
----------------------------
     List of Associates
----------------------------
)";
  for (int i=0; i<library.number_of_asss(); ++i) {
    list += "Associate " + std::to_string(i) + ") " + library.ass_to_string(i) + '\n';
  } 
  return list;}

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

// /////////////////////////////////////
//          C O M M A N D S
// /////////////////////////////////////

void Controller::execute_cmd(int cmd) {
  if (cmd == 1) { // Add part
    string part_name, description, filename;
    int number, type, bat_com, max_arm;
	double cost, h_pow, loco_pow, arm_pow, bat_pow, energy;

	type = get_int("1: Head \n2) Locomotor\n3) Torso\n4) Battery\n5) Arm\nPart Type #: ");
	  
    cout << "Part Name? ";
    getline(cin, part_name);

    cout << "Description? ";
    getline(cin, description);

    cout << "Image Filename? ";
    getline(cin, filename);

    number = get_int("Part Number? ");

    cost = get_double("Cost? ");
	  
	if(type == 1){ //head
		h_pow = get_double("Head Power? ");
		Robot_part head(part_name, number, cost, description, filename, h_pow, 0, 0, 0, 0, 0, 0);
		library.add_head(head);}
	  
	  if(type == 2){ //locomotor
		loco_pow = get_double("Locomotor Power? ");
		Robot_part loco(part_name, number, cost, description, filename, 0, loco_pow, 0, 0, 0, 0, 0);
		library.add_loco(loco);}
	  
	  if(type == 3){ //torso
		bat_com = get_int("Number of Battery Compartments? ");
		max_arm = get_int("Max Number of Arms Possible? ");
		Robot_part torso(part_name, number, cost, description, filename, 0, 0, bat_com, max_arm, 0, 0, 0);
		library.add_torso(torso);}
	  
	  if(type == 2){ //battery
		bat_pow = get_double("Battery Power? ");
		energy = get_double("Amount of Energy? ");
		Robot_part battery(part_name, number, cost, description, filename, 0, 0, 0, 0, 0, bat_pow, energy);
		library.add_battery(battery);}
	  
	  if(type == 2){ //arm
		arm_pow = get_double("Arm Power? ");
		Robot_part arm(part_name, number, cost, description, filename, 0, 0, 0, 0, arm_pow, 0, 0);
		library.add_arm(arm);}
	  
} 
	
	else if (cmd == 2) { // Create model
		string mod_name;
		int mod_num, head_sel, loco_sel, torso_sel, battery_sel, arm_sel;
		
		cout << "Model Name? ";
    	getline(cin, mod_name);
		
		mod_num = get_int("Model Number? ");
		
		cout << view.get_head_list();
		head_sel = get_int("Select the head for your model: ");
				
		cout << view.get_loco_list();
		loco_sel = get_int("Select the locomotor for your model: ");
		
		cout << view.get_torso_list();
		torso_sel = get_int("Select the torso for your model: ");
		
		cout << view.get_battery_list();
		battery_sel = get_int("Select the battery for your model: ");
		
		cout << view.get_arm_list();
		arm_sel = get_int("Select the arm for your model: ");
		
		library.add_model(mod_name, mod_num, head_sel, loco_sel, torso_sel, battery_sel, arm_sel);
	}
	
		else if (cmd == 3) { // add customer
		string name, phone, email;
		int cust_num;
		
		cout << "Customer Name? ";
    	getline(cin, name);
		
		cust_num = get_int("ID Number? ");
		
		cout << "Phone #? ";
    	getline(cin, phone);
			
		cout << "Email? ";
    	getline(cin, email);
		
		library.add_customer(customer(name, cust_num, phone, email));
	}
	
	else if (cmd == 4) { // add associate
		string name;
		int emp_num;
		
		cout << "Associate Name? ";
    	getline(cin, name);
		
		emp_num = get_int("ID Number? ");
		
		library.add_associate(associate(name, emp_num));
	}
	
		else if (cmd == 5) {                                                           // *******ORDER***********
			string order_name, date;
			int status, cust_sel, ass_sel, model_sel, quantity;

			cout << "\nOrder Name? ";
			getline(cin, order_name);

			cout << "Date? ";
			getline(cin, date);

			cout << view.get_cust();
			cust_sel = get_int("\nSelect the customer: ");

			cout << view.get_ass();
			ass_sel = get_int("\nSelect the associate: ");

			cout << view.get_model_list();
			model_sel = get_int("\nSelect the model: ");

			status = get_int("\nStatus? ");

			quantity = get_int("\nHow many would you like to buy? ");

			library.add_order(order_name, date, cust_sel, ass_sel, model_sel, status);
			
			cout << view.order_confirm(model_sel, quantity);
		
	}
	
	else if (cmd == 8) { // List all models
		int mod_sel;
    	cout << view.get_model_list();
		mod_sel = get_int("\nSelect the model to view: ");
		cout << view.model_details(mod_sel);}
	
	else if (cmd == 9) { // List all orders
    	cout << view.get_order_list();}
	
	else if (cmd == 10) { // List all locos
    	cout << view.get_loco_list();}
	
	else if (cmd == 11) { // List all cust
    	cout << view.get_cust();}
	
	else if (cmd == 12) { // List all ass
    	cout << view.get_ass();}
	
	else if (cmd == 99) { // easter egg
    	library.add_head(Robot_part("head1", 9999999, 100, "head1 descript", "head1filename", 20.5, 0, 0, 0, 0, 0, 0));
		library.add_head(Robot_part("head2", 666666, 200, "head2 descript", "head2file", 1, 0, 0, 0, 0, 0, 0));
		
		library.add_loco(Robot_part("loco1", 8888, 100, "loco1 descript", "loco1filename", 0, 43.82, 0, 0, 0, 0, 0));
		library.add_loco(Robot_part("loco2", 33333, 200, "loco2 descript", "locofile", 0, 56, 0, 0, 0, 0, 0));
		
		library.add_torso(Robot_part("torso1", 11, 100, "torso1 descript", "torsofile", 0, 0, 4, 4, 0, 0, 0));
		library.add_torso(Robot_part("torso2", 12, 200, "torso2 descript", "torso2file", 0, 0, 6, 6, 0, 0, 0));
		
		library.add_battery(Robot_part("battery1", 21, 100, "battery1 descript", "bat1file", 0, 0, 0, 0, 0, 100, 1000));
		library.add_battery(Robot_part("battery2", 23, 200, "battery2 descript", "bat2file", 0, 0, 0, 0, 0, 200, 2000));
		
		library.add_arm(Robot_part("arm1", 31, 100, "arm1 descript", "arm1file", 0, 0, 0, 0, 30, 0, 0));
		library.add_arm(Robot_part("arm2", 33, 200, "arm2 descript", "arm2file", 0, 0, 0, 0, 60, 0, 0));
		
		library.add_customer(customer("test customer", 1234, "214-555-5555", "customer@gmail"));
		library.add_associate(associate("test associate", 4321));
  }
}

// /////////////////////////////////////
//          M A I N
// /////////////////////////////////////

int main() {
  Library library;
  View view{library};
  Controller controller(library, view);
  controller.cli();
}



