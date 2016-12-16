#include <iostream>

#include "Poco/Net/TCPServer.h"
#include "Poco/Net/TCPServerConnection.h"
#include "Poco/Net/TCPServerConnectionFactory.h"
#include "Poco/Net/TCPServerParams.h"
#include "Poco/Net/StreamSocket.h"
#include "Poco/Net/ServerSocket.h"
#include "Poco/Timestamp.h"
#include "Poco/DateTimeFormatter.h"
#include "Poco/DateTimeFormat.h"
#include "Poco/Exception.h"
#include "Poco/Util/ServerApplication.h"
#include "Poco/Util/Option.h"
#include "Poco/Util/OptionSet.h"
#include "Poco/Util/HelpFormatter.h"


using Poco::Net::ServerSocket;
using Poco::Net::StreamSocket;
using Poco::Net::TCPServerConnection;
using Poco::Net::TCPServerConnectionFactory;
using Poco::Net::TCPServer;
using Poco::Timestamp;
using Poco::DateTimeFormatter;
using Poco::DateTimeFormat;
using Poco::Util::ServerApplication;
using Poco::Util::Application;
using Poco::Util::Option;
using Poco::Util::OptionSet;
using Poco::Util::HelpFormatter;


class TimeServerConnection: public TCPServerConnection
{

public:
    TimeServerConnection(const StreamSocket& s, const std::string& format): 
		TCPServerConnection(s),
		_format(format)
    {

    }
	
	void run()
	{
		Application& app = Application::instance();
		app.logger().information("Request from " + this->socket().peerAddress().toString());
		try
		{
			Timestamp now;
			std::string dt(DateTimeFormatter::format(now, _format));
			dt.append("\r\n");
			socket().sendBytes(dt.data(), (int) dt.length());
		}
		catch (Poco::Exception& exc)
		{
			app.logger().log(exc);
		}
	}
	
private:
	std::string _format;
};


class TimeServerConnectionFactory: public TCPServerConnectionFactory
{
public:
	TimeServerConnectionFactory(const std::string& format):
		_format(format)
	{
	}
	
	TCPServerConnection* createConnection(const StreamSocket& socket)
	{
		return new TimeServerConnection(socket, _format);
	}

private:
	std::string _format;
};


class TimeServer: public Poco::Util::ServerApplication
{
public:
	TimeServer(): _helpRequested(false)
	{
	}
	
	~TimeServer()
	{
	}

protected:
	void initialize(Application& self)
	{
		loadConfiguration(); // load default configuration files, if present
		ServerApplication::initialize(self);
	}
		
	void uninitialize()
	{
		ServerApplication::uninitialize();
	}

	void defineOptions(OptionSet& options)
	{
		ServerApplication::defineOptions(options);
		
		options.addOption(
			Option("help", "h", "display help information on command line arguments")
				.required(false)
				.repeatable(false));
	}

	void handleOption(const std::string& name, const std::string& value)
	{
		ServerApplication::handleOption(name, value);

		if (name == "help")
			_helpRequested = true;
	}

	void displayHelp()
	{
		HelpFormatter helpFormatter(options());
		helpFormatter.setCommand(commandName());
		helpFormatter.setUsage("OPTIONS");
		helpFormatter.setHeader("A server application that serves the current date and time.");
		helpFormatter.format(std::cout);
	}

	int main(const std::vector<std::string>& args)
	{
		if (_helpRequested)
		{
			displayHelp();
		}
		else
		{
			// get parameters from configuration file
			unsigned short port = (unsigned short) config().getInt("TimeServer.port", 9911);
			std::string format(config().getString("TimeServer.format", DateTimeFormat::ISO8601_FORMAT));
			
			// set-up a server socket
			ServerSocket svs(port);
			// set-up a TCPServer instance
			TCPServer srv(new TimeServerConnectionFactory(format), svs);
			// start the TCPServer
			srv.start();
			// wait for CTRL-C or kill
			waitForTerminationRequest();
			// Stop the TCPServer
			srv.stop();
		}
		return Application::EXIT_OK;
	}
	
private:
	bool _helpRequested;
};


int main(int argc, char** argv)
{
	TimeServer app;
	return app.run(argc, argv);
}
