from rest_framework import generics
from rest_framework import viewsets


from Rest.serializers import HistorySerializer,DoorSerializer
from Rest.serializers import CardSerializer,DoorCardSerializer
from cardInfo.models import TblHistory,TblDoorCard,TblDoor,TblCard

class DoorViewSet(viewsets.ModelViewSet):
    queryset = TblDoor.objects.all()
    serializer_class = DoorSerializer

class CardViewSet(viewsets.ModelViewSet):
    queryset = TblCard.objects.all()
    serializer_class = CardSerializer

class DoorCardViewSet(viewsets.ModelViewSet):
    queryset = TblDoorCard.objects.all()
    serializer_class = DoorCardSerializer

class HistoryViewSet(viewsets.ModelViewSet):
    queryset = TblHistory.objects.all()
    serializer_class = HistorySerializer

# class HistoryViewSet(viewsets.ModelViewSet):
#     queryset = TblHistory.objects.all()
#     serializer_class = HistorySerializer