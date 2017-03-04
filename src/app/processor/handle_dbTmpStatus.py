import sys

def dbTmpStatus(self,ID_Tmp_Status, IDCard, Ip, Port, Day, Mon, Year, Hour, Min, Sec):

    print("1");
    info = dbTmpStatus_cffi.new("CardInfo* ");
    print("2");
    info.card.idCard = IDCard;
    print("3");
    info.ip_port.ip = Ip;
    info.ip_port.port = Port;
    print("5");

    info.dateTime.day = Day;
    info.dateTime.mon = Mon;
    info.dateTime.year = Year;
    info.dateTime.hour = Hour;
    info.dateTime.min = Min;
    info.dateTime.sec = Sec;

    # dbTmpStatus_c.select_to_db_TmpStatus_ForC(1);
    dbTmpStatus_c.insert_to_db_TmpStatus_ForC (info);