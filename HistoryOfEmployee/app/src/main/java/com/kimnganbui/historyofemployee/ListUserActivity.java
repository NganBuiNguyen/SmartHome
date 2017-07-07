package com.kimnganbui.historyofemployee;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.Toast;


import com.kimnganbui.adapter.UserAdapter;
import com.kimnganbui.api.APIService;
import com.kimnganbui.api.ApplicationService;
import com.kimnganbui.api.ResponseData;
import com.kimnganbui.models.History;
import com.kimnganbui.models.User;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;

public class ListUserActivity extends AppCompatActivity implements APIService.ServiceListener{
    EditText txtUser;
    Button btnSearch;

    ListView lvUser;
    ArrayList<User> userArrayList;
    UserAdapter adapterUser;

    ApplicationService applicationService;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_list_user);
        selectUser();
        addControls();
        addEvents();
    }

    private void addEvents() {
        btnSearch.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                selectUserYeuCau();
            }
        });

        lvUser.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                Intent intent = new Intent(ListUserActivity.this,ShowPositionActivity.class);
                String maGui = userArrayList.get(position).getNameUser();
                intent.putExtra("VITRI",maGui);
                startActivityForResult(intent,1);
            }
        });
    }

    private void addControls() {
        txtUser = (EditText) findViewById(R.id.txtUser);
        btnSearch = (Button) findViewById(R.id.btnSearch);

        lvUser = (ListView) findViewById(R.id.lvUser);
        userArrayList = new ArrayList<>();
        adapterUser = new UserAdapter(ListUserActivity.this, R.layout.item_list_user, userArrayList);
        lvUser.setAdapter(adapterUser);
    }

    private void getRequest(String val) {
        applicationService = new ApplicationService(this);
        applicationService.getRequest(val);
    }

    private void selectUser() {
        String cmd = "";
        JSONObject object = new JSONObject();
        try {
            object.put(Constants.ATTR_JSON_MESSAGE_STATUS_VALUE, Constants.ATTR_JSON_SELECT_USER);
            cmd = object.toString();
            getRequest(cmd);
            Toast.makeText(ListUserActivity.this, "SELECT history: " + cmd, Toast.LENGTH_LONG).show();
            Toast.makeText(ListUserActivity.this, "SELECT history: " + object, Toast.LENGTH_LONG).show();
            System.out.println("SELECT history: " + cmd);
        } catch (JSONException e) {
            e.printStackTrace();
            System.out.println("JSON history error");
        }

    }

    private void selectUserYeuCau() {
        String name = txtUser.getText().toString();
        String cmd = "";
        JSONObject object = new JSONObject();
        try {
            object.put(Constants.ATTR_JSON_MESSAGE_STATUS_VALUE, Constants.ATTR_JSON_SELECT_USER);
            object.put(Constants.ATTR_JSON_NAME_USER, name);
            cmd = object.toString();
            getRequest(cmd);
            Toast.makeText(ListUserActivity.this, "SELECT history: " + cmd, Toast.LENGTH_LONG).show();
            Toast.makeText(ListUserActivity.this, "SELECT history: " + object, Toast.LENGTH_LONG).show();
            System.out.println("SELECT history: " + cmd);
        } catch (JSONException e) {
            e.printStackTrace();
            System.out.println("JSON history error");
        }
    }


    @Override
    public void onReceivedResponseSuccess(ResponseData respData) {
        if(respData.getApiID() == 100){
            String json = respData.getValue();
            try {
                JSONObject object = new JSONObject(json);
                JSONArray jsonArray = object.getJSONArray(Constants.ATTR_JSON_SELECT_USER);
                userArrayList.clear();
                for(int i =0; i < jsonArray.length(); i++) {
                    User user = new User();
                    JSONObject jsonObject = jsonArray.getJSONObject(i);

                    String idUser = jsonObject.getString("IDUser");
                    user.setIduser(idUser);

                    String nameUser = jsonObject.getString("NameUser");
                    user.setNameUser(nameUser);

                    userArrayList.add(user);
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
            Toast.makeText(ListUserActivity.this, "Check Connection", Toast.LENGTH_LONG).show();
        }
    }
}
