package com.kimnganbui.historyofemployee;

import android.content.Intent;
import android.os.AsyncTask;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.kimnganbui.api.APIService;
import com.kimnganbui.api.ApplicationService;
import com.kimnganbui.api.ResponseData;
import com.kimnganbui.models.HttpRequest;
import com.kimnganbui.models.User;

import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;


public class MainActivity extends AppCompatActivity implements APIService.ServiceListener{
    ApplicationService applicationService;
    EditText txtUserName, txtPassword;
    Button btnLogin;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        addControl();
        addEvent();
    }

    private void doLoginJson() {
        String cmd = "";
        String username = txtUserName.getText().toString();
        String password = txtPassword.getText().toString();

        if(username.isEmpty() == false && password.isEmpty() == false) {
            if (Constants.whiteSpace(username) == false && Constants.whiteSpace(password) == false) {
                if(Constants.usernameCharacterSpecial(username) == false) {
                    if(Constants.checkUsernameLength(username) == false && Constants.checkPasswordLength(password) == false) {
                        JSONObject jsonObject = new JSONObject();
                        try {
                            jsonObject.put(Constants.ATTR_JSON_MESSAGE_STATUS_VALUE, Constants.ATTR_JSON_MESSAGE_STATUS_VALUE_LOGIN);
                            jsonObject.put(Constants.ATTR_JSON_USER_NAME, username);
                            jsonObject.put(Constants.ATTR_JSON_PASSWORD, password);
                            cmd = jsonObject.toString();
                            getRequest(cmd);
                            System.out.println("Login: " + cmd);
                        } catch (JSONException e) {
                            e.printStackTrace();
                            System.out.println("Lỗi");
                        }
                    }else {
                        Toast.makeText(this, "UserName và Password không đúng chiều dài", Toast.LENGTH_SHORT).show();
                    }
                }else {
                    Toast.makeText(this, "UserName tồn tại kí tự đặc biệt", Toast.LENGTH_SHORT).show();
                }
            } else {
                Toast.makeText(MainActivity.this,"UserName và Password không được tồn tại khoảng trắng", Toast.LENGTH_LONG).show();
            }
        }else{
            Toast.makeText(this,"UserName và Password rỗng" , Toast.LENGTH_LONG).show();
        }

    }

    private void getRequest(String val){
        applicationService = new ApplicationService(this);
        applicationService.getRequest(val);
    }

    private void addEvent() {
        btnLogin.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                doLoginJson();
            }
        });
    }

    private void addControl() {
        btnLogin = (Button) findViewById(R.id.btnLogin);
        txtUserName = (EditText) findViewById(R.id.txtUserName);
        txtPassword = (EditText) findViewById(R.id.txtPassword);
    }

    @Override
    public void onReceivedResponseSuccess(ResponseData respData) {
        if(respData.getApiID() == 100){
            String json = respData.getValue();

            try {
                JSONObject object = new JSONObject(json);
                String json_mess = object.getString("LOGIN");
                JSONObject object_mess = new JSONObject(json_mess);
                String message = object_mess.getString("MESSAGE_TYPE");

                if (message.equals(Constants.ATTR_JSON_LOGIN_SUCCESSFUL_ADMIN))
                {
                    Toast.makeText(this, "Bạn đang đăng nhập với quyền người quản trị hệ thống", Toast.LENGTH_SHORT).show();
                    Intent intent = new Intent(MainActivity.this,NavigationActivity.class);
                    startActivity(intent);
                }
                else if(message.equals(Constants.ATTR_JSON_LOGIN_SUCCESSFUL_USER))
                {
                    Toast.makeText(this, "Bạn đang đăng nhập với quyền người quản lí", Toast.LENGTH_SHORT).show();
                    Intent intent = new Intent(MainActivity.this,NavigationActivity.class);
                    startActivity(intent);
                }
                else{
                    Toast.makeText(this, "UserName và Password không đúng", Toast.LENGTH_SHORT).show();
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
            Toast.makeText(MainActivity.this, "Check Connection", Toast.LENGTH_LONG).show();
        }

    }

//    private class UserTask extends AsyncTask<String,Void,String> {
//
//        @Override
//        protected String doInBackground(String... params) {
//            try {
//                return HttpRequest.get(params[0]).accept("application/json").body();
//
//            }catch (Exception ex){
//                return "";
//            }
//        }
//
//
//        @Override
//        protected void onPostExecute(String result) {
//            if(result.isEmpty()){
//                Toast.makeText(MainActivity.this, "EMPTY", Toast.LENGTH_LONG).show();
//            }else {
//                ArrayList<User> user = User.pareUsers(result);
//                int flag = 0;
//                for(int i = 0; i< user.size() ;i++)
//                {
//                    if((user.get(i).getUsername().equals(txtUserName.getText().toString().trim())) && (user.get(i).getPassword().equals(txtPassword.getText().toString().trim())))
//                    {
//                         flag = 1;
//                        Intent intent = new Intent(MainActivity.this,ListSearchActivity.class);
//                        startActivity(intent);
//                    }
//
//                }
//                if(flag == 0) {
//                    Toast.makeText(MainActivity.this, "Mật khẩu hoặc Tên người dùng sai!", Toast.LENGTH_SHORT).show();
//                }
//            }
//        }
//
//    }
}
