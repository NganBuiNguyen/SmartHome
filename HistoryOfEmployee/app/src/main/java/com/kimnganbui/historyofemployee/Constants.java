package com.kimnganbui.historyofemployee;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Created by ngan-bui on 04/07/2017.
 */

public class Constants {

    public static final String ATTR_JSON_MESSAGE_STATUS_VALUE = "MESSAGE_STATUS_VALUE";
    public static final String ATTR_JSON_SELECT_HISTORY = "SELECT_HISTORY";
    public static final String ATTR_JSON_SELECT_YEU_CAU = "SELECT_YEU_CAU";
    public static final String ATTR_JSON_SELECT_USER = "SELECT_USER";
    public static final String ATTR_JSON_DAY = "DAY";
    public static final String ATTR_JSON_MONTH = "MONTH";
    public static final String ATTR_JSON_ID_HISTORY = "ID_HISTORY";
    public static final String ATTR_JSON_YEAR = "YEAR";
    public static final String ATTR_JSON_HOUR = "HOUR";
    public static final String ATTR_JSON_NAME_USER = "NAME_USER";
    public static final String ATTR_JSON_ID_CARD = "ID_CARD";
    public static final String ATTR_JSON_SELECT_POSITION = "SELECT_POSITION";


    public static final String ATTR_JSON_MESSAGE_STATUS_VALUE_LOGIN = "LOGIN";
    public static final String ATTR_JSON_USER_NAME = "USERNAME";
    public static final String ATTR_JSON_PASSWORD = "PASSWORD";
    public static final String ATTR_JSON_LOGIN_SUCCESSFUL_ADMIN = "LOGIN_ADMIN";
    public static final String ATTR_JSON_LOGIN_SUCCESSFUL_USER = "LOGIN_USER";

    public static boolean checkUsernameLength(String s){
        if(s.length() < 3  || s.length() > 30)
            return true;
        else
            return false;
    }

    public static boolean checkPasswordLength(String s)
    {
        if(s.length() < 5)
            return true;
        else
            return false;

    }

    public static boolean usernameCharacterSpecial(String s)
    {
        Pattern special = Pattern.compile ("[!@#$%&*()+=|<>?{}\\[\\]~-]");
        Matcher hasSpecial = special.matcher(s);

        if(hasSpecial.find()) {
            return true;
        } else {
            return false;
        }

    }

    public static boolean whiteSpace(String s){
        if(s.contains(" ") || s.contains("\n") || s.contains("\t") || s.contains("\r")){
            return true;
        }else {
            return false;
        }

    }

    public static boolean isValidEmailAddress(String email) {
        String ePattern = "^[a-zA-Z0-9.!#$%&'*+/=?^_`{|}~-]+@((\\[[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\])|(([a-zA-Z\\-0-9]+\\.)+[a-zA-Z]{2,}))$";
        Pattern p = Pattern.compile(ePattern);
        Matcher m = p.matcher(email);
        if(m.find()) return true;
        else return false;
    }
}
