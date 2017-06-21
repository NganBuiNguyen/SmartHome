"""webSmartHome URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/1.8/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  url(r'^$', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  url(r'^$', Home.as_view(), name='home')
Including another URLconf
    1. Add a URL to urlpatterns:  url(r'^blog/', include('blog.urls'))
"""
from django.conf.urls import include, url
from django.contrib import admin
from cardInfo import views

from rest_framework import routers
from Rest.viewsets import HistoryViewSet,DoorViewSet
from Rest.viewsets import CardViewSet, DoorCardViewSet

router = routers.DefaultRouter()
router.register(r'cards', CardViewSet)
router.register(r'doors', DoorViewSet)
router.register(r'doorcards', DoorCardViewSet)
router.register(r'historys', HistoryViewSet)

urlpatterns = [
    url(r'^admin/', include(admin.site.urls)),
    url(r'^save/$', "cardInfo.views.save", name='save'),
    url(r'^notifyUpdateProcessor/$', views.notifyUpdateProcessor, name='notify'),
    url(r'^actionsave/$', views.actionsave , name='actionsave'),
    url(r'^rest/', include(router.urls))
]
