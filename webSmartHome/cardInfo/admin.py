from django.contrib import admin

# Register your models here.
from .models import TblCard , TblDoor , TblDoorCard, TblHistory
from .models import TblInfouser , TblRoom , TblUser

# class KhachHangAdmin(admin.ModelAdmin):
#     list_display = (
#         'makhachhang','tenkhachhang', 'cmnd', 'ngaysinh',
#         'gioitinh', 'diachi', 'sodienthoai')
#     search_fields = ['makhachhang','tenkhachhang', 'cmnd', 'sodienthoai']
admin.site.register(TblInfouser)

admin.site.register(TblUser)
admin.site.register(TblCard)
admin.site.register(TblDoor)
admin.site.register(TblDoorCard)
admin.site.register(TblHistory)
admin.site.register(TblRoom)

