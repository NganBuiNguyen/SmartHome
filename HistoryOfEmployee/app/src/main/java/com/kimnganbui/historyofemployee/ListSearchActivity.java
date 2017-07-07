package com.kimnganbui.historyofemployee;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ListView;
import android.widget.Toast;

import com.kimnganbui.adapter.HistoryAdapter;
import com.kimnganbui.api.APIService;
import com.kimnganbui.api.ApplicationService;
import com.kimnganbui.api.ResponseData;
import com.kimnganbui.models.History;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;

public class ListSearchActivity extends Activity implements APIService.ServiceListener {

    ListView lvHistory;
    ArrayList<History> historysArrayList;
    HistoryAdapter adapterHistory;


    ApplicationService applicationService;



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_list_search);
        selectHistory();
        addControl();
        addEvent();
    }

    private void addEvent() {


    }

    private void addControl() {

        lvHistory = (ListView) findViewById(R.id.lvHistory);
        historysArrayList = new ArrayList<>();
        adapterHistory = new HistoryAdapter(ListSearchActivity.this, R.layout.layout_item_history, historysArrayList);
        lvHistory.setAdapter(adapterHistory);
    }

    private void selectHistory() {
        String cmd = "";
        JSONObject object = new JSONObject();
        try {
            object.put(Constants.ATTR_JSON_MESSAGE_STATUS_VALUE, Constants.ATTR_JSON_SELECT_HISTORY);
            cmd = object.toString();
            getRequest(cmd);
            Toast.makeText(ListSearchActivity.this, "SELECT history: " + cmd, Toast.LENGTH_LONG).show();
            System.out.println("SELECT history: " + cmd);
        } catch (JSONException e) {
            e.printStackTrace();
            System.out.println("JSON history error");
        }
    }
    private void getRequest(String val){
        applicationService = new ApplicationService(this);
        applicationService.getRequest(val);
    }

    @Override
    public void onReceivedResponseSuccess(ResponseData respData) {
        if(respData.getApiID() == 100){
            String json = respData.getValue();
            try {
                JSONObject object = new JSONObject(json);
                JSONArray jsonArray = object.getJSONArray("SELECT_HISTORY");
                historysArrayList.clear();
                for(int i =0; i < jsonArray.length(); i++){
                    History history = new History();
                    JSONObject jsonObject = jsonArray.getJSONObject(i);

                    int idHis = jsonObject.getInt("IDHistory");
                    history.setIdhistory(idHis);

                    int day = jsonObject.getInt("Day");
                    history.setDay(day);


                    int mon = jsonObject.getInt("Mon");
                    history.setMon(mon);

                    int year = jsonObject.getInt("Year");
                    history.setYear(year);

                    int hour = jsonObject.getInt("Hour");
                    history.setHour(hour);

                    int minute = jsonObject.getInt("Min");
                    history.setMin(minute);

                    int second = jsonObject.getInt("Sec");
                    history.setSec(second);

                    int statusdoor = jsonObject.getInt("StatusDoor");
                    if(statusdoor == 1) {
                        history.setStatusdoor("Vào");
                    }
                    else{
                        history.setStatusdoor("Ra");
                    }

                    int checkcard = jsonObject.getInt("CheckCard");
                    if(checkcard == 1)
                    {
                        history.setCheckcard("Đúng");
                    }
                    else {
                        history.setCheckcard("Sai");
                    }

                    String idCard = jsonObject.getString("IDCard");
                    history.setIdCard(idCard);

                    String idDoor = jsonObject.getString("IDDoor");
                    history.setIdDoor(idDoor);

                    String countTime = jsonObject.getString("CountTime");
                    history.setCountTime(countTime);

                    String nameUser = jsonObject.getString("NameUser");
                    history.setNameUser(nameUser);


                    historysArrayList.add(history);

                }
            } catch (JSONException e) {
                e.printStackTrace();
                System.out.println("JSON select error");
            }
        }
    }

    @Override
    public void onReceivedResponseFail(ResponseData respData) {
        if(respData.getApiID() == 100){
            //alert
            Toast.makeText(ListSearchActivity.this, "Check Connection", Toast.LENGTH_LONG).show();
        }
    }

}
