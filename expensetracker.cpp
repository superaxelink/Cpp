#include <iostream>
#include <stdlib.h>
#include <string>
#include <list>

class ExpenseItem{
	private:
		int id;
		std::string date;
		std::string description;
		std::string category;
		double amount;

	public:
		ExpenseItem() : id(0), date(""), description(""), category(""), amount(0) {

		}
		~ExpenseItem() = default;

		bool create(std::string new_date, std::string new_description, std::string new_category){
			id = rand() % 100 + 1; 
			date = new_date;
			description = new_description;
			category = new_category;
			return true;
		}
		void setAmount(double new_amount) {amount = new_amount;}
		void setDate(std::string new_date) {date = new_date;}
		void setDescription(std::string new_description) {description = new_description;}
		void setCategory(std::string new_category) {category = new_category;}
		std::string getDate() {return date;}
		std::string getDescription() {return description;}
		std::string getCategory() {return category;}
		double getAmount() {return amount;}
		int getId() {return id;}
};

int main()
{
	std::list<ExpenseItem> expenses;
	std::list<ExpenseItem>::iterator it;
	std::string version = "v0.0.1";
	char input_option;
	
	expenses.clear();

	while(1){
		system("clear");
		std::cout<<"Expense tracker -" << version << std:: endl;
		
		std::cout << "Id | Date | Description | Category | Amount" << std::endl;
		for(it = expenses.begin(); it != expenses.end(); it++){
			std::cout
							<< it->getId() << " | "
							<< it->getDate() << " | "
							<< it->getDescription() << " | "
							<< it->getCategory() << " | "
							<< it->getAmount() <<std::endl;
		}
		if(expenses.empty()){
			std::cout << "Add a new expense "<< std::endl;
		}
		std::cout << "[a]-add a new expense"<< std::endl;
		std::cout << "[m]-modify date" << std::endl;
		std::cout << "[d]-change description"<< std:: endl;
		std::cout << "[c]-change category" << std::endl;
		std::cout << "[t]-change amount " << std::endl;
		std::cout << "[q]-quit" << std::endl;

		std::cout << "choice: ";
		std::cin >> input_option;
		std::cin.clear();
		std::cin.ignore();
		if(input_option == 'q'){
			std::cout << "Have a nice day!" << std:: endl;
			break;
		}
		else if(input_option == 'a'){
			std::string new_date;
			std::string new_description;
			std::string new_category;
			double new_amount;

			std::cout << "Enter a new expense date: ";
			std::getline(std::cin, new_date);

			std::cout << "Enter a new expense description: ";
			std::getline(std::cin, new_description);

			std::cout << "Enter a new expense category: ";
			std::getline(std::cin, new_category);

			std::cout << "Enter a new expense amount: ";
			std::cin >> new_amount;
			std::cin.clear();
			std::cin.ignore();

			ExpenseItem item;
			item.create(new_date, new_description, new_category);
			item.setAmount(new_amount);
			expenses.push_back(item);
		}
		else if(input_option == 'm'){
			int expense_id;
			std::string new_date;
			
			std::cout << "Enter id of expense: ";
			std::cin >> expense_id;
			for(it = expenses.begin(); it != expenses.end(); it++){
				if(expense_id == it->getId()){
					std::cout<<"Enter a new date: ";
					std::cin.clear();
					std::cin.ignore();
					std::getline(std::cin, new_date);

					it->setDate(new_date);
					break;
				}
			}
		}
		else if(input_option == 'd'){
			int expense_id;
			std::string new_description;
			
			std::cout << "Enter id of expense: ";
			std::cin >> expense_id;
			for(it = expenses.begin(); it != expenses.end(); it++){
				if(expense_id == it->getId()){
					std::cout<<"Enter a new description: ";
					std::cin.clear();
					std::cin.ignore();
					std::getline(std::cin, new_description);

					it->setDescription(new_description);
					break;
				}
			}
		}
		else if(input_option == 'c'){
			int expense_id;
			std::string new_category;
			
			std::cout << "Enter id of expense: ";
			std::cin >> expense_id;
			for(it = expenses.begin(); it != expenses.end(); it++){
				if(expense_id == it->getId()){
					std::cout<<"Enter a new category: ";
					std::cin.clear();
					std::cin.ignore();
					std::getline(std::cin, new_category);

					it->setCategory(new_category);
					break;
				}
			}
		}
		else if(input_option == 't'){
			int expense_id;
			double new_amount;
			
			std::cout << "Enter id of expense: ";
			std::cin >> expense_id;
			for(it = expenses.begin(); it != expenses.end(); it++){
				if(expense_id == it->getId()){
					std::cout<<"Enter a new amount: ";
					std::cin>>new_amount;

					it->setAmount(new_amount);
					break;
				}
			}
		}
	}
	return 0;
}
