package com.kimnganbui.classes;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.TextView;

import com.kimnganbui.testconectdjango.R;

import java.util.ArrayList;

/**
 * Created by ngan-bui on 20/06/2017.
 */

public class HistoryAdapter extends BaseAdapter {
    Context context ;
    ArrayList<History> listHistory;

    public HistoryAdapter(Context context, ArrayList<History> listHistory) {
        this.context = context;
        this.listHistory = listHistory;
    }

    @Override
    public int getCount() {
        return this.listHistory.size();
    }

    @Override
    public Object getItem(int position) {
        return this.listHistory.get(position);
    }

    @Override
    public long getItemId(int position) {
        return position;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        LayoutInflater layoutInflater = (LayoutInflater) context.getSystemService(context.LAYOUT_INFLATER_SERVICE);
        View view = layoutInflater.inflate(R.layout.layout_item_history, parent, false);

        TextView txtIdHistory = (TextView) view.findViewById(R.id.txtIdHistory);
        TextView txtDay = (TextView) view.findViewById(R.id.txtDay);
        TextView txtMon = (TextView) view.findViewById(R.id.txtMon);
        TextView txtYear = (TextView) view.findViewById(R.id.txtYear);
        TextView txtHour = (TextView) view.findViewById(R.id.txtHour);
        TextView txtMin = (TextView) view.findViewById(R.id.txtMin);
        TextView txtSec = (TextView) view.findViewById(R.id.txtSec);
        TextView txtStatusdoor = (TextView) view.findViewById(R.id.txtStatusDoor);
        TextView txtCheckcard = (TextView) view.findViewById(R.id.txtCheckCard);


        History history = this.listHistory.get(position);
        if(history != null){
            txtIdHistory.setText("IdHistory: " + history.getIdhistory());
            txtDay.setText("Day: "+ history.getDay());
            txtMon.setText("Mon: "+ history.getMon());
            txtYear.setText("Year: "+ history.getYear());
            txtHour.setText("Hour: "+ history.getHour());
            txtMin.setText("Min: "+ history.getMin());
            txtSec.setText("Sec: "+ history.getSec());
            txtStatusdoor.setText("StatusDoor: "+ history.getStatusdoor());
            txtCheckcard.setText("Checkcard: " + history.getCheckcard());
        }

        return view;
    }
}
