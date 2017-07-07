package com.kimnganbui.api;

import org.apache.http.HttpEntity;
import org.apache.http.HttpResponse;
import org.apache.http.NameValuePair;
import org.apache.http.auth.AuthScope;
import org.apache.http.auth.UsernamePasswordCredentials;
import org.apache.http.client.ClientProtocolException;
import org.apache.http.client.HttpClient;
import org.apache.http.client.methods.HttpDelete;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.client.methods.HttpPut;
import org.apache.http.client.methods.HttpUriRequest;
import org.apache.http.entity.StringEntity;
import org.apache.http.entity.mime.HttpMultipartMode;
import org.apache.http.entity.mime.MultipartEntity;
import org.apache.http.entity.mime.content.FileBody;
import org.apache.http.impl.client.AbstractHttpClient;
import org.apache.http.impl.client.DefaultHttpClient;
import org.apache.http.message.BasicNameValuePair;
import org.apache.http.params.HttpConnectionParams;
import org.json.JSONArray;
import org.json.JSONObject;

import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.net.URLEncoder;
import java.util.ArrayList;


public class RestClient {

	public enum RequestMethod {
		GET, POST, POST_GET, PUT, DELETE, DOWN_FROM_LINK, UPLOAD_FILE
	}

	String AUTHENTICATION_USER;
	String AUTHENTICATION_PASS;
	String fileParaName;
	
	public RestClientListener listener;
	private ArrayList<NameValuePair> params;
	private ArrayList<NameValuePair> headers;
	private String url;
	private int responseCode;
	private String message;
	private String response;
	private JSONObject postJSONObject;
	private JSONArray postJsonArray;
	private File file;

	
	
	public String getAUTHENTICATION_USER() {
		return AUTHENTICATION_USER;
	}

	public void setAUTHENTICATION_USER(String aUTHENTICATION_USER) {
		AUTHENTICATION_USER = aUTHENTICATION_USER;
	}

	public String getAUTHENTICATION_PASS() {
		return AUTHENTICATION_PASS;
	}

	public void setAUTHENTICATION_PASS(String aUTHENTICATION_PASS) {
		AUTHENTICATION_PASS = aUTHENTICATION_PASS;
	}

	public interface RestClientListener {
		public void onSuccess();

		public void onFail();
	}

	public File getFile() {
		return file;
	}

	public void setFile(File file, String fileParaName) {
		this.file = file;
		this.fileParaName = fileParaName;
	}

	public void addClientListener(RestClientListener listener) {
		this.listener = listener;
	}

	public void setUrl(String url) {
		this.url = url;
	}

	public void setPostJSONObject(JSONObject postJSONObject) {
		this.postJSONObject = postJSONObject;
	}

	public void setPostJsonArray(JSONArray jsonArray) {
		this.postJsonArray = jsonArray;
	}

	public String getResponse() {
		return response;
	}

	public String getErrorMessage() {
		return message;
	}

	public int getResponseCode() {
		return responseCode;
	}

	public RestClient(String url, String authorName, String authorPass) {
		this.url = url;
		params = new ArrayList<NameValuePair>();
		headers = new ArrayList<NameValuePair>();
		this.AUTHENTICATION_PASS = authorPass;
		this.AUTHENTICATION_USER = authorName;
	}

	public void AddParam(String name, String value) {
		params.add(new BasicNameValuePair(name, value));
	}

	public void AddHeader(String name, String value) {
		headers.add(new BasicNameValuePair(name, value));
	}

	public void ClearParams() {
		params.clear();
	}

	private void excuteGetMethod() throws IOException {
		// add parameters
		String combinedParams = "";
		if (!params.isEmpty()) {
			combinedParams += "?";
			for (NameValuePair p : params) {
				String paramString = p.getName() + "=" + URLEncoder.encode(p.getValue(), "UTF-8");
				if (combinedParams.length() > 1) {
					combinedParams += "&" + paramString;
				} else {
					combinedParams += paramString;
				}
			}
		}
		HttpGet request = new HttpGet(url + combinedParams);

		for (NameValuePair h : headers) {
			request.addHeader(h.getName(), h.getValue());
		}
		executeRequest(request, url);
	}

	private void excuteGetPostMethod() throws IOException {
		// add parameters
		String combinedParams = "";
		if (!params.isEmpty()) {
			combinedParams += "?";
			for (NameValuePair p : params) {
				String paramString = p.getName() + "=" + URLEncoder.encode(p.getValue(), "UTF-8");
				if (combinedParams.length() > 1) {
					combinedParams += "&" + paramString;
				} else {
					combinedParams += paramString;
				}
			}
		}
		HttpPost request = new HttpPost(url + combinedParams);
		for (NameValuePair h : headers) {
			request.addHeader(h.getName(), h.getValue());
		}
		executeRequest(request, url);
	}

	private void excutePostMethod() throws IOException {
		String combinedParams = "";
		String link = url;
		HttpPost request = null;
		StringEntity se = null;
		if (!params.isEmpty()) {

			combinedParams += "?";
			for (NameValuePair p : params) {
				String paramString = p.getName() + "=" + URLEncoder.encode(p.getValue(), "UTF-8");
				if (combinedParams.length() > 1) {
					combinedParams += "&" + paramString;
				} else {
					combinedParams += paramString;
				}
			}
			request = new HttpPost(url + combinedParams);
			link =  url + combinedParams;
		} else {
			request = new HttpPost(url);
			link = url;
		}
		if (postJSONObject != null) {
			se = new StringEntity(postJSONObject.toString(), "UTF_8");
			request.addHeader("Content-type", "application/json");
			request.setEntity(se);
		} else if (postJsonArray != null) {
			se = new StringEntity(postJsonArray.toString(), "UTF_8");
			request.addHeader("Content-type", "application/json");
			request.setEntity(se);

		}
		for (NameValuePair h : headers) {
			request.addHeader(h.getName(), h.getValue());
		}
		executeRequest(request, link);
	}
	
	private void excuteUploadFileMethod() throws IOException {
		String combinedParams = "";
		String link = url;
		HttpPost request = null;
		StringEntity se = null;
		if (!params.isEmpty()) {

			combinedParams += "?";
			for (NameValuePair p : params) {
				String paramString = p.getName() + "=" + URLEncoder.encode(p.getValue(), "UTF-8");
				if (combinedParams.length() > 1) {
					combinedParams += "&" + paramString;
				} else {
					combinedParams += paramString;
				}
			}
			request = new HttpPost(url + combinedParams);
			link =  url + combinedParams;
		} else {
			request = new HttpPost(url);
			link = url;
		}
		if(file!=null && file.exists()){
			FileBody fileBody = new FileBody(file);
			MultipartEntity reqEntity = new MultipartEntity(HttpMultipartMode.BROWSER_COMPATIBLE);
			reqEntity.addPart(fileParaName, fileBody);
			request.setEntity(reqEntity);
		}
		for (NameValuePair h : headers) {
			request.addHeader(h.getName(), h.getValue());
		}
		
		executeRequest(request, link);
	}

	private void excutePutMethod() throws IOException {
		// add parameters
		String combinedParams = "";
		String link = "";
		HttpPut request;
		if (!params.isEmpty()) {
			combinedParams += "?";
			for (NameValuePair p : params) {
				String paramString = p.getName() + "=" + URLEncoder.encode(p.getValue(), "UTF-8");
				if (combinedParams.length() > 1) {
					combinedParams += "&" + paramString;
				} else {
					combinedParams += paramString;
				}
			}
			request = new HttpPut(url + combinedParams);
			link = url + combinedParams;
		} else {
			request = new HttpPut(url);
			link = url;
		}
		
		if (postJSONObject != null) {
			StringEntity se = new StringEntity(postJSONObject.toString(), "UTF_8");
			request.addHeader("Content-type", "application/json");
			request.setEntity(se);
		} else if (postJsonArray != null) {
			StringEntity se = new StringEntity(postJsonArray.toString(), "UTF_8");
			request.addHeader("Content-type", "application/json");
			request.setEntity(se);
		}
		
		for (NameValuePair h : headers) {
			request.addHeader(h.getName(), h.getValue());
		}
		executeRequest(request, link);
	}

	private void excuteDeleteMethod() throws IOException {
		// add parameters
		String combinedParams = "";
		if (!params.isEmpty()) {
			combinedParams += "?";
			for (NameValuePair p : params) {
				String paramString = p.getName() + "=" + URLEncoder.encode(p.getValue(), "UTF-8");
				if (combinedParams.length() > 1) {
					combinedParams += "&" + paramString;
				} else {
					combinedParams += paramString;
				}
			}

		}
		HttpDelete request = new HttpDelete(url + combinedParams);

		// add headers
		for (NameValuePair h : headers) {
			request.addHeader(h.getName(), h.getValue());
		}

		executeRequest(request, url);
	}

	private void excuteDownFromLink() throws IOException {
		String combinedParams = "";
		if (!params.isEmpty()) {
			combinedParams += "?";
			for (NameValuePair p : params) {
				String paramString = p.getName() + "=" + URLEncoder.encode(p.getValue(), "UTF-8");
				if (combinedParams.length() > 1) {
					combinedParams += "&" + paramString;
				} else {
					combinedParams += paramString;
				}
			}

		}
		excuteRequest(url + combinedParams);
	}

	@SuppressWarnings("incomplete-switch")
	public void Execute(RequestMethod method) throws Exception {
		switch (method) {
		case GET:
			excuteGetMethod();
			break;
		case POST_GET: // Post with params in url
			excuteGetPostMethod();
			break;
		case POST:
			excutePostMethod();
			break;
		case PUT:
			excutePutMethod();
			break;
		case DELETE:
			excuteDeleteMethod();
			break;
		case DOWN_FROM_LINK:
			excuteDownFromLink();
			break;
		case UPLOAD_FILE:
			excuteUploadFileMethod();
			break;
		}
	}

	private void excuteRequest(String strUrl) throws IOException {
		InputStream iStream = null;
		HttpURLConnection urlConnection = null;
		try {
			URL url = new URL(strUrl);
			urlConnection = (HttpURLConnection) url.openConnection();
			urlConnection.connect();
			iStream = urlConnection.getInputStream();
			responseCode = urlConnection.getResponseCode();
			message = urlConnection.getResponseMessage();
			response = convertStreamToString(iStream);
		} catch (Exception e) {
		} finally {
			iStream.close();
			urlConnection.disconnect();
		}
	}

	private void executeRequest(HttpUriRequest request, String url) throws IOException {

		HttpClient client = new DefaultHttpClient();
		HttpConnectionParams.setConnectionTimeout(client.getParams(), 30000 );//30s time out
		HttpResponse httpResponse;

		try {
			((AbstractHttpClient) client).getCredentialsProvider().setCredentials(AuthScope.ANY,
					new UsernamePasswordCredentials(AUTHENTICATION_USER, AUTHENTICATION_PASS));
			httpResponse = client.execute(request);
			responseCode = httpResponse.getStatusLine().getStatusCode();
			message = httpResponse.getStatusLine().getReasonPhrase();

			HttpEntity entity = httpResponse.getEntity();

			if (entity != null) {
				InputStream instream = entity.getContent();
				response = convertStreamToString(instream);
				instream.close();
			}

		} catch (ClientProtocolException e) {
			client.getConnectionManager().shutdown();
			message = e.getMessage();
			throw e;
		} catch (IOException e) {
			client.getConnectionManager().shutdown();
			e.printStackTrace();
			message = e.getMessage();
			throw e;
		}
	}

	private static String convertStreamToString(InputStream is) {

		BufferedReader reader = new BufferedReader(new InputStreamReader(is));
		StringBuilder sb = new StringBuilder();

		String line = null;
		try {
			while ((line = reader.readLine()) != null) {
				sb.append(line + "\n");
			}
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				is.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		return sb.toString();
	}
}
