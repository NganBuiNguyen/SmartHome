# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='DjangoMigrations',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('app', models.CharField(max_length=255)),
                ('name', models.CharField(max_length=255)),
                ('applied', models.DateTimeField()),
            ],
            options={
                'db_table': 'django_migrations',
                'managed': False,
            },
        ),
        migrations.CreateModel(
            name='TblCard',
            fields=[
                ('idcard', models.CharField(max_length=30, primary_key=True, serialize=False, db_column='IDCard')),
            ],
            options={
                'db_table': 'tbl_Card',
                'managed': False,
            },
        ),
        migrations.CreateModel(
            name='TblDoor',
            fields=[
                ('iddoor', models.CharField(max_length=10, primary_key=True, serialize=False, db_column='IDDoor')),
                ('namedoor', models.CharField(max_length=30, blank=True, db_column='NameDoor', null=True)),
                ('ip', models.CharField(max_length=20, blank=True, db_column='IP', null=True)),
                ('port', models.CharField(max_length=6, blank=True, db_column='Port', null=True)),
            ],
            options={
                'db_table': 'tbl_Door',
                'managed': False,
            },
        ),
        migrations.CreateModel(
            name='TblDoorCard',
            fields=[
                ('id', models.IntegerField(serialize=False, primary_key=True, db_column='ID')),
            ],
            options={
                'db_table': 'tbl_Door_Card',
                'managed': False,
            },
        ),
        migrations.CreateModel(
            name='TblHistory',
            fields=[
                ('idhistory', models.IntegerField(serialize=False, primary_key=True, db_column='IDHistory')),
                ('day', models.IntegerField(blank=True, db_column='Day', null=True)),
                ('mon', models.IntegerField(blank=True, db_column='Mon', null=True)),
                ('year', models.IntegerField(blank=True, db_column='Year', null=True)),
                ('hour', models.IntegerField(blank=True, db_column='Hour', null=True)),
                ('min', models.IntegerField(blank=True, db_column='Min', null=True)),
                ('sec', models.IntegerField(blank=True, db_column='Sec', null=True)),
                ('statusdoor', models.IntegerField(blank=True, db_column='StatusDoor', null=True)),
                ('checkcard', models.IntegerField(blank=True, db_column='CheckCard', null=True)),
            ],
            options={
                'db_table': 'tbl_History',
                'managed': False,
            },
        ),
        migrations.CreateModel(
            name='TblInfouser',
            fields=[
                ('iduser', models.CharField(max_length=20, primary_key=True, serialize=False, db_column='IDUser')),
                ('nameuser', models.CharField(max_length=45, blank=True, db_column='NameUser', null=True)),
                ('age', models.IntegerField(blank=True, db_column='Age', null=True)),
            ],
            options={
                'db_table': 'tbl_InfoUser',
                'managed': False,
            },
        ),
        migrations.CreateModel(
            name='TblRoom',
            fields=[
                ('idroom', models.CharField(max_length=10, primary_key=True, serialize=False, db_column='IDRoom')),
                ('nameroom', models.CharField(max_length=30, blank=True, db_column='NameRoom', null=True)),
            ],
            options={
                'db_table': 'tbl_Room',
                'managed': False,
            },
        ),
        migrations.CreateModel(
            name='TblUser',
            fields=[
                ('iduser', models.ForeignKey(primary_key=True, serialize=False, db_column='IDUser', to='cardInfo.TblInfouser')),
                ('grantuser', models.IntegerField(blank=True, db_column='GrantUser', null=True)),
                ('username', models.CharField(max_length=30, blank=True, db_column='UserName', null=True)),
                ('password', models.CharField(max_length=20, blank=True, db_column='Password', null=True)),
            ],
            options={
                'db_table': 'tbl_User',
                'managed': False,
            },
        ),
    ]
