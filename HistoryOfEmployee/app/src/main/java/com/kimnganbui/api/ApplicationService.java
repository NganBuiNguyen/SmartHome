package com.kimnganbui.api;


import java.io.File;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;



public class ApplicationService extends APIService implements
		RestClient.RestClientListener {

	private ServiceListener serviceListener;


	private final String url_getRequest = "http://192.168.3.100:8000/serverDjango/";
	
	//upload_file
	
	public ApplicationService(ServiceListener servListener) {
		//this.restClient = new RestClient("", Constants.AUTHENTICATION_USER, Constants.AUTHENTICATION_PASS);
		this.restClient = new RestClient("", "", "");
		this.serviceListener = servListener;
	}

	
	public void getRequest(String val){
		this.restClient.setUrl(url_getRequest);
		restClient.ClearParams();
		restClient.AddParam("cmd", val);
		restClient.addClientListener(this);
		this.serviceTask = this.getAsyncTaskInstance();
		this.serviceTask.setApiID(100); // id request
		this.serviceTask.execute(RestClient.RequestMethod.GET);// mothod
	}

	@Override
	public void onSuccess() {
		// TODO Auto-generated method stub
		if (this.serviceTask.getApiID() == 2 // array list return here
				) {
			if (this.restClient.getResponseCode() == 200) {
				try {
					JSONArray jsonArray = new JSONArray(this.restClient.getResponse());

					ResponseData responseData = new ResponseData();
					responseData.setResponseCode(this.restClient.getResponseCode());
					responseData.setResponseMessage(this.restClient.getErrorMessage());
					responseData.setJsonArray(jsonArray);
					responseData.setApiID(this.serviceTask.getApiID());
					serviceListener.onReceivedResponseSuccess(responseData);
				} catch (JSONException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
					onFail();
				}
			} else {
				onFail();
			}
		} else if (this.serviceTask.getApiID() == 1 // object return here
				) {
			if (this.restClient.getResponseCode() == 200) {
				try {
					JSONObject jsonObject = new JSONObject( this.restClient.getResponse());
					ResponseData responseData = new ResponseData();
					responseData.setResponseCode(this.restClient.getResponseCode());
					responseData.setResponseMessage(this.restClient.getErrorMessage());
					responseData.setJsonObject(jsonObject);
					responseData.setApiID(this.serviceTask.getApiID());
					serviceListener.onReceivedResponseSuccess(responseData);
				} catch (JSONException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
					onFail();
				}
			} else {
				onFail();
			}
		} else//default return  + data only
			if (this.restClient.getResponseCode() == 200) {
				String value = this.restClient.getResponse();
				ResponseData responseData = new ResponseData();
				responseData.setResponseCode(this.restClient.getResponseCode());
				responseData.setResponseMessage(this.restClient
						.getErrorMessage());
				responseData.setValue(value);
				responseData.setApiID(this.serviceTask.getApiID());
				serviceListener.onReceivedResponseSuccess(responseData);
			} else {
				onFail();
			}
	}

	@Override
	public void onFail() {
		// TODO Auto-generated method stub
		String value = this.restClient.getResponse();
		ResponseData responseData = new ResponseData();
		responseData.setResponseCode(this.restClient.getResponseCode());
		responseData.setResponseMessage(this.restClient.getErrorMessage());
		responseData.setApiID(this.serviceTask.getApiID());
		responseData.setValue(value);
		serviceListener.onReceivedResponseFail(responseData);
	}

}
