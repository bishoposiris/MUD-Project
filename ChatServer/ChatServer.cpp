// MUD Programming
// Ron Penton
// (C)2003
// Demo06-02.cpp - A simple chat server
// 
// 

#include "stdafx.h"
#include "../MUDLibrary/SocketLibrary/SocketLib.h"
#include "SCUserDB.h"
#include "SCLogon.h"
#include "SCChat.h"
#include <iostream>
#include <exception>


int main()
{
	using SocketLib::Telnet;

	try
	{
		SocketLib::ListeningManager<Telnet, SCLogon> lm;
		SocketLib::ConnectionManager<Telnet, SCLogon> cm(128);

		lm.SetConnectionManager(&cm);
		lm.AddPort(5099);

		while (1)
		{
			lm.Listen();
			cm.Manage();
			ThreadLib::YieldThread();
		}
	}

	catch (SocketLib::Exception& ex)
	{
		std::cerr << "Exception from ChatServer: " << ex.PrintError() << "\n\n";
	}

	catch (const std::exception& e) // #include <exception>
	{
		std::cerr << "Runtime error: " << e.what() << "\n\n";
	}

}
