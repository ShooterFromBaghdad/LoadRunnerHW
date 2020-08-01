Action()
{

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_start_transaction("3.1_tr_login");

	web_revert_auto_header("Sec-Fetch-User");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	lr_think_time(22);

	web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value=129243.42980964zztHQfipQcAiDDDDDQiiHpHfDfcf", ENDITEM, 
		"Name=username", "Value=jojo", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=login.x", "Value=53", ENDITEM, 
		"Name=login.y", "Value=12", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		LAST);

	lr_end_transaction("3.1_tr_login",LR_AUTO);

	lr_start_transaction("3.2_Itinerary_button");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(55);

	web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("3.2_Itinerary_button",LR_AUTO);

	lr_start_transaction("3.3_tr_Cancel_all_button");

	web_add_header("Origin", 
		"http://localhost:1080");

	lr_think_time(42);

	web_submit_data("itinerary.pl", 
		"Action=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=flightID", "Value=0-7-JB", ENDITEM, 
		"Name=flightID", "Value=0-15-JB", ENDITEM, 
		"Name=flightID", "Value=292222981-2345-JB", ENDITEM, 
		"Name=flightID", "Value=292223054-3112-JB", ENDITEM, 
		"Name=flightID", "Value=292223054-3881-JB", ENDITEM, 
		"Name=flightID", "Value=292223054-4651-JB", ENDITEM, 
		"Name=flightID", "Value=292223054-5420-JB", ENDITEM, 
		"Name=flightID", "Value=292223054-6189-JB", ENDITEM, 
		"Name=flightID", "Value=292223054-6958-JB", ENDITEM, 
		"Name=flightID", "Value=292223054-7728-JB", ENDITEM, 
		"Name=flightID", "Value=292223054-8497-JB", ENDITEM, 
		"Name=flightID", "Value=292223054-9266-JB", ENDITEM, 
		"Name=flightID", "Value=292223054-10035-JB", ENDITEM, 
		"Name=flightID", "Value=292223054-107799-JB", ENDITEM, 
		"Name=flightID", "Value=292223054-11574-JJ", ENDITEM, 
		"Name=flightID", "Value=292223054-12343-JJ", ENDITEM, 
		"Name=flightID", "Value=292223054-13112-JB", ENDITEM, 
		"Name=flightID", "Value=292223054-13881-JB", ENDITEM, 
		"Name=flightID", "Value=292223054-14651-JB", ENDITEM, 
		"Name=removeAllFlights.x", "Value=33", ENDITEM, 
		"Name=removeAllFlights.y", "Value=5", ENDITEM, 
		"Name=.cgifields", "Value=11", ENDITEM, 
		"Name=.cgifields", "Value=7", ENDITEM, 
		"Name=.cgifields", "Value=17", ENDITEM, 
		"Name=.cgifields", "Value=2", ENDITEM, 
		"Name=.cgifields", "Value=1", ENDITEM, 
		"Name=.cgifields", "Value=18", ENDITEM, 
		"Name=.cgifields", "Value=16", ENDITEM, 
		"Name=.cgifields", "Value=13", ENDITEM, 
		"Name=.cgifields", "Value=6", ENDITEM, 
		"Name=.cgifields", "Value=3", ENDITEM, 
		"Name=.cgifields", "Value=9", ENDITEM, 
		"Name=.cgifields", "Value=12", ENDITEM, 
		"Name=.cgifields", "Value=14", ENDITEM, 
		"Name=.cgifields", "Value=15", ENDITEM, 
		"Name=.cgifields", "Value=8", ENDITEM, 
		"Name=.cgifields", "Value=4", ENDITEM, 
		"Name=.cgifields", "Value=19", ENDITEM, 
		"Name=.cgifields", "Value=10", ENDITEM, 
		"Name=.cgifields", "Value=5", ENDITEM, 
		LAST);

	lr_end_transaction("3.3_tr_Cancel_all_button",LR_AUTO);

	lr_start_transaction("3.4_tr_Home");

	web_revert_auto_header("Sec-Fetch-User");

	web_add_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(52);

	web_url("Home Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=menus", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("3.4_tr_Home",LR_AUTO);

	return 0;
}