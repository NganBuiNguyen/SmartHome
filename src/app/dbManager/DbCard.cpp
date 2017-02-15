 #include "DbCard.h"


    DbCard* DbCard::instance = NULL;
    std::string DbCard::database = DATABASE;


    DbCard* DbCard::getInstance()
    {
        if (instance == NULL)
        {
            instance = new DbCard();
        }
        return instance;
    }


    sql::Connection* DbCard::getConn(std::string userName,std::string password,std::string url)
    {
        this->driver = get_driver_instance();
        this->conn = driver->connect(url, userName, password);
        this->conn->setSchema(database);
        this->conn->setAutoCommit(0);
        return this->conn;
    }


    DbCard::DbCard()
    {
        this->url=DBHOST;
        this->user=USER;
        this->password=PASSWORD;
    }

    void DbCard::closeConn()
    {
        if(this->res!=NULL)
        {
            delete this->res;
        }
        if (this->stmt!=NULL)
        {
            delete this->stmt;
        }
        if (this->prep_stmt !=NULL)
        {
            delete this->prep_stmt;
        }
        if (this->conn !=NULL)
        {
            delete this->conn;
        }
    }


    void DbCard::insert_to_db(sql::Connection* conn,CardInfo &info)
    {
        DbCard* dbCard = DbCard::getInstance();
        conn = dbCard->getConn(this->user, this->password, this->url);
        if(conn==NULL)
        {
            return;
        }
        this->prep_stmt = conn->prepareStatement("INSERT INTO Card(cardID,kindCard) values(?,?)");
        if( this->prep_stmt==NULL)
        {
            return;
        }
        try{
        (this->prep_stmt)->setString(1, info.card.idCard);
        (this->prep_stmt)->setString(2, info.card.nameKindCard);
         int i=(this->prep_stmt)->executeUpdate();
       if(i>0)
       { 
       std::cout<<"Them thanh cong";
       }
       else
       {
        std::cout<<"Them that bai";
        } 
       }catch(sql::SQLException& e)
        {
            conn->rollback();
        } 
        conn->commit();
        dbCard->closeConn();
    }

    void DbCard::select_to_db(sql::Connection* conn)
    {
        DbCard* dbCard = DbCard::getInstance();

        stmt = conn->createStatement();

        conn=  dbCard->getConn(this->user,this->password,this->url);

        this->res = stmt->executeQuery("SELECT * FROM Card");

         while (res->next())
        {
            std::cout << res->getString("cardID") << std::endl;
        }
        int updateCount = prep_stmt->executeUpdate();
        conn->commit();
        
        dbCard->closeConn();
    }
    void DbCard::update_to_db(sql::Connection* conn, CardInfo &info)
    {
        
        DbCard* dbCard = DbCard::getInstance();

        conn=dbCard->getConn(this->user,this->password,this->url);

        this->prep_stmt = conn->prepareStatement("UPDATE Card SET kindCard = ? WHERE cardID = ?");

        (this->prep_stmt)->setString(1, info.card.idCard);
        (this->prep_stmt)->setString(2, info.card.nameKindCard);
        
        int updateCount = prep_stmt->executeUpdate();
        conn->commit();
        dbCard->closeConn();
    }
    void DbCard::delete_to_db(sql::Connection* conn, CardInfo &info)
    {
        DbCard* dbCard = DbCard::getInstance();

        conn= dbCard->getConn(this->user,this->password,this->url);
        this->prep_stmt = conn->prepareStatement("DELETE FROM Card WHERE cardID = ?");

        (this->prep_stmt)->setString(1,info.card.idCard);

        int updateCount = prep_stmt->executeUpdate();
        conn->commit();

        dbCard->closeConn();
    }
    
