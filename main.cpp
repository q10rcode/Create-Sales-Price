/**************************************************************
* PROGRAMMED BY : Quinten Ridley
* PROJECT 03	: Functions
* CLASS			: CSC5
* SECTION		: MW 2:20PM-5:30PM
* DUE DATE		: 11/3/21
**************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/**************************************************************
 *
 * CALCULATE SALES PRICE
 * ____________________________________________________________
 *
 * This program will collect user data such as the account
 * number, date of the purchase, the county it was purchased in
 * the price of the sale, and the weight of the sale.
 * The program will take those inputs to find things like the
 * sales tax, shipping price, and discount. The program will
 * display the sale amount, discount, sales tax, shipping price,
 * and the total amount due.
 **************************************************************/

/**************************************************************
 * GetSalesInfo
 * ____________________________________________________________
 * This function gets user input for the variables:
 * accountNumber, month, day, year, countyCode, saleAmount, and
 * weight. It changes the values of these variables in main
 * because they are passes by reference.
 * ____________________________________________________________
 * INPUT
 * accountNumber		:User's account number
 * month				:Month of the sale
 * day					:Day of the sale
 * year					:Year of the sale
 * countyCode			:User's county code
 * saleAmount			:Price of the sale (Before tax)
 * weight				:The weight of the product
 *
 * OUTPUT
 * accountNumber		:User's account number
 * month				:Month of the sale
 * day					:Day of the sale
 * year					:Year of the sale
 * countyCode			:User's county code
 * saleAmount			:Price of the sale (Before tax)
 * weight				:The weight of the product
 **************************************************************/
void GetSalesInfo(int& accountNumber, //Changes accountNumber
				  int& month,		  //Changes month
				  int& day,			  //Changes day
				  int& year,		  //Changes year
				  char& countyCode,   //Changes countyCode
				  float& saleAmount,  //Changes saleAmount
				  int& weight		  //Changes weight
				  );

/**************************************************************
 * CalcDiscount
 * ____________________________________________________________
 * This function gets month and saleAmount. It uses month
 * for a if else statement that will decide what saleAmount
 * is multiplied by. The product is then stored in discount
 * which is returned from the function.
 * ____________________________________________________________
 * INPUT
 * month				:Month of the sale
 * saleAmount			:Price of the sale (Before tax)
 *
 * OUTPUT
 * discount				:Discount based on month
 **************************************************************/
float CalcDiscount(int month,		//Uses for if else statement
				   float saleAmount //Uses for calculation
				   );

/**************************************************************
 * CalcSalesTax
 * ____________________________________________________________
 * This function gets countyCode, saleAmount, and discount by
 * value. The variable countyName is passed by reference.It
 * subtracts the discount from the saleAmount because the
 * sales tax is taken after the discount is applied.
 * Then the function uses countyCode for a switch statement.
 * In each branch of the switch statement saleAmount is
 * multiplied by the rate of the county and countyName is set
 * equal to whichever county is being represented with
 * countyCode. The function then returns the variable salesTax
 * which holds the product of the sale amount and county rate.
 * ____________________________________________________________
 * INPUT
 * countyCode			:User's county code
 * saleAmount			:Price of the sale (Before tax)
 * countyName			:Name of the county
 * discount				:Discount based on month
 *
 * OUTPUT
 * salesTax				:Tax depending on county
 **************************************************************/
float CalcSalesTax(char countyCode,		//Used for switch
				   float saleAmount,	//Used for calculation
				   string& countyName,	//Changes countyName
				   float discount		//Returns
				   );

/**************************************************************
 * CalcShipping
 * ____________________________________________________________
 * This function gets the variable weight by value. It uses
 * weight for some if else statements that determine the value
 * that is stored in shippingPrice. shippingPrice is then
 * returned to main.
 * ____________________________________________________________
 * INPUT
 * weight				:The weight of the product
 *
 * OUTPUT
 * shippingPrice		:Price of the shipping
 **************************************************************/
float CalcShipping(int weight);	//Used for if else statement

/**************************************************************
 * OutPutInvoice
 * ____________________________________________________________
 * This function gets the variables accountNumber, month, day,
 * year, saleAmount, discount, salesTax,
 * shippingPrice, and countyName by value. The function prints
 * out each of these variables along with headers.
 * ____________________________________________________________
 * INPUT
 * accountNumber		:User's account number
 * month				:Month of the sale
 * day					:Day of the sale
 * year					:Year of the sale
 * countyCode			:User's county code
 * saleAmount			:Price of the sale (Before tax)
 * weight				:The weight of the product
 *
 * OUTPUT
 * This function outputs all the input variables along with
 * headers.
 **************************************************************/
void OutputInvoice(int accountNumber,  //Displays account number
				   int month,		   //Displays month
				   int day,			   //Displays day
				   int year,		   //Displays year
				   float saleAmount,   //Displays sale amount
				   float discount,	   //Displays discount
				   float salesTax,	   //Displays sales tax
				   float shippingPrice,//Displays shipping price
				   string countyName   //Displays county name
				   );


int main()
{
	cout << left;
	cout << "************************************************\n";
	cout << "* PROGRAMMED BY : Quinten Ridley\n";
	cout << "* CLASS         : CSC5\n";
	cout << "* SECTION       : MW - 2:20PM-6:30PM\n";
	cout << "* PROJECT #3    : Functions\n";
	cout << "************************************************\n";
	cout << right;

	int accountNumber;		//INPUT - User's account number
	int month;				//INPUT - Month of the sale
	int day;				//INPUT - Day of the sale
	int year;				//INPUT - Year of the sale
	char countyCode;		//INPUT - User's county code
	float saleAmount;		//INPUT - Price of the sale (Before tax)
	int weight;				//INPUT - The weight of the product
    float discount;			//OUTPUT - Discount based on month
    float salesTax;			//OUTPUT - Tax depending on county
    float shippingPrice;	//OUTPUT - Price of the shipping
    string countyName;		//OUTPUT - Name of the county

    //Loops the program 3 times
    for (int i = 0; i < 3; i++)
    {
    	//Calling this function will collect data from user
		GetSalesInfo(accountNumber, month, day, year, countyCode,
		saleAmount, weight);

		//discount holds the discount amount of the purchase
		discount = CalcDiscount(month, saleAmount);

		//salesTax will hold the sales tax of the purchase
		salesTax = CalcSalesTax(countyCode, saleAmount, countyName,
								discount);

		//shippingPrice will hold the shipping of the purchase
		shippingPrice = CalcShipping(weight);

		//Displays the variables within the parameter
		OutputInvoice(accountNumber, month, day, year,
					  saleAmount, discount, salesTax, shippingPrice,
					  countyName);
    }

	return 0;
}

 void GetSalesInfo(int& accountNumber, int& month, int& day, int& year,
			char& countyCode, float& saleAmount, int& weight)
 {
	 //Collects the account number
	 cout << "Please Enter your Account Number: ";
	 cin >> accountNumber;

	 //Collects the month of the purchase
	 cout << "Please Enter the Sales Date.\n"
	 	     "Enter Month: ";
	 cin >> month;

	 //Collects the day of the purchase
	 cout << "Enter Day: ";
	 cin >> day;

	 //Collects the year of the purchase
	 cout << "Enter Year: ";
	 cin >> year;

	 //Collects the county where it was purchased
	 cout << "Please Enter the County Code: ";
	 cin >> countyCode;

	 //Collects the sale amount
	 cout << "Please Enter the Sales Amount: ";
	 cin >> saleAmount;

	 //Collects the weight of the purchase
	 cout << "Please Enter the Weight: ";
	 cin >> weight;

	 return;
 }

 float CalcDiscount(int month, float saleAmount)
 {
	float discount;

	//Calculates discount using month
	if (month <= 5)
	{
		discount = saleAmount * 0.05;
	} else if (month <= 8)
	{
		discount = saleAmount * 0.1;
	} else
	{
		discount = saleAmount * 0.15;
	}

	return discount;
 }


 float CalcSalesTax(char countyCode, float saleAmount,
		 string& countyName, float discount)
 {
	 float salesTax;

	 /*The sales tax has to be taken after the discount is
	  * applied to the sale amount*/
	 saleAmount -= discount;

	 /*Uses countyCode to calculate sales tax and give a name
	  * to countyName*/
	 switch (countyCode)
	 {
	 	 case 'o':
	 	 case 'O':  salesTax = saleAmount * 0.0775;
	 	 	 	 	countyName = "Orange County";
	 	 	 	 	break;
	 	 case 's':
	 	 case 'S':  salesTax = saleAmount * 0.0825;
	 	 	 	 	countyName = "San Diego County";
	 	 	 	    break;
	 	 case 'l':
	 	 case 'L':  salesTax = saleAmount * 0.0800;
	 	 	 	 	countyName = "LA County";
	 	 	 	 	break;
	 }

	 return salesTax;
 }

 float CalcShipping(int weight)
 {
	 float shippingPrice;

	 //Calculates the shipping price based on the weight
	 if (weight <= 25 )
	 {
		 shippingPrice = 5;

	 } else if (weight <= 50)
	 {
		 weight -= 25;
		 shippingPrice = 5 + (weight * 0.10);

	 } else
	 {
		 weight -= 50;
		 shippingPrice = 7.50 + (weight * 0.07);
	 }

	 return shippingPrice;
 }


 void OutputInvoice(int accountNumber, int month, int day, int year,
				    float saleAmount,float discount,
				   float salesTax,float shippingPrice, string countyName)
 {
	 //Prints the account number
	 cout << "\nACCOUNT NUMBER" << setw(33) << "COUNTY\n"
		  << setw(9) << accountNumber << setw(41)
		  << countyName << endl << endl;

	 //Prints the date of the sale
	 cout << "DATE OF SALE: " << month << "/"
		  << day << "/" << year << endl << endl <<endl;

	 cout << fixed << setprecision(2);

	 //Prints the sale amount
	 cout << "SALE AMOUNT:" << setw(8) <<  "$"
		  << setw(8) << saleAmount;

	 //Prints the discount
	 cout << endl << "DISCOUNT:" << setw(11) << "$"
	      << setw(8) << discount;

	 //Prints the sales tax
	 cout << endl << "SALES TAX:" << setw(10) << "$"
		  << setw(8) << salesTax;

	 //Prints the shipping price
	 cout << endl << "SHIPPING:" << setw(11) << "$"
		  << setw(8) << shippingPrice;

	 //Prints the total amount of the sale
	 cout << endl << "TOTAL DUE:" << setw(10) << "$"
		  << setw(8)
		  << (saleAmount + salesTax + shippingPrice - discount);

	 cout << endl << endl << endl;

	 return;
 }
