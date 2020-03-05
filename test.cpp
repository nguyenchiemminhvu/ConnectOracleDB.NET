// test.cpp : main project file.

#include "stdafx.h"
#include "Form1.h"

#include <string>
#include <windows.h>

using namespace test;
using namespace std;
using namespace Oracle;
using namespace Oracle::DataAccess;
using namespace Oracle::DataAccess::Client;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	//Create a connection to Oracle
	std::string conString = "User Id=HR; password=HR;Data Source=localhost:1521/SAMPLEDB; Pooling=false;";

	//How to connect to an Oracle Database with a Database alias.
	//Uncomment below and comment above.
	//"Data Source=pdborcl;Pooling=false;";

	OracleConnection ^con =  gcnew OracleConnection();
	con->ConnectionString =  gcnew System::String(conString.c_str());
	con->Open();

	//Create a command within the context of the connection
	//Use the command to display employee names and salary from the Employees table
	OracleCommand ^cmd= con->CreateCommand();
	cmd->CommandText = "select first_name from employees where department_id = 60";

	//Execute the command and use datareader to display the data
	OracleDataReader ^reader = cmd->ExecuteReader();

	// Create the main window and run it
	if (reader->Read())
		Application::Run(gcnew Form1());
	return 0;
}
