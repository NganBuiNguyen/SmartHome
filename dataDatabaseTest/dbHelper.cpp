#include <iostream>
#include <sstream>
#include <memory>
#include <string>
#include <stdexcept>

#include <mysql_driver.h>
#include <cppconn/connection.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <cppconn/metadata.h>
#include <cppconn/resultset_metadata.h>
#include <cppconn/exception.h>
#include <cppconn/warning.h>

#define DBHOST "tcp://127.0.0.1:3306"
#define USER "root"
#define PASSWORD "hongha17"
#define DATABASE "students"

#define NUMOFFSET 100
#define COLNAME 200
/*
static void retrieve_data(sql::ResultSet* rs,
                          int type, int colidx,
                          std::string colname)
{
    std::cout << "Retrieved: " << rs-rowsCount() << "rows." << std::endl;	
	while(rs->next())
	{
		if (type == NUMOFFSET)
		{
			std::cout << rs->getString(colidx) << std::endl;
		}
		else if (type == COLNAME)
		{
			std::cout << rs->getString(colname) << std::endl;
		}
	}
}
*/
static void retrieve_db_metadata(sql::Connection* dbcon)
{
    if (dbcon->isClosed())
    {
        throw std::runtime_error("FAILURE-Data connection closed");
    }

    sql::DatabaseMetaData* dbcon_meta = dbcon->getMetaData();
	
    std::cout << "Database User Name: "
	      << dbcon_meta->getUserName()
	      << std::endl;

    std::cout << "Driver Name: "
	      << dbcon_meta->getDriverName()
	      << std::endl;

    std::cout << "Driver version: "
	      << dbcon_meta->getDriverVersion()
	      << std::endl;

    std::cout << "Database is Read-Only Mode?"
	      << dbcon_meta->isReadOnly()
	      << std::endl;

    std::cout << "Maximum Connections: "
	      << dbcon_meta->getMaxConnections()
	      << std::endl;

}

int main()
{
	sql::Driver* driver;
	sql::Connection *conn;
	sql::Statement* stmt;
	sql::ResultSet* res;
	sql::PreparedStatement* prep_stmt;
	sql::Savepoint* savept;

	int updateCount = 0;

	std::string url(DBHOST);
	std::string user(USER);
	std::string password(PASSWORD);
	std::string database(DATABASE);

	try
	{
            driver = get_driver_instance();
            conn = driver->connect(url, user, password);
            conn->setSchema(database);
            conn->setAutoCommit(0);
            
	    //retrieve_dbmetadata_and_print(conn);

            stmt = conn->createStatement();
            res = stmt->executeQuery("SELECT * FROM Persons");

            while (res->next())
            {
                std::cout << res->getString("LastName") << std::endl;
            }

            prep_stmt = conn->prepareStatement("INSERT INTO Persons values(?, ?, ?, ?, ?)");

            prep_stmt->setInt(1, 1);
            prep_stmt->setString(2, "Cuong");
            prep_stmt->setString(3, "Manh Do");
            prep_stmt->setString(4, "QTSC");
            prep_stmt->setString(5, "HCMC");

            int updateCount = prep_stmt->executeUpdate();

            conn->commit();

            delete res;
            delete stmt;
            delete prep_stmt;
            conn->close();
            delete conn;
		
	}
	catch(sql::SQLException& ex)
	{
            std::cout << ex.what() << std::endl;
	}
	catch(std::runtime_error& e)
	{

	}

	return 0;
}
