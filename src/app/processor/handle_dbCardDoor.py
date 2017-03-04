import sys

def dbCard(self, IDCard , NameKindCard , IDPerson):
    info = dbCard_cffi.new("CardInfo* ");
    
    info.card.idCard = IDCard;
    
    info.card.nameKindCard = NameKindCard;
    
    info.card.idPerson = IDPerson;
    
    dbCard_c.insert_to_db_Card_ForC(info);
    dbCard_c.update_to_db_Card_ForC(info);
    dbCard_c.delete_to_db_Card_ForC(info);

    card = dbCard_c.select_to_db_Card_ForC();
    print(card);