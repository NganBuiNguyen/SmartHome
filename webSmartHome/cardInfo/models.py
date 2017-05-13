# This is an auto-generated Django model module.
# You'll have to do the following manually to clean this up:
#   * Rearrange models' order
#   * Make sure each model has one field with primary_key=True
#   * Remove `managed = False` lines if you wish to allow Django to create, modify, and delete the table
# Feel free to rename the models, but don't rename db_table values or field names.
#
# Also note: You'll have to insert the output of 'django-admin sqlcustom [app_label]'
# into your database.
from __future__ import unicode_literals

from django.db import models



class DjangoMigrations(models.Model):
    app = models.CharField(max_length=255)
    name = models.CharField(max_length=255)
    applied = models.DateTimeField()

    class Meta:
        managed = False
        db_table = 'django_migrations'
    
class TblInfouser(models.Model):
    iduser = models.CharField(db_column='IDUser', primary_key=True, max_length=20)  # Field name made lowercase.
    nameuser = models.CharField(db_column='NameUser', max_length=45, blank=True, null=True)  # Field name made lowercase.
    age = models.IntegerField(db_column='Age', blank=True, null=True)  # Field name made lowercase.

    class Meta:
        managed = False
        db_table = 'tbl_InfoUser'

    def __str__(self):
        return ('%s' % self.iduser + '-' + self.nameuser)

class TblUser(models.Model):
    iduser = models.ForeignKey(TblInfouser, db_column='IDUser', primary_key=True)  # Field name made lowercase.
    grantuser = models.IntegerField(db_column='GrantUser', blank=True, null=True)  # Field name made lowercase.
    username = models.CharField(db_column='UserName', max_length=30, blank=True, null=True)  # Field name made lowercase.
    password = models.CharField(db_column='Password', max_length=20, blank=True, null=True)  # Field name made lowercase.

    class Meta:
        managed = False
        db_table = 'tbl_User'

    def __str__(self):
        return ('%s' % self.iduser + '-' + '%s' % self.grantuser )


class TblCard(models.Model):
    idcard = models.CharField(db_column='IDCard', primary_key=True, max_length=30)  # Field name made lowercase.
    iduser = models.ForeignKey('TblUser', db_column='IDUser', blank=True, null=True)  # Field name made lowercase.

    class Meta:
        managed = False
        db_table = 'tbl_Card'

    def __str__(self):
        return ('%s' % self.idcard + '-' + '%s' % self.iduser)

class TblDoor(models.Model):
    iddoor = models.CharField(db_column='IDDoor', primary_key=True, max_length=10)  # Field name made lowercase.
    namedoor = models.CharField(db_column='NameDoor', max_length=30, blank=True, null=True)  # Field name made lowercase.
    ip = models.CharField(db_column='IP', max_length=20, blank=True, null=True)  # Field name made lowercase.
    port = models.CharField(db_column='Port', max_length=6, blank=True, null=True)  # Field name made lowercase.
    idroom = models.ForeignKey('TblRoom', db_column='IDRoom', blank=True, null=True)  # Field name made lowercase.

    class Meta:
        managed = False
        db_table = 'tbl_Door'

    def __str__(self):
        return ('%s' % self.namedoor)

class TblDoorCard(models.Model):
    id = models.IntegerField(db_column='ID', primary_key=True)  # Field name made lowercase.
    idcard = models.ForeignKey(TblCard, db_column='IDCard', blank=True, null=True)  # Field name made lowercase.
    iddoor = models.ForeignKey(TblDoor, db_column='IDDoor', blank=True, null=True)  # Field name made lowercase.

    class Meta:
        managed = False
        db_table = 'tbl_Door_Card'

    def __str__(self):
        return ('%s' % self.idcard + '-' + '%s' % self.iddoor)

class TblHistory(models.Model):
    idhistory = models.IntegerField(db_column='IDHistory', primary_key=True)  # Field name made lowercase.
    day = models.IntegerField(db_column='Day', blank=True, null=True)  # Field name made lowercase.
    mon = models.IntegerField(db_column='Mon', blank=True, null=True)  # Field name made lowercase.
    year = models.IntegerField(db_column='Year', blank=True, null=True)  # Field name made lowercase.
    hour = models.IntegerField(db_column='Hour', blank=True, null=True)  # Field name made lowercase.
    min = models.IntegerField(db_column='Min', blank=True, null=True)  # Field name made lowercase.
    sec = models.IntegerField(db_column='Sec', blank=True, null=True)  # Field name made lowercase.
    statusdoor = models.IntegerField(db_column='StatusDoor', blank=True, null=True)  # Field name made lowercase.
    checkcard = models.IntegerField(db_column='CheckCard', blank=True, null=True)  # Field name made lowercase.
    id = models.ForeignKey(TblDoorCard, db_column='ID', blank=True, null=True)  # Field name made lowercase.

    class Meta:
        managed = False
        db_table = 'tbl_History'

    # def __str__(self):
    #     return ('%s' % self.idhistory + '-' + self.iddoor)



class TblRoom(models.Model):
    idroom = models.CharField(db_column='IDRoom', primary_key=True, max_length=10)  # Field name made lowercase.
    nameroom = models.CharField(db_column='NameRoom', max_length=30, blank=True, null=True)  # Field name made lowercase.

    class Meta:
        managed = False
        db_table = 'tbl_Room'

    def __str__(self):
        return ('%s' % self.idroom)

