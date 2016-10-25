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
        this->conn->setSchema(database);// phan quyen
        this->conn->setAutoCommit(0);
        return this->conn;
    }


    DbCard::DbCard()
    {

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


    void DbCard::insert_to_db(sql::Connection* conn,Card card)
    {
        DbCard* dbCard = DbCard::getInstance();

        dbCard->getConn(this->user, this->password, this->url);
        this->prep_stmt = conn->prepareStatement("INSERT INTO Card(cardID,kindCard,employeeID,roomID) values(?,?)");
        (this->prep_stmt)->setInt(1, card.getCardID());
        (this->prep_stmt)->setString(2, card.getKindCard());
        (this->prep_stmt)->setString(3, card.getEmployeeID());
        (this->prep_stmt)->setString(4, card.getRoomID());

        dbCard->closeConn();
    
    }
    