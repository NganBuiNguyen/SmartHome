from rest_framework import serializers
from cardInfo.models import TblHistory, TblDoorCard
from cardInfo.models import TblDoor,TblCard,TblUser,TblInfouser

class InfoUserSerializer(serializers.HyperlinkedModelSerializer):
    class Meta:
        model = TblInfouser
        fields = ('iduser','nameuser','age')

class UserSerializer(serializers.HyperlinkedModelSerializer):
    class Meta:
        model = TblUser
        fields = ('iduser','grantuser','username','password')


class DoorSerializer(serializers.HyperlinkedModelSerializer):
    class Meta:
        model = TblDoor
        fields = ('iddoor','namedoor','ip','port')


class CardSerializer(serializers.HyperlinkedModelSerializer):
    class Meta:
        model = TblCard
        fields = ('idcard','iduser')


class DoorCardSerializer(serializers.HyperlinkedModelSerializer):
    class Meta:
        model = TblDoorCard
        fields = ('id','idcard','iddoor')


class HistorySerializer(serializers.HyperlinkedModelSerializer):
    # Doorcard = DoorCardSerializer()
    class Meta:
        model = TblHistory
        fields = ('idhistory','day','mon','year','hour','min','sec','statusdoor','checkcard','countTime','id')

# class SupportSearchSerializer(serializers.HyperlinkedModelSerializer):
#     Doorcard = DoorCardSerializer()
#     class Meta:
#         model = TblHistory
#         fields = ('id','idhistory','day','mon','year','hour','min','sec','statusdoor','checkcard','countTime','Doorcard')