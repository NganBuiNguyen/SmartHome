package com.kimnganbui.classes;

import com.google.gson.Gson;
import com.google.gson.reflect.TypeToken;

import java.lang.reflect.Type;
import java.util.ArrayList;

/**
 * Created by ngan-bui on 20/06/2017.
 */

public class History {
    String idhistory;
    String day;
    String mon;
    String year;
    String hour;
    String min;
    String sec;
    String statusdoor;
    String checkcard;

    public History(String idhistory, String day, String mon, String year, String hour, String min, String sec, String statusdoor, String checkcard) {
        this.idhistory = idhistory;
        this.day = day;
        this.mon = mon;
        this.year = year;
        this.hour = hour;
        this.min = min;
        this.sec = sec;
        this.statusdoor = statusdoor;
        this.checkcard = checkcard;
    }

    public History() {
    }

    public String getIdhistory() {
        return idhistory;
    }

    public void setIdhistory(String idhistory) {
        this.idhistory = idhistory;
    }

    public String getDay() {
        return day;
    }

    public void setDay(String day) {
        this.day = day;
    }

    public String getMon() {
        return mon;
    }

    public void setMon(String mon) {
        this.mon = mon;
    }

    public String getYear() {
        return year;
    }

    public void setYear(String year) {
        this.year = year;
    }

    public String getHour() {
        return hour;
    }

    public void setHour(String hour) {
        this.hour = hour;
    }

    public String getMin() {
        return min;
    }

    public void setMin(String min) {
        this.min = min;
    }

    public String getSec() {
        return sec;
    }

    public void setSec(String sec) {
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

//    @Override
//    public String toString() {
//        return "History{" +
//                "idhistory=" + idhistory +
//                ", day=" + day +
//                ", mon=" + mon +
//                ", year=" + year +
//                ", hour=" + hour +
//                ", min=" + min +
//                ", sec=" + sec +
//                ", statusdoor=" + statusdoor +
//                ", checkcard=" + checkcard +
//                '}';
//    }

    public static ArrayList<History> pareHistorys (String json){
        Gson gson = new Gson();
        Type type = new TypeToken<ArrayList<History>>(){}.getType();
//        Type type = new TypeToken<ArrayList<History>>(){}.getType();
        return gson.fromJson(json, type);
    }
}
