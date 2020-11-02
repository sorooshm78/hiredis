#include <string>
#include <iostream>

#include <hiredis/hiredis.h>

#include "SomRedis.h"

using namespace std;

int main()
{
	cout << "-----------" << endl;
	cout << "connect by unix socket" << endl;
	somredis s("/var/run/redis/redis.sock");
	cout << "-----------" << endl;
	//cout << "test error connect to redis" << endl;
	//somredis err("127.0.0.22",80);
	cout << "-----------" << endl;
	//cout << "connect by ip/port" << endl;
	//somredis s("127.0.0.1", 6379);
	cout << "key and value normal" << endl;
	s.insert("fname","mehran");
	cout << "SET fname mehran" << endl;
	cout << "get fname: " << s.get("fname") << endl;
    cout << "-----------" << endl;
	cout << "key normal and value by space" << endl;
	s.insert("lname","sed soroosh");
	cout << "SET lname sed soroosh" << endl;
	cout << "get lname: " << s.get("lname") << endl;
	cout << "-----------" << endl;
	cout << "key by space and value normal" << endl;
	s.insert("first name","ahmad");
	cout << "SET first name = ahmad" << endl;
	cout << "get first name: " << s.get("first name") << endl;
	cout << "-----------" << endl;
	cout << "key and value by space" << endl;
	s.insert("last name","allah gholi");
	cout << "SET last name = allah gholi" << endl;
	cout << "get last name: " << s.get("last name") << endl;	
	cout << "-----------" << endl;
	cout << "test get functions return empty:\"" << s.get("age") << "\"" << endl;
	if(s.get("age").empty() == 1)	
		cout << "return empty string" << endl;
	cout << "-----------" << endl;
	cout << "size befor clear: " << s.size() << endl;
	cout << "empty: " << s.empty() << endl;
	cout << "-----------" << endl;
	s.clear();
	cout << "clear database" << endl;
	cout << "-----------" << endl;
	cout << "size after clear: " << s.size() << endl;
	cout << "empty: " << s.empty() << endl;
	cout << "-----------" << endl;
}
