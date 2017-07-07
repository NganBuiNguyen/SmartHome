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
import android.widget.TextView;

import com.kimnganbui.historyofemployee.R;
import com.kimnganbui.models.History;
import com.kimnganbui.models.User;

import java.util.List;

/**
 * Created by ngan-bui on 06/07/2017.
 */

public class UserAdapter extends ArrayAdapter<User> {
    Activity context;
    int resource;
    List<User> objects;


    public UserAdapter(@NonNull Activity context, @LayoutRes int resource, @NonNull List<User> objects) {
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

        TextView txtIDUser = (TextView) view.findViewById(R.id.txtIDUser);
        TextView txtNameUser = (TextView) view.findViewById(R.id.txtNameUser);

        User user = this.objects.get(position);
        txtIDUser.setText("ID User: "+ user.getIduser());
        txtNameUser.setText("Name User :"+ user.getNameUser());

        return view;
    }
}
