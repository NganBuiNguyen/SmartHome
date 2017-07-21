from django import forms
from cardInfo.models import TblUser,TblHistory,TblInfouser,TblRoom,TblDoor,TblCard,TblDoorCard
from django.contrib.auth import(
    authenticate,
    get_user_model,
    login,
    logout,
)
User = get_user_model()
class UserLoginForm(forms.ModelForm):
    class Meta:
        model = TblUser
        fields = ('username', 'password')

class UserForm(forms.Form):
    class Meta:
        model = TblUser
        fields=['iduser','grantuser','username','password']  
class InfoUserForm(forms.Form):
    class Meta:
        model = TblInfouser
        fields=['iduser','nameuser','age'] 

class RoomForm(forms.Form):
    class Meta:
        model = TblRoom
        fields=['idroom','nameroom'] 

class CardForm(forms.Form):
    class Meta:
        model = TblCard
        fields=['idcard','iduser'] 

class DoorForm(forms.Form):
    class Meta:
        model = TblDoor
        fields=['iddoor','namedoor','ip','port','idroom'] 
class HistoryForm(forms.Form):
    class Meta:
        model = TblHistory
        fields=['day','mon','year'] 

class DoorCardForm(forms.Form):
    class Meta:
        model = TblDoorCard
        fields=['id','idcard','iddoor'] 