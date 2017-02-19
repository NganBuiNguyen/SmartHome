    
    #include "DbStatus.h"

    
    DbStatus* DbStatus::instance = NULL;
    std::string DbStatus::database = DATABASE;
   

    DbStatus* DbStatus::getInstance()
    {
      if(instance == NULL)
      {
         instance= new DbStatus();
      }
      return instance;
    }
    sql::Connection* DbStatus::getConn(std::string userName,std::string password,std::string url)
    {
        this->driver=get_driver_instance();
        this->conn=driver->connect(url,userName,password);
        this->conn->setSchema(database);
        this->conn->setAutoCommit(0);
        return this->conn;
    }
    DbStatus::DbStatus()
    {
       this->url=DBHOST;
       this->user=USER;
       this->password=PASSWORD;
    }
    void DbStatus::closeConn()
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
    void DbStatus::insert_to_db(sql::Connection* conn,Status status)
    {
        DbStatus* dbStatus = DbStatus::getInstance();

        conn= dbStatus->getConn(this->user,this->password,this->url);
         if(conn==NULL)
           {
            return;
           }
        this->prep_stmt = conn->prepareStatement("INSERT INTO Status(statusID,statusName,timeIn,timeOut) values(?,?,?,?)");//chua insert card
        if(this->prep_stmt==NULL)
         {
            return;
         }
        try{
        (this->prep_stmt)->setString(1, status.getStatusID());
        (this->prep_stmt)->setBoolean(2, status.getStatusName());

        
        (this->prep_stmt)->setInt(3, (int) status.getTimeIn()) ;
        (this->prep_stmt)->setInt(4, (int) status.getTimeOut()) ;
        }catch(sql::SQLException& e)
        {
          conn->rollback();
        }
         
         conn->commit();
         dbStatus->closeConn();
    }
    void DbStatus::select_to_db(sql::Connection* conn)
    {
        DbStatus* dbStatus = DbStatus::getInstance();

        stmt = conn->createStatement();
        conn=dbStatus->getConn(this->user,this->password,this->url);

        this->res = stmt->executeQuery("SELECT * FROM Status");

         while (res->next())
        {
            std::cout << res->getString("statusID") << std::endl;
        }
        int updateCount = prep_stmt->executeUpdate();
        conn->commit();
        
        dbStatus->closeConn();
    }
    void DbStatus::update_to_db(sql::Connection* conn,Status status)
     {
      
        DbStatus* dbStatus = DbStatus::getInstance();

        conn= dbStatus->getConn(this->user,this->password,this->url);

        this->prep_stmt = conn->prepareStatement("UPDATE Status SET statusName = ? WHERE statusID = ?");

        (this->prep_stmt)->setBoolean(1, status.getStatusName());
        (this->prep_stmt)->setString(2, status.getStatusID());
        
        int updateCount = prep_stmt->executeUpdate();
        conn->commit();
        dbStatus->closeConn();
    }
    void DbStatus::delete_to_db(sql::Connection* conn,Status status)
    {
        DbStatus* dbStatus = DbStatus::getInstance();

        conn= dbStatus->getConn(this->user,this->password,this->url);
        this->prep_stmt = conn->prepareStatement("DELETE FROM Status WHERE statusID = ?");

        (this->prep_stmt)->setString(1, status.getStatusID());

        int updateCount = prep_stmt->executeUpdate();
        conn->commit();

        dbStatus->closeConn();
    }
