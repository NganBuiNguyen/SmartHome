package com.kimnganbui.models;

import com.google.gson.Gson;
import com.google.gson.reflect.TypeToken;

import java.lang.reflect.Type;
import java.util.ArrayList;

/**
 * Created by ngan-bui on 22/06/2017.
 */

public class User {
    String iduser;
    String nameUser;
    String idCard;
    String idDoor;
    String idRoom;

    public User() {
    }

    public User(String iduser, String nameUser, String idCard, String idDoor, String idRoom) {
        this.iduser = iduser;
        this.nameUser = nameUser;
        this.idCard = idCard;
        this.idDoor = idDoor;
        this.idRoom = idRoom;
    }

    public String getIduser() {
        return iduser;
    }

    public void setIduser(String iduser) {
        this.iduser = iduser;
    }

    public String getNameUser() {
        return nameUser;
    }

    public void setNameUser(String nameUser) {
        this.nameUser = nameUser;
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

    public String getIdRoom() {
        return idRoom;
    }

    public void setIdRoom(String idRoom) {
        this.idRoom = idRoom;
    }

    @Override
    public String toString() {
        return "User{" +
                "iduser='" + iduser + '\'' +
                ", nameUser='" + nameUser + '\'' +
                ", idCard='" + idCard + '\'' +
                ", idDoor='" + idDoor + '\'' +
                ", idRoom='" + idRoom + '\'' +
                '}';
    }
}
