package com.kimnganbui.models;

import com.google.gson.Gson;
import com.google.gson.reflect.TypeToken;

import java.lang.reflect.Type;
import java.util.ArrayList;

/**
 * Created by ngan-bui on 20/06/2017.
 */

public class History {
    int idhistory;
    int day;
    int mon;
    int year;
    int hour;
    int min;
    int sec;
    String statusdoor;
    String checkcard;
    String countTime;
    int id;
    String idCard;
    String idDoor;
    String nameUser;

    public History(int idhistory, int day, int mon, int year, int hour, int min, int sec, String statusdoor, String checkcard, String countTime, int id) {
        this.idhistory = idhistory;
        this.day = day;
        this.mon = mon;
        this.year = year;
        this.hour = hour;
        this.min = min;
        this.sec = sec;
        this.statusdoor = statusdoor;
        this.checkcard = checkcard;
        this.countTime = countTime;
        this.id = id;
    }

    public History() {
    }

    public String getIdCard() {
        return idCard;
    }

    public void setIdCard(String idCard) {
        this.idCard = idCard;
    }

    public String getIdDoor() {
        return idDoor;
    }

    public void setIdDoor(String idDoor) {
        this.idDoor = idDoor;
    }

    public String getNameUser() {
        return nameUser;
    }

    public void setNameUser(String nameUser) {
        this.nameUser = nameUser;
    }

    public int getIdhistory() {
        return idhistory;
    }

    public void setIdhistory(int idhistory) {
        this.idhistory = idhistory;
    }

    public int getDay() {
        return day;
    }

    public void setDay(int day) {
        this.day = day;
    }

    public int getMon() {
        return mon;
    }

    public void setMon(int mon) {
        this.mon = mon;
    }

    public int getYear() {
        return year;
    }

    public void setYear(int year) {
        this.year = year;
    }

    public int getHour() {
        return hour;
    }

    public void setHour(int hour) {
        this.hour = hour;
    }

    public int getMin() {
        return min;
    }

    public void setMin(int min) {
        this.min = min;
    }

    public int getSec() {
        return sec;
    }

    public void setSec(int sec) {
        this.sec = sec;
    }

    public String getStatusdoor() {
        return statusdoor;
    }

    public void setStatusdoor(String statusdoor) {
        this.statusdoor = statusdoor;
    }

    public String getCheckcard() {
        return checkcard;
    }

    public void setCheckcard(String checkcard) {
        this.checkcard = checkcard;
    }

    public String getCountTime() {
        return countTime;
    }

    public void setCountTime(String countTime) {
        this.countTime = countTime;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    @Override
    public String toString() {
        return "History{" +
                "idhistory=" + idhistory +
                ", day=" + day +
                ", mon=" + mon +
                ", year=" + year +
                ", hour=" + hour +
                ", min=" + min +
                ", sec=" + sec +
                ", statusdoor='" + statusdoor + '\'' +
                ", checkcard='" + checkcard + '\'' +
                ", countTime='" + countTime + '\'' +
                ", id=" + id +
                ", idCard='" + idCard + '\'' +
                ", idDoor='" + idDoor + '\'' +
                ", nameUser='" + nameUser + '\'' +
                '}';
    }
}
