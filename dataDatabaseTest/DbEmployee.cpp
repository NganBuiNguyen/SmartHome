    
    #include "DbEmployee.h"

    
    DbEmployee* DbEmployee::instance = NULL;
    std::string DbEmployee::database = DATABASE;
   

    DbEmployee* DbEmployee::getInstance()
    {
      if(instance == NULL)
      {
         instance= new DbEmployee();
      }
      return instance;
    }
    sql::Connection* DbEmployee::getConn(std::string userName,std::string password,std::string url)
    {
        this->driver=get_driver_instance();
        this->conn=driver->connect(url,userName,password);
        this->conn->setSchema(database);
        this->conn->setAutoCommit(0);
        return this->conn;
    }
    DbEmployee::DbEmployee()
    {

    }
    void DbEmployee::closeConn()
    {
        if(this->res!=NULL)
        {
            delete this->res;
        }
        if(this->stmt !=NULL)
        {
            delete this->stmt;
        }
        if(this->prep_stmt !=NULL)
        {
            delete this->prep_stmt;
        }
        if(this->conn !=NULL)
        {
            this->conn->close();
            delete this->conn;
        }
    }
    void DbEmployee::insert_node_to_db(sql::Connection* conn,Employee employee)
    {
        DbEmployee* dbEmployee = DbEmployee::getInstance();

        dbEmployee->getConn(this->user,this->password,this->url);
        this->prep_stmt = conn->prepareStatement("INSERT INTO Employee(employeeName,roomID) values(?,?)");
        (this->prep_stmt)->setString(1, employee.getEmployeeName());
        (this->prep_stmt)->setString(2, employee.getRoomID());
        
         dbEmployee->closeConn();
    }
   
