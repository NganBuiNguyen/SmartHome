package com.kimnganbui.api;



import android.os.AsyncTask;

public class APIService {
	public interface ServiceListener {
		public void onReceivedResponseSuccess(ResponseData respData);

		public void onReceivedResponseFail(ResponseData respData);
	}

	public RestClient restClient;
	public ApiAsyncTask serviceTask;

	public ApiAsyncTask getAsyncTaskInstance() {
		serviceTask = new ApiAsyncTask();
		return serviceTask;
	}

	public class ApiAsyncTask extends AsyncTask<RestClient.RequestMethod, Void, Boolean> {
		private int ApiID;

		@Override
		protected Boolean doInBackground(RestClient.RequestMethod... params) {
			try {
				restClient.Execute(params[0]);

				return true;
			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();

			}
			return false;
		}

		@Override
		protected void onPostExecute(Boolean result) {
			if (result) {
				
				restClient.listener.onSuccess();
				serviceTask.cancel(true);
			} else {
				restClient.listener.onFail();
				serviceTask.cancel(true);
			}
		}

		public void setApiID(int apiID) {
			this.ApiID = apiID;
		}

		public int getApiID() {
			return this.ApiID;
		}
	}
}
