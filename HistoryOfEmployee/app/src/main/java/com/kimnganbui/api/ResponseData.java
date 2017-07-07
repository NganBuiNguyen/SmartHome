package com.kimnganbui.api;

import org.json.JSONArray;
import org.json.JSONObject;

public class ResponseData {

	enum ResponseType {
		JSONArray, JSONObject,

	}

	private int responseCode;
	private String responseMessage;
	private String value;
	public String getValue() {
		return value;
	}

	public void setValue(String value) {
		this.value = value;
	}

	private JSONObject jsonObject;
	private JSONArray jsonArray;
	private ResponseType responseType;
	private int apiID;

	public int getApiID() {
		return apiID;
	}

	public void setApiID(int apiID) {
		this.apiID = apiID;
	}

	public ResponseType getResponseType() {
		return responseType;
	}

	public void setResponseType(ResponseType responseType) {
		this.responseType = responseType;
	}

	public ResponseData() {
		this.responseType = ResponseType.JSONObject;
	}

	public JSONArray getJsonArray() {
		return jsonArray;
	}

	public void setJsonArray(JSONArray jsonArray) {
		this.jsonArray = jsonArray;
	}

	public int getResponseCode() {
		return responseCode;
	}

	public void setResponseCode(int responseCode) {
		this.responseCode = responseCode;
	}

	public String getResponseMessage() {
		return responseMessage;
	}

	public void setResponseMessage(String responseMessage) {
		this.responseMessage = responseMessage;
	}

	public JSONObject getJsonObject() {
		return jsonObject;
	}

	public void setJsonObject(JSONObject jsonObject) {
		this.jsonObject = jsonObject;
	}
}
