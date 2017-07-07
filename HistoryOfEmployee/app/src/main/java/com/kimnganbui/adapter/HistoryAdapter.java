package com.kimnganbui.adapter;

import android.app.Activity;
import android.content.Context;
import android.support.annotation.LayoutRes;
import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.BaseAdapter;
import android.widget.TextView;

import com.kimnganbui.api.ApplicationService;
import com.kimnganbui.models.History;
import com.kimnganbui.historyofemployee.R;

import java.util.ArrayList;
import java.util.List;



public class HistoryAdapter extends ArrayAdapter<History> {
        Activity context;
        int resource;
        List<History> objects;

    public HistoryAdapter(@NonNull Activity context, @LayoutRes int resource, @NonNull List<History> objects) {
        super(context, resource, objects);
        this.context = context;
        this.resource = resource;
        this.objects = objects;
    }

    @NonNull
    @Override
    public View getView(int position, @Nullable View convertView, @NonNull ViewGroup parent) {
        LayoutInflater inflater = this.context.getLayoutInflater();
        View view = inflater.inflate(this.resource, null);


        TextView txtDay = (TextView) view.findViewById(R.id.txtDay);
        TextView txtCard = (TextView) view.findViewById(R.id.txtIDCard);
        TextView txtIdDoor = (TextView) view.findViewById(R.id.txtIDDoor);
        TextView txtIdHistory = (TextView) view.findViewById(R.id.txtIdHistory);
        TextView txtNameUser = (TextView) view.findViewById(R.id.txtNameUser);
        TextView txtCheckCard = (TextView) view.findViewById(R.id.txtCheckCard);
        TextView txtStatusDoor = (TextView) view.findViewById(R.id.txtStatusDoor);

        History history = this.objects.get(position);

        txtDay.setText("Date Time: "+ history.getDay()+"/"+history.getMon()+"/"+history.getYear()+" "+
                    history.getHour()+":"+history.getMin()+":"+history.getSec());

        txtCard.setText("Id Card: " + history.getIdCard());
        txtIdDoor.setText("Id Door: " + history.getIdDoor());
        txtIdHistory.setText("Id History: " + history.getIdhistory());
        txtNameUser.setText("Nam User: "+ history.getNameUser());
        txtCheckCard.setText("Check Card: "+ history.getCheckcard());
        txtStatusDoor.setText("Status Door: " + history.getStatusdoor());
        return view;

    }

}
