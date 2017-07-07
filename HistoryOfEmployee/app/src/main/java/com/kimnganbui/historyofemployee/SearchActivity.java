package com.kimnganbui.historyofemployee;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.Spinner;
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

public class SearchActivity extends AppCompatActivity implements APIService.ServiceListener {
    Spinner spSearch;
    EditText data;

    ListView lvSearch;
    ArrayList<History> searchArrayList;
    HistoryAdapter adapterSearch;

    Button btnSearch;

    ApplicationService applicationService;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_search);
        addControls();
        addEvents();
    }

    private void addEvents() {
        btnSearch.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                selectSearch();
            }
        });
    }

    private void selectSearch() {
        switch (spSearch.getSelectedItem().toString()){
            case "Day":
                selectDay();
                break;
            case "Mon":
                selectMonth();
                break;
            case "IdHistory":
                selectIdHistory();
                break;
            case "Year":
                selectYear();
                break;
            case "Hour":
                selectHour();
                break;
            case "NameUser":
                selectNameUser();
                break;
            case "IdCard":
                selectIDCard();
                break;

        }

    }

    private void addControls() {
        spSearch = (Spinner) findViewById(R.id.spSearch);
        data = (EditText) findViewById(R.id.editText);
        btnSearch = (Button) findViewById(R.id.btnSearch);

        lvSearch = (ListView) findViewById(R.id.lvSearch);
        searchArrayList = new ArrayList<>();
        adapterSearch = new HistoryAdapter(SearchActivity.this, R.layout.layout_item_history, searchArrayList);
        lvSearch.setAdapter(adapterSearch);
    }

    private void selectDay() {
        String cmd = "";
        String dataDay = data.getText().toString();

        JSONObject jsonObject = new JSONObject();
        try {
            jsonObject.put(Constants.ATTR_JSON_MESSAGE_STATUS_VALUE, Constants.ATTR_JSON_SELECT_YEU_CAU);
            jsonObject.put(Constants.ATTR_JSON_DAY, dataDay);
            cmd = jsonObject.toString();
            getRequest(cmd);
            System.out.println("Login: " + cmd);
        } catch (JSONException e) {
            e.printStackTrace();
            System.out.println("Lỗi");
        }
    }

    private void selectMonth() {
        String cmd = "";
        String dataMonth = data.getText().toString();

        JSONObject jsonObject = new JSONObject();
        try {
            jsonObject.put(Constants.ATTR_JSON_MESSAGE_STATUS_VALUE, Constants.ATTR_JSON_SELECT_YEU_CAU);
            jsonObject.put(Constants.ATTR_JSON_MONTH, dataMonth);
            cmd = jsonObject.toString();
            getRequest(cmd);
            System.out.println("Login: " + cmd);
        } catch (JSONException e) {
            e.printStackTrace();
            System.out.println("Lỗi");
        }
    }
    private void selectIdHistory() {
        String cmd = "";
        String dataIdHistory = data.getText().toString();

        JSONObject jsonObject = new JSONObject();
        try {
            jsonObject.put(Constants.ATTR_JSON_MESSAGE_STATUS_VALUE, Constants.ATTR_JSON_SELECT_YEU_CAU);
            jsonObject.put(Constants.ATTR_JSON_ID_HISTORY, dataIdHistory);
            cmd = jsonObject.toString();
            getRequest(cmd);
            System.out.println("Login: " + cmd);
        } catch (JSONException e) {
            e.printStackTrace();
            System.out.println("Lỗi");
        }
    }
    private void selectYear() {
        String cmd = "";
        String dataIdHistory = data.getText().toString();

        JSONObject jsonObject = new JSONObject();
        try {
            jsonObject.put(Constants.ATTR_JSON_MESSAGE_STATUS_VALUE, Constants.ATTR_JSON_SELECT_YEU_CAU);
            jsonObject.put(Constants.ATTR_JSON_YEAR, dataIdHistory);
            cmd = jsonObject.toString();
            getRequest(cmd);
            System.out.println("Login: " + cmd);
        } catch (JSONException e) {
            e.printStackTrace();
            System.out.println("Lỗi");
        }
    }
    private void selectHour() {
        String cmd = "";
        String dataIdHistory = data.getText().toString();

        JSONObject jsonObject = new JSONObject();
        try {
            jsonObject.put(Constants.ATTR_JSON_MESSAGE_STATUS_VALUE, Constants.ATTR_JSON_SELECT_YEU_CAU);
            jsonObject.put(Constants.ATTR_JSON_HOUR, dataIdHistory);
            cmd = jsonObject.toString();
            getRequest(cmd);
            System.out.println("Login: " + cmd);
        } catch (JSONException e) {
            e.printStackTrace();
            System.out.println("Lỗi");
        }
    }

    private void selectNameUser() {
        String cmd = "";
        String dataIdHistory = data.getText().toString();

        JSONObject jsonObject = new JSONObject();
        try {
            jsonObject.put(Constants.ATTR_JSON_MESSAGE_STATUS_VALUE, Constants.ATTR_JSON_SELECT_YEU_CAU);
            jsonObject.put(Constants.ATTR_JSON_NAME_USER, dataIdHistory);
            cmd = jsonObject.toString();
            getRequest(cmd);
            System.out.println("Login: " + cmd);
        } catch (JSONException e) {
            e.printStackTrace();
            System.out.println("Lỗi");
        }
    }

    private void selectIDCard() {
        String cmd = "";
        String dataIdHistory = data.getText().toString();

        JSONObject jsonObject = new JSONObject();
        try {
            jsonObject.put(Constants.ATTR_JSON_MESSAGE_STATUS_VALUE, Constants.ATTR_JSON_SELECT_YEU_CAU);
            jsonObject.put(Constants.ATTR_JSON_ID_CARD, dataIdHistory);
            cmd = jsonObject.toString();
            getRequest(cmd);
            System.out.println("Login: " + cmd);
        } catch (JSONException e) {
            e.printStackTrace();
            System.out.println("Lỗi");
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
                Toast.makeText(this, ""+json, Toast.LENGTH_LONG).show();
                JSONArray jsonArray = object.getJSONArray(Constants.ATTR_JSON_SELECT_YEU_CAU);
                Toast.makeText(this, ""+jsonArray, Toast.LENGTH_SHORT).show();
                searchArrayList.clear();
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


                    searchArrayList.add(history);

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
            Toast.makeText(SearchActivity.this, "Check Connection", Toast.LENGTH_LONG).show();
        }
    }
}
