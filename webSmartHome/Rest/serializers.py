from rest_framework import serializers
from cardInfo.models import TblHistory, TblDoorCard,TblDoor,TblCard




class DoorSerializer(serializers.HyperlinkedModelSerializer):
    class Meta:
        model = TblDoorCard
        fields = ('iddoor','namedoor','ip','port')


class CardSerializer(serializers.HyperlinkedModelSerializer):
    class Meta:
        model = TblDoorCard
        fields = ('idcard')


class DoorCardSerializer(serializers.HyperlinkedModelSerializer):
    class Meta:
        model = TblDoorCard
        fields = ('id','idcard','iddoor')


class HistorySerializer(serializers.HyperlinkedModelSerializer):
    class Meta:
        model = TblHistory
        fields = ('idhistory','day','mon','year','hour','min','sec','statusdoor','checkcard','id')
