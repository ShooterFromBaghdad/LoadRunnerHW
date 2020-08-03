Action()
{
	int flightCounter = 0;
	
	lr_start_transaction("tr_main_cancel_1_ticket");

	lr_start_transaction("tr_home_page");

	web_set_sockets_option("SSL_VERSION", "TLS");

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

	lr_save_string("jojo", "login");
	lr_save_string("bean", "password");

	web_reg_save_param("userSession",
		"LB/IC=name=\"userSession\" value=\"",
		"RB=\"/>",
		LAST);

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
		
	lr_end_transaction("tr_home_page", LR_AUTO);

	lr_start_transaction("tr_login");

	web_revert_auto_header("Sec-Fetch-User");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	lr_think_time(89);
	
	web_reg_find("Fail=NotFound",
		"Text/IC=User password was correct",
		LAST);

	web_submit_data("login.pl",
		"Action=http://localhost:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t2.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={login}", ENDITEM,
		"Name=password", "Value={password}", ENDITEM,
		"Name=login.x", "Value=0", ENDITEM,
		"Name=login.y", "Value=0", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		LAST);

	lr_end_transaction("tr_login",LR_AUTO);

	lr_start_transaction("tr_itinerary_button");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(35);
	
	web_reg_find("Fail=NotFound",
		"Text/IC=Flights List",
		LAST);
	
	// отлов первой части id
	web_reg_save_param_ex(
		"ParamName=FlightsID",
		"LB=name=\"flightID\" value=\"",
		"RB=-",
		"Ordinal=1",
		SEARCH_FILTERS,
		LAST);

	web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
			"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);
	
//	lr_output_message(lr_eval_string("{FlightsID_count}"));
//	
//	flightCounter = atoi(lr_eval_string("{FlightsID_count}"));

	lr_end_transaction("tr_itinerary_button",LR_AUTO);

	lr_start_transaction("tr_cancel_ticket");

	web_add_header("Origin", 
		"http://localhost:1080");

	lr_think_time(28);
	
	web_reg_find("Fail=Found",
	             lr_eval_string("Text/IC={FlightsID}"),
		LAST);

//	web_submit_data("itinerary.pl",
//		"Action=http://localhost:1080/cgi-bin/itinerary.pl",
//		"Method=POST",
//		"TargetFrame=",
//		"RecContentType=text/html",
//		"Referer=http://localhost:1080/cgi-bin/itinerary.pl",
//		"Snapshot=t4.inf",
//		"Mode=HTML",
//		ITEMDATA,
//		"Name=1", "Value=on", ENDITEM,
//		"Name=flightID", "Value={FlightsID}", ENDITEM,
//		"Name=removeFlights.x", "Value=76", ENDITEM,
//		"Name=removeFlights.y", "Value=7", ENDITEM,
//		"Name=.cgifields", "Value=1", ENDITEM,
//		LAST);

	
	web_submit_form("itinerary.pl", 
    "Snapshot=t100.inf", 
    ITEMDATA, 
    "Name=1", "Value=on", ENDITEM,  
    "Name=removeFlights.x", "Value=72", ENDITEM, 
    "Name=removeFlights.y", "Value=1", ENDITEM, 
    LAST);


	lr_end_transaction("tr_cancel_ticket",LR_AUTO);

	lr_start_transaction("tr_home_button");

	web_revert_auto_header("Sec-Fetch-User");

	web_add_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(28);
	
	web_reg_find("Fail=NotFound",
		"Text/IC=Welcome to Web Tours",
		LAST);

	web_url("Home Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=menus", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("tr_home_button",LR_AUTO);

	lr_end_transaction("tr_main_cancel_1_ticket", LR_AUTO);

	
	return 0;
}