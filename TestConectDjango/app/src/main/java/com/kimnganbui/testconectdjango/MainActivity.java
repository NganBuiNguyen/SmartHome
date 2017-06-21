package com.kimnganbui.testconectdjango;

import android.os.AsyncTask;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.ArrayAdapter;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.Spinner;
import android.widget.Toast;

import com.kimnganbui.classes.History;


import java.util.ArrayList;

import com.kimnganbui.classes.HistoryAdapter;
import com.kimnganbui.classes.HttpRequest;


public class MainActivity extends AppCompatActivity {

    Spinner spHistory;
    EditText data;
    ListView lvHistory;



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        addEvents();
        addControls();
    }

    private void addControls() {
        spHistory = (Spinner) findViewById(R.id.spHistory);
        data = (EditText) findViewById(R.id.editText);
        lvHistory = (ListView) findViewById(R.id.lvHistory);



        new HistoryTask().execute("http://192.168.1.7:8000/rest/historys/");
    }

    private void addEvents() {

    }

    private class HistoryTask extends AsyncTask<String,Void,String> {

        @Override
        protected String doInBackground(String... params) {
            try {
                return HttpRequest.get(params[0]).accept("application/json").body();

            }catch (Exception ex){
                return "";
            }
        }


        @Override
        protected void onPostExecute(String result) {
            if(result.isEmpty()){
                Toast.makeText(MainActivity.this, "EMPTY", Toast.LENGTH_LONG).show();
            }else {
                ArrayList<History> his = History.pareHistorys(result);
                ArrayList<History> history_list  = new ArrayList<>();
                if(spHistory.getSelectedItem().toString().equals("List History"))
                {
                    history_list = his;
                }else{
                    for(int i = 0; i< his.size() ;i++)
                    {
                        switch (spHistory.getSelectedItem().toString()){
                            case "IdHistory":
                                if(his.get(i).getIdhistory().equals(data.getText().toString().trim()))
                                     {
                                         history_list.add(his.get(i));
                                     }
                                break;

                            case "day":
                                if(his.get(i).getDay().equals(data.getText().toString().trim()))
                                {
                                    history_list.add(his.get(i));
                                }
                                break;
                            case "mon":
                                if(his.get(i).getMon() .equals(data.getText().toString().trim()))
                                {
                                    history_list.add(his.get(i));
                                }
                                break;
                            case "year":
                                if(his.get(i).getYear().equals(data.getText().toString().trim()))
                                {
                                    history_list.add(his.get(i));
                                }
                                break;
                            case "hour":
                                if(his.get(i).getHour().equals(data.getText().toString().trim()))
                                {
                                    history_list.add(his.get(i));
                                }
                                break;
                            case "min":
                                if(his.get(i).getMin().equals(data.getText().toString().trim()))
                                {
                                    history_list.add(his.get(i));
                                }
                                break;
                            case "sec":
                                if(his.get(i).getSec().equals(data.getText().toString().trim()))
                                {
                                    history_list.add(his.get(i));
                                }
                                break;
                            case "statusdoor":
                                if(his.get(i).getIdhistory().equals(data.getText().toString().trim()))
                                {
                                    history_list.add(his.get(i));
                                }
                                break;
                            case "checkcard":
                                if(his.get(i).getIdhistory().equals(data.getText().toString().trim()))
                                {
                                    history_list.add(his.get(i));
                                }
                                break;
                        }
                    }
                }

                if (history_list.size() !=0)
                {
                    HistoryAdapter adapter = new HistoryAdapter(MainActivity.this , history_list);
                    lvHistory.setAdapter(adapter);
                }
            }
        }

//        @Override
//        protected void onProgressUpdate(Void... values) {
//            super.onProgressUpdate(values);
//        }
    }
}
