package com.kimnganbui.historyofemployee;

import android.content.Intent;
import android.graphics.Color;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.LinearLayout;
import android.widget.Toast;

import com.kimnganbui.api.APIService;
import com.kimnganbui.api.ApplicationService;
import com.kimnganbui.api.ResponseData;
import com.kimnganbui.models.User;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

public class ShowPositionActivity extends AppCompatActivity implements APIService.ServiceListener {

    LinearLayout lnP0001;
    LinearLayout lnP0002;
    ApplicationService applicationService;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_show_position);
        setViewFromIntentData();
        addControls();
    }

    private void addControls() {
        lnP0001 = (LinearLayout) findViewById(R.id.lnP0001);
        lnP0002 = (LinearLayout) findViewById(R.id.lnP0002);
    }

    private void setViewFromIntentData() {
        Intent intent = getIntent();
        String nhan = intent.getStringExtra("VITRI");

        if (nhan == null) {
            Toast.makeText(this, "Không tìm được vị trí", Toast.LENGTH_SHORT).show();

        } else {
            String cmd = "";
            JSONObject object = new JSONObject();
            try {
                object.put(Constants.ATTR_JSON_MESSAGE_STATUS_VALUE, Constants.ATTR_JSON_SELECT_POSITION);
                object.put(Constants.ATTR_JSON_NAME_USER, nhan);
                cmd = object.toString();
                getRequest(cmd);
                System.out.println("SELECT history: " + cmd);
            } catch (JSONException e) {
                e.printStackTrace();
                System.out.println("JSON history error");
            }
            Toast.makeText(this, " " + nhan, Toast.LENGTH_SHORT).show();
        }
    }


    private void getRequest(String val) {
        applicationService = new ApplicationService(this);
        applicationService.getRequest(val);
    }

    @Override
    public void onReceivedResponseSuccess(ResponseData respData) {
        if(respData.getApiID() == 100){
            String json = respData.getValue();
            try {
                JSONObject object = new JSONObject(json);
                JSONArray jsonArray = object.getJSONArray(Constants.ATTR_JSON_SELECT_POSITION);

                for(int i =0; i < jsonArray.length(); i++) {
                    JSONObject jsonObject = jsonArray.getJSONObject(i);

                    String idRoom = jsonObject.getString("IDRoom");
                    Toast.makeText(this, "" + idRoom, Toast.LENGTH_SHORT).show();

                    if(idRoom.equals("P0001"))
                    {
                        lnP0001.setBackgroundColor(Color.parseColor("#660000"));
                    }
                    else if(idRoom.equals("P0002"))
                    {
                        lnP0002.setBackgroundColor(Color.parseColor("#660000"));
                    }
                    else
                    {
                        Toast.makeText(this, "Nhân Viên không có mặt ở phòng ban", Toast.LENGTH_SHORT).show();
                    }

                }
            }catch (JSONException e){
                e.printStackTrace();
                System.out.println("JSON select error");
            }
        }
    }

    @Override
    public void onReceivedResponseFail(ResponseData respData) {
        if(respData.getApiID() == 100){
            //alert
            Toast.makeText(ShowPositionActivity.this, "Check Connection", Toast.LENGTH_LONG).show();
        }
    }
}
